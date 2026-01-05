int is_palindrome(char str[],int left,int right){
    if(left>=right) return 1;
    if(str[left]!=str[right]) return 0;
    return is_plindrome(str,left+1,right-1);
}
