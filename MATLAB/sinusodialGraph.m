clc; clear; clf;
t = -1:1/100:1;
f = 1;
x = sin(2*pi*f*t);
plot(t, x);
title('Sine Wave');
xlabel('Time');
ylabel('Amplitude');