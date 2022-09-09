clc; clear; clf;
t = 0:0.01:1;
f = 10;
% sin wave
x1 = sin(2*pi*f*t);
% cos wave
x2 = cos(2*pi*f*t);
subplot(2, 2, 1);
plot(t, x1);
title('Sine Wave');
subplot(2, 2, 2);
plot(t, x2);
title('Cosine Wave');
subplot(2, 2, [3, 4]);
plot(t, x1, t, x2);
title('Both Sine and Cosine Wave');