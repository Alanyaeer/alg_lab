clear all,clc

Numb=1000*10^4;
Data=random('uniform',1,100,[1,Numb]);%保存随机生成的数用来排序，随机数从1~100的均匀分布取出

tic;
range=zeros(2,1);%不用递归调用，存放各段的边界，处理完一段再从本数组中取出下一段处理
range(1,1)=1;range(2,1)=Numb;
rangebottom=2;rangetop=1;%bottom存放下一个分段要存放的位置，top记录下次要处理的分段位置，当两者相等时，所有分段处理完毕

while rangetop<rangebottom
    left=range(1,rangetop);right=range(2,rangetop);
    if left<right
        i=left+1;j=right;%以第一个元素为基准，分组，调换元素
        while Data(i)<Data(left)
            i=i+1;
            if i>Numb
                break;
            end
        end
        while Data(j)>Data(left)%不等式带等号会把自己错过去，i、j跑到下标范围之外
            j=j-1;
            if j<1
                break;
            end
        end
        while i<=j
            a=Data(i);
            Data(i)=Data(j);
            Data(j)=a;
            i=i+1;
            j=j-1;
            while Data(i)<Data(left)
                i=i+1;
                if i>Numb
                    break;
                end
            end
            while Data(j)>Data(left)
                j=j-1;
                if j<1
                    break;
                end
            end
        end
        a=Data(j);
        Data(j)=Data(left);
        Data(left)=a;
        middle=j;
        
        range(1,rangebottom)=left;%将两个分段存储到range里
        range(2,rangebottom)=middle-1;
        rangebottom=rangebottom+1;
        range(1,rangebottom)=middle+1;
        range(2,rangebottom)=right;
        rangebottom=rangebottom+1;
        rangetop=rangetop+1;
    else
        rangetop=rangetop+1;
    end
    
end
toc;

flag=0;%检查排序有无错误
a=Data(1);
for i=2:Numb
    b=Data(i);
    if a>b
        flag=flag+1;
    end
    a=b;
end
flag