clc; clear; clf;
t = 0:0.01:1;
f = 1;
% sin wave
x1 = sin(2*pi*f*t);
% cos wave
x2 = cos(2*pi*f*t);

plot(t, x1, t, x2);
title('Two signals in one graph')