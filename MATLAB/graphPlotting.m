clc; clear; clf;
x = 1:10;
y = x;
xlabel('x');
ylabel('y');
title('Graph between x and y');
y2 = x.*x;
xlabel('x');
ylabel('x^2');
title('Graph between x and x^2');
subplot(1, 2, 1);
plot(x, y);
subplot(1, 2, 2);
plot(x, y2);