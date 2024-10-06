b = [0 1 0 1 1 1 0];
n = length(b);
t = 0:.01:n;
for i = 1:n
 if (b(i) == 0)
   b_p(i) = -1;
 else
   b_p(i) = 1;
end
end
for j = 1:n
  bw(j*100:(j+1)*100) = b_p(j);
end
bw = bw(100:end);
sint = sin(2*pi*t);
st = bw.*sint;
subplot(3,1,1)
plot(t,bw)
grid on ; 
axis([0 n -2 +2])
subplot(3,1,2)
plot(t,sint)
grid on ; 
axis([0 n -2 +2])
subplot(3,1,3)
plot(t,st)
grid on ; axis([0 n -2 +2])
