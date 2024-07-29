clear all,clc

Numb=1000*10^4;
Data=random('uniform',1,100,[1,Numb]);%����������ɵ������������������1~100�ľ��ȷֲ�ȡ��

tic;
range=zeros(2,1);%���õݹ���ã���Ÿ��εı߽磬������һ���ٴӱ�������ȡ����һ�δ���
range(1,1)=1;range(2,1)=Numb;
rangebottom=2;rangetop=1;%bottom�����һ���ֶ�Ҫ��ŵ�λ�ã�top��¼�´�Ҫ����ķֶ�λ�ã����������ʱ�����зֶδ������

while rangetop<rangebottom
    left=range(1,rangetop);right=range(2,rangetop);
    if left<right
        i=left+1;j=right;%�Ե�һ��Ԫ��Ϊ��׼�����飬����Ԫ��
        while Data(i)<Data(left)
            i=i+1;
            if i>Numb
                break;
            end
        end
        while Data(j)>Data(left)%����ʽ���ȺŻ���Լ����ȥ��i��j�ܵ��±귶Χ֮��
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
        
        range(1,rangebottom)=left;%�������ֶδ洢��range��
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

flag=0;%����������޴���
a=Data(1);
for i=2:Numb
    b=Data(i);
    if a>b
        flag=flag+1;
    end
    a=b;
end
flag