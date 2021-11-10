
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int Lomuto(int arr[],int l,int r){
        int pivot=arr[r];
        int i=l-1;
        for(int j=l;j<=r-1;j++){
            if(arr[j]<pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[r]);
        return i+1;
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        while(l<=r){
            int p=Lomuto(arr,l,r);
            if(p== (k-1)) return arr[p];
            else if(p>k-1) r=p-1;
            else l=p+1;
        }
    }
};