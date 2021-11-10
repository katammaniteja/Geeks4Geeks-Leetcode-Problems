// Lomuto
int lomuto(int arr[],int l,int r){
    int piv=arr[r];
    int i=l-1;
    for(int j=l;j<=r-l;j++){
        if(arr[j]<piv){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
void qSort(int arr[],int l,int r){
    if(l<r){
        int p=lomuto(arr,l,r);
        qSort(arr,l,p-1);
        qSort(arr,p+1,r);
    }
}

//Hoare
int hoare(int arr[],int l,int r){
    int piv=arr[l];
    int i=l-1,j=r+1;
    while(true){
        do{
            i++;
        }while(arr[i]<piv);
        do{
            j--;
        }while(arr[j]>piv);
        if(j<=i) return j;
        swap(arr[i],arr[j]);
    }
}
void qSort(int arr[],int l,int r){
    if(l<r){
        int p=hoare(arr,l,r);
        qSort(arr,l,p);
        qSort(arr,p+1,r);
    }
}