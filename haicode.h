//simple library by haicode
//https://github.com/khanghaicode/simplelib
template<typename datatype>
void haicode_swap(datatype&a,datatype&b){
    datatype c;
    c=a;
    a=b;
    b=c;
}
template<typename datatype>
void haicode_sort(datatype *left,datatype *right){
    right--;
    if(left<right){
        datatype *i=left-1;
        for(datatype *j=left;j<right;j++){
            if((*j)<=(*right)){
                i++;
                my_swap((*j),(*i));
            }
        }
        i++;
        my_swap((*i),(*right));
        my_sort(left,i-1);
        my_sort(i+1,right);
    }
}
template<typename datatype,typename compare>
void haicode_sort(datatype *left,datatype *right,compare __comp){
    right--;
    if(left<right){
        datatype *i=left-1;
        for(datatype *j=left;j<right;j++){
            if(__comp((*j),(*right))){
                i++;
                my_swap((*j),(*i));
            }
        }
        i++;
        my_swap((*i),(*right));
        my_sort(left,i-1,__comp);
        my_sort(i+1,right,__comp);
    }
}