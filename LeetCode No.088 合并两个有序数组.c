void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i=m-1;
    int j=n-1;
    int k=m+n-1;
    while(i>=0&&j>=0){
        if(nums1[i]>=nums2[j]){
            nums1[k--]=nums1[i--];
        }else{
            nums1[k--]=nums2[j--];
        }
    }
    while(j>=0){
        nums1[k--]=nums2[j--];
    }
}//从后往前合并

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int *temp=(int*)malloc((m+n)*sizeof(int));
    int i=0,j=0,k=0;
    while(i<m&&j<n){
        if(nums1[i]<=nums2[j]){
            temp[k++]=nums1[i++];
        }else{
            temp[k++]=nums2[j++];
        }
    }
    while(i<m){
        temp[k++]=nums1[i++];
    }
    while(j<n){
        temp[k++]=nums2[j++];
    }
    for(int l=0;l<m+n;l++){
        nums1[l]=temp[l];
    }
    free(temp);
}
