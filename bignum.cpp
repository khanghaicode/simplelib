#define bignum string
int sosanh(bignum x,bignum y){
    while(x.size()<y.size())x="0"+x;
    while(x.size()>y.size())y="0"+y;
    if(x==y)return 0;
    else if(x>y)return 1;
    else return -1;
}
bignum cong(bignum x,bignum y){
    bignum kq="";
    int tg,nho=0;
    while(x.size()<y.size())x="0"+x;
    while(x.size()>y.size())y="0"+y;
    for(int i=x.size()-1;i>=0;i--){
        tg=x[i]+y[i]+nho-96;
        kq=char(tg%10+48)+kq;
        nho=tg/10;
    }
    if(nho)kq=char(nho+48)+kq;
    return kq;
}
bignum tru(bignum x,bignum y){
    bignum kq="";
    int tg,muon=0;
    while(x.size()<y.size())x="0"+x;
    while(x.size()>y.size())y="0"+y;
    for(int i=x.size()-1;i>=0;i--){
        if(x[i]-muon>=y[i]){
            tg=x[i]-y[i]-muon;
            muon=0;
        }
        else{
            tg=x[i]-y[i]-muon+10;
            muon=1;
        }
        kq=char(tg+48)+kq;
    }
    while(kq[0]=='0'&&kq.size()>1)kq.erase(0,1);
    return kq;
}
bignum nhan1(bignum x,int y){
    int nho=0,tg;
    bignum kq="";
    for(int i=x.size()-1;i>=0;i--){
        tg=(x[i]-48)*y+nho;
        nho=tg/10;
        kq=char(tg%10+48)+kq;
    }
    if(nho)kq=char(nho+48)+kq;
    return kq;
}
bignum nhan(bignum x,bignum y){
    bignum kq="",tg,duoi="";
    for(int i=y.size()-1;i>=0;i--){
        tg=nhan1(x,y[i]-48)+duoi;
        kq=cong(kq,tg);
        duoi.push_back('0');
    }
    return kq;
}
bignum chia1(bignum x,long long y){
    bignum kq="";
    long long tg,tmp=0;
    for(int i=0;i<x.size();i++){
        tmp=tmp*10+x[i]-48;
        tg=tmp/y;
        tmp%=y;
        kq+=char(tg+48);
    }
    while(kq[0]=='0'&&kq.size()>1)kq.erase(0,1);
    return kq;
}
long long chiadu1(bignum x,long long y){
    long long kq=0;
    for(int i=0;i<x.size();i++)kq=((x[i]-48)+kq*10)%y;
    return kq;
}
bignum chia(bignum x,bignum y){
    bignum kq="",tmp="";
    bignum nhany[10];
    nhany[0]="0";
    int k;
    for(int i=1;i<10;i++)nhany[i]=cong(nhany[i-1],y);
    for(int i=0;i<x.size();i++){
        tmp+=x[i];
        k=1;
        while(sosanh(tmp,nhany[k])!=-1)k++;
        kq+=(char(k-1+48));
        tmp=tru(tmp,nhany[k-1]);
    }
    while(kq[0]=='0'&&kq.size()>1)kq.erase(0,1);
    return kq;
}
bignum chiadu(bignum x,bignum y){
    bignum kq="";
    bignum nhany[10];
    nhany[0]="0";
    int k;
    for(int i=1;i<10;i++)nhany[i]=cong(nhany[i-1],y);
    for(int i=0;i<x.size();i++){
        kq+=x[i];
        k=1;
        while(sosanh(kq,nhany[k])!=-1)k++;
        kq=tru(kq,nhany[k-1]);
    }
    return kq;
}
