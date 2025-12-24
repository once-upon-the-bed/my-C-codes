bool isPalindrome(int x){
    int digit=1;
    int temp=x;
    while(temp>=10){
        temp/=10;
        digit*=10;
    }
    if(x<0){
        return false;
    }else{
        int left,right;
        while(x>0){
            right=x%10;
            left=x/digit;
            if(left!=right){
                return false;
            }
            x=(x%digit)/10;
            digit/=100;
        }
        return true;
    }
}

bool isPalindrome(int x) {
    if (x < 0) return false;
    char s[20];
    sprintf(s, "%d", x);
    int l = 0, r = strlen(s) - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

bool isPalindrome(int x) {
    if (x < 0) return false;
    int original = x, reversed = 0;
    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return original == reversed;
}

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;
    int reversed = 0;
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return x == reversed || x == reversed / 10;
}
