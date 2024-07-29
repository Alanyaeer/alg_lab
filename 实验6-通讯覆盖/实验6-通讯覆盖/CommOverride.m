clear all,clc

n=9;
d=4;
islandx=zeros(1,n);
islandy=zeros(1,n);
for i=1:n%随机生成岛屿坐标
    islandx(i)=random('unif',-n,n);
    islandy(i)=random('unif',0.1,d);
end

tempX=zeros(5,n);%第一行为岛屿横坐标，第二行纵坐标，第三行为基站右限，第四行覆盖它的基站编号，第五行记录岛屿到基站的距离
tempX(1,:)=islandx;
tempX(2,:)=islandy;
for i=1:n
    tempX(3,i)=tempX(1,i)+sqrt(d^2-(tempX(2,i))^2);
end
tempX(3,:)
for i=1:n-1%ChoiseSort
    temp=tempX(3,i);
    a=i;
    for j=i+1:n
        if tempX(3,j)<temp
            temp=tempX(3,j);
            a=j;
        end
    end
    tempX(3,a)=tempX(3,i);tempX(3,i)=temp;
    temp=tempX(1,a);tempX(1,a)=tempX(1,i);tempX(1,i)=temp;
    temp=tempX(2,a);tempX(2,a)=tempX(2,i);tempX(2,i)=temp;
end
tempX(3,:)

k=0;%基站计数
base=zeros(1,n);
for i=1:n
   if tempX(4,i)==0
       k=k+1;
       base(k)=tempX(3,i);
       tempX(4,i)=k;
       for j=i+1:n
           if tempX(4,j)==0
               if (base(k)-tempX(1,j))^2+(tempX(2,j))^2<=d^2
                   tempX(4,j)=k;
               end
           end
       end
   end
end

k
base

%Check
for i=1:n
    x=tempX(1,i)-base(tempX(4,i));
    y=tempX(2,i);
    dist=sqrt(x^2+y^2);
    tempX(5,i)=dist;
    if dist>d
        disp('Error')
        break
    end
end

%chart
scatter(islandx,islandy);
hold on;
scatter(base(1:k),zeros(1,k));
for i=1:k
    theta=0:2*pi/1000:pi;
    x=base(i)+d*cos(theta);
    y=d*sin(theta);
    plot(x,y);
end
for i=1:n
    line([tempX(1,i),base(tempX(4,i))],[tempX(2,i),0]);
end