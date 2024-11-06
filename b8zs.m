clear;
clc;
b = [0 1 1 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 1 0 1];

%prompt='Enter an array in the format-[a b c ... ] \n';
%b= input(prompt);% input function


%b= input('Enter an array in the format-[a b c ... ] \n');% input function

%display(b);

n = length(b);
t = 0:.001:n;
for i = 1:n
 if (b(i) == 0)
   b_p(i) = 0;
 else
   b_p(i) = 1;
end
end
for j = 1:n
  bw(j*1000:(j+1)*1000) = b_p(j);
end
bw = bw(1000:end);
subplot(3,1,1)
plot(t,bw)
grid on; 
axis([0 n -2 +2])

lastbit_1 = -1;
for i=1:n
  if b(i)==1
    x(i*1000:(i+1)*1000) = -lastbit_1;
    lastbit_1 = -lastbit_1;
  else x(i*1000:(i+1)*1000) = 0;
  end
end
x = x(1000:end);
subplot(3,1,2)
plot(t,x)
grid on;
axis([0 n -2 +2])

lastbit_2 = -1;
zros=0;
for j=1:n
  if b(j)==1
      y(j*1000:(j+1)*1000) = -lastbit_2;
      lastbit_2 = -lastbit_2;
      zros=0;
  else
      zros=zros+1;
      y(j*1000:(j+1)*1000) = 0;
      if zros==8
          y((j-7)*1000:(j-4)*1000) = 0;
          y((j-4)*1000:(j-3)*1000) = lastbit_2;
          y((j-3)*1000:(j-2)*1000) = -lastbit_2;
          y((j-2)*1000:(j-1)*1000) = 0;
          y((j-1)*1000:(j)*1000) = -lastbit_2;
          y((j)*1000:(j+1)*1000) = lastbit_2;
          zros=0;
      end
          
  end
end
y = y(1000:end);
subplot(3,1,3)
plot(t,y)
grid on;
axis([0 n -2 +2])
