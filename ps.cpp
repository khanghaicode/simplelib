struct ps{
    long long tu=0,mau=1;
    ps(){};
    ps(long long val){tu=val;mau=1;}
    void rut(){
        long long tmp=__gcd(tu,mau);
        tu/=tmp;
        mau/=tmp;
        if(mau<0){
            mau=-mau;
            tu=-tu;
        }
    }
    ps(long long t,long long m){
        tu=t;
        mau=m;
        rut();
    }
    bool operator<(ps a){return tu*a.mau<mau*a.tu;}
    bool operator>(ps a){return a<*this;}
    bool operator==(ps a){return tu==a.tu&&mau==a.mau;}
    bool operator<=(ps a){return !(*this>a);}
    bool operator>=(ps a){return !(*this<a);}
    ps operator-(){return ps(-tu,mau);};
    ps operator-(ps a){return ps(tu*a.mau-mau*a.tu,a.mau*mau);}
    ps operator+(ps a){return ps(tu*a.mau+mau*a.tu,a.mau*mau);}
    ps operator*(ps a){return ps(tu*a.tu,mau*a.mau);}
    ps operator/(ps a){return ps(tu*a.mau,mau*a.tu);}
};
void operator<<(ostream&os,ps a){os<<a.tu<<"/"<<a.mau;}
