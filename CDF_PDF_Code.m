clear all;
clc;
pkg load statistics;
DATA_exp = load("-ascii", "../exponential.txt");
x_exp = DATA_exp(1002):1.2:DATA_exp(1003);
figure
[y_exp,x_exp_] = hist(DATA_exp(1:1001),x_exp);
bar(x_exp,(y_exp./1000)); 



y_exp_int = @(x) ((y_exp(x)./1000) .* x_exp_(x))
for i = 1:1:length(y_exp)
  y_cdf_exp(i) = sum(y_exp_int([1:i]));
end
hold on
plot(x_exp_,(y_cdf_exp./y_cdf_exp(length(y_exp))));




ylabel("Normalized Frequency");
xlabel("Midpoint");
legend("PDF","CDF");
hold off

DATA_u1 = load("-ascii", "../uniform1.txt");
x_u1 = DATA_u1(1002):0.1:DATA_u1(1003);
figure
[y_u1,x_u1_] = hist(DATA_u1(1:1001),x_u1);
bar(x_u1,(y_u1./1000)); 
y_u1_int = @(x) (y_u1(x) .* x_u1_(x))
for i = 1:1:length(y_u1)
  y_cdf_u1(i) = sum(y_u1_int([1:i]));
end
hold on
plot(x_u1_,y_cdf_u1./y_cdf_u1(length(y_u1)));
ylabel("Normalized Frequency");
xlabel("Midpoint");
legend("PDF","CDF");
hold off

DATA_u2 = load("-ascii", "../uniform2.txt");
x_u2 = DATA_u2(1002):0.6:DATA_u2(1003);
figure
[y_u2,x_u2_] = hist(DATA_u2(1:1001),x_u2);
bar(x_u2,(y_u2./1000)); 
hold on
y_u2_int = @(x) (y_u2(x) .* x_u2_(x))
for i = 1:1:length(y_u2)
  y_cdf_u2(i) = sum(y_u2_int([1:i]));
end
plot(x_u2_,y_cdf_u2./y_cdf_u2(length(y_u2)));
ylabel("Normalized Frequency");
xlabel("Midpoint");
legend("PDF","CDF");
hold off

DATA_p = load("-ascii", "../pareto_f.txt");
x_p = DATA_p(1002):1.2:DATA_p(1003);
[y_p,x_p_] = hist(DATA_p(1:1001),x_p);
figure
bar(x_p_,(y_p./1000)); 
hold on
y_p_int = @(x) (y_p(x) .* x_p_(x))
for i = 1:1:length(y_p)
  y_cdf_p(i) = sum(y_p_int([1:i]));
end
plot(x_p_,y_cdf_p./y_cdf_p(length(y_p)));
ylabel("Normalized Frequency");
xlabel("Midpoint");
legend("PDF","CDF");
hold off
