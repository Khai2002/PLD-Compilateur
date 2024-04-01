int main()
{
    int x;
    x = 3;
    if(x==3){
        x = 4;
        if(x==3){
            x = 4;
        }
        else{
            x = 5;
        }
    }
    
    return x;
}