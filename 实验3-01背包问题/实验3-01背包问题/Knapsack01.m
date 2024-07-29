clear all,clc

n=50;
Capacity=300;
Weight=[71,34,82,23,1,88,12,57,10,68,5,33,37,69,98,24,26,83,16,26,18,43,52,71,22,65,68,8,40,40,24,72,16,34,10,19,28,13,34,98,29,31,79,33,60,74,44,56,54,17];
Value=[26,59,30,19,66,85,94,8,3,44,5,1,41,82,76,1,12,81,73,32,74,54,62,41,19,10,65,53,56,53,70,66,58,22,72,33,96,88,68,45,44,61,78,78,6,66,11,59,83,48];
result=[0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,1,0,1,1,1,0,0,1,0,1,0,0,0,0,0,1];
m=zeros(n,Capacity+1);
x=zeros(n,Capacity+1);

tic
for i=0:Capacity
    if i>=Weight(n)
        m(n,i+1)=Value(n);
        x(n,i+1)=1;
    else
        m(n,i+1)=0;
        x(n,i+1)=0;
    end
end

for j=n-1:-1:1
    for i=0:Capacity
        if i<Weight(j)
            m(j,i+1)=m(j+1,i+1);
            x(j,i+1)=0;
        else
            a=Value(j)+m(j+1,i+1-Weight(j));
            b=m(j+1,i+1);
            if a>b
                m(j,i+1)=a;
                x(j,i+1)=1;
            else
                m(j,i+1)=b;
                x(j,i+1)=0;
            end
        end
    end
end

cc=Capacity;
y=zeros(1,n);
for i=1:n
    y(i)=x(i,cc+1);
    if x(i,cc)==1
        cc=cc-Weight(i);
    end
end
toc
m(1,Capacity+1)
y

tic
%DACknapsack(1,n,Capacity,Weight,Value)
toc