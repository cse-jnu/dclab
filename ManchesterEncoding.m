clear;
clc;

b = [0 1 0 0 1 0]; 
n = length(b); 
t = 0:.001:n;  

for i = 1:n
    if (b(i) == 0)
        b_p(i) = -1;
    else
        b_p(i) = 1;  
    end
end


for j = 1:n
    bw(j*1000:(j+1)*1000) = b_p(j);
end

bw = bw(1000:end);

subplot(2,1,1)
plot(t, bw)
grid on;
title('Binary Pulse Signal');

for i = 1:n
    if b(i) == 1
        x(i*1000:(i*1000+500)) = 1;   
        x((i*1000+501):(i+1)*1000) = -1;
    else
        x(i*1000:(i*1000+500)) = -1;   
        x((i*1000+501):(i+1)*1000) = 1;
    end
end

x = x(1000:end);


subplot(2,1,2)
plot(t, x)
grid on;
title('Manchester Encoded Signal');
