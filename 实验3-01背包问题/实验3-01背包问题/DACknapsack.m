function s=DACknapsack(i,n,c,w,v)

if i<n
    if c<w(i)
        s=DACknapsack(i+1,n,c,w,v);
    else
        a=v(i)+DACknapsack(i+1,n,c-w(i),w,v);
        b=DACknapsack(i+1,n,c,w,v);
        if a>b
            s=a;
        else
            s=b;
        end
    end
else
    if c<w(i)
        s=0;
    else
        s=v(i);
    end
end