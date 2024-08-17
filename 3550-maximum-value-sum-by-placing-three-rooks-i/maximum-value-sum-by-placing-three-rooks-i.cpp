class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        vector<vector<pair<long long,int>>>rl;
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++){
            int maxi1 = INT_MIN, maxi2 = INT_MIN, maxi3 = INT_MIN;
            int ind1, ind2, ind3;
            for(int j = 0; j < m; j++){
                if(board[i][j] > maxi1){
                    maxi3 = maxi2;
                    maxi2 = maxi1;
                    maxi1 = board[i][j];
                    ind3 = ind2;
                    ind2 = ind1;
                    ind1 = j;
                }else if(board[i][j] > maxi2){
                    maxi3 = maxi2;
                    maxi2 = board[i][j];
                    ind3 = ind2;
                    ind2 = j;
                }else if(board[i][j] > maxi3){
                    maxi3 = board[i][j];
                    ind3 = j;                    
                }
            }
            rl.push_back({make_pair(maxi1, ind1), make_pair(maxi2, ind2), make_pair(maxi3, ind3)});
            
        }
        long long ans = LLONG_MIN;
        // cout << rl.size() << endl;
        for(int k1 = 0; k1 < 3; k1++){
            for(int i = 0; i < rl.size() - 2; i++){
                for(int k2 = 0; k2 < 3; k2++){
                    for(int j = i + 1; j < rl.size() - 1; j++){
                        for(int k3 = 0; k3 < 3; k3++){
                            for(int k = j + 1; k < rl.size(); k++){
                                if(rl[i][k1].second != rl[j][k2].second && rl[i][k1].second != rl[k][k3].second && rl[k][k3].second != rl[j][k2].second){
                                    ans = max(ans, rl[i][k1].first + rl[j][k2].first + rl[k][k3].first);
                                }
                            }
                        }
                    }
                 }
            }
        }
        return ans;  
    }
};