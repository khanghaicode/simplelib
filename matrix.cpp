struct matrix{
    int w,h;
    long long **ar;
    matrix(){
        w=0;
    }
    matrix(int hang,int cot){
        this->w=hang;
        this->h=cot;
        this->ar=new long long*[w+1];
        for(int i=1;i<=w;i++)ar[i]=new long long[h+1];
    }
    void chet(){
        for(int i=1;i<=this->w;i++)delete this->ar[i];
        delete this->ar;
    }
    long long *operator[](int fuck){
        return ar[fuck];
    }
    matrix opp_nhu_lon(){
        matrix res(this->w,this->h);
        for(int i=1;i<=this->w;i++){
            for(int j=1;j<=this->h;j++){
                res[i][j]=this->ar[i][j];
            }
        }
        return res;
    }
    void operator =(matrix x){
        this->chet();
        w=x.w;
        h=x.h;
        ar=x.ar;
    }
    matrix operator *(matrix x){
        matrix ans(this->w,x.h);
        for(int i=1;i<=this->w;i++){
            for(int j=1;j<=x.h;j++){
                ans[i][j]=0;
                for(int k=1;k<=this->h;k++){
                    ans[i][j]+=this->ar[i][k]*x[k][j];

                }

            }
        }
        return ans;
    }
    matrix operator^(long long x){
        if(!x){       
            int lon=this->w;
            matrix ans(lon,lon);
            for(int i=1;i<=lon;i++){
                for(int j=1;j<=lon;j++)ans[i][j]=0;
                ans[i][i]=1;
            }
            return ans;
        }
        matrix tmp=(*this)^(x/2);
        matrix tmpp=tmp*tmp;
        if(x%2){  
            tmp=this->opp_nhu_lon();
            tmp=tmp*tmpp;
            tmpp.chet();
            return tmp;
        }
        else{
            tmp.chet();
            return tmpp;
        }
    }
};
matrix huyen_Anh(int lon){
    matrix ans(lon,lon);
    for(int i=1;i<=lon;i++){
        for(int j=1;j<=lon;j++)ans[i][j]=0;
        ans[i][i]=1;
    }
    return ans;
}
