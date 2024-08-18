class Solution {
public:
    string largestPalindrome(int n, int k) {
        string ans = "";
        if(k == 1 || k == 3 || k == 9){
            for(int i = 0; i < n; i++) ans += '9';
        }else if(k == 2){
            ans += '8';
            for(int i = 1; i < n - 1; i++) ans += '9';
            if(n > 1) ans += '8';
        }else if(k == 5){
            ans += '5';
            for(int i = 1; i < n - 1; i++) ans += '9';
            if(n > 1) ans += '5';
        }else if(k == 4){
            if(n == 1) ans = "8";
            else if(n == 2){
                ans = "88";
            }else if(n == 3){
                ans = "888";
            }else if(n >= 4){
                ans = "88";
                for(int i = 2; i < n - 2; i++){
                    ans += '9';
                }
                ans += "88";
            }
        }else if(k == 8){
            if(n == 1) ans = "8";
            else if(n == 2) ans = "88";
            else if(n == 3) ans = "888";
            else if(n == 4) ans = "8888";
            else if(n == 5) ans = "88888";
            else{
                ans += "888";
                for(int i = 3; i < n - 3; i++){
                    ans += '9';
                }
                ans += "888";
            }
        }else if(k == 6){
            if(n == 1) ans = "6";
            else if(n == 2) ans = "66";
            else{
                int val = 16;
                ans += '8';
                for(int i = 1; i < n - 1; i++){
                    ans += '9';
                }
                ans += '8';
                if(n % 2) ans[n / 2] = '8';
                else{
                    ans[n / 2] = '7';
                    ans[n / 2 - 1] = '7';
                }
            }
        }else{
            if(n == 1) ans = "7";
            else if(n == 2) ans = "77";
            else{
                for(int i = 0; i < n; i++) ans += '9';
                if(n % 2){
                    for(int i = 9; i >= 0; i--){
                        ans[n / 2] = i + '0';
                        int rem = 0;
                        for(int j = 0; j < n; j++){
                            rem = (rem * 10 +  (ans[j] - '0')) % 7;
                        }
                        if(rem == 0){
                            break;
                        }
                    }
                }else{
                    for(int i = 9; i >= 0; i--){
                        ans[n / 2] = i + '0';
                        ans[n / 2 - 1] = i + '0';
                        int rem = 0;
                        for(int j = 0; j < n; j++){
                            rem = (rem * 10 +  (ans[j] - '0')) % 7;
                        }
                        if(rem == 0){
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};