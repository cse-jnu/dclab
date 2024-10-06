b = [0 1 0 0 1 1 1 0];
n = length(b);
t = 0:.01:n;
for i = 1:n
 if (b(i) == 0)
   b_p(i) = 1;
 else
   b_p(i) = -1;
end
end
for j = 1:n
  bw(j*100:(j+1)*100) = b_p(j);
end
bw = bw(100:end);
subplot(1,1,1)
plot(t,bw)
grid on ; 
axis([0 n -2 +2])
