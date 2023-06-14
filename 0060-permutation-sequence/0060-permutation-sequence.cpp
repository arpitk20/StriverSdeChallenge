class Solution {
public:
    //Recursive Solution - O(n!*n) 
    
    
    
//     void permutationHelper(string& s, int index, vector<string>& res)
//     {
//         int n = s.size();
//         if(index==s.size())
//         {
//             res.push_back(s);
//             return;
//         }
        
//         for(int i=index;i<n;i++)
//         {
//             swap(s[index], s[i]);
//             permutationHelper(s, index+1, res);
//             swap(s[index], s[i]);
//         }
        
        
//     }
//     string getPermutation(int n, int k) {
        
//         string s;//for the initial string
//         vector<string>res;//for the storage of all the possibilities
//         for(int i=1;i<=n;i++)
//         {
//             s.push_back(i+'0');
//         }
        
//         permutationHelper(s, 0, res);//the string, index, res vector
//         sort(res.begin(), res.end());
        
//         auto it = res.begin() + (k-1);
        
//         return *it;    
//     }
    string getPermutation(int n, int k) {
        
//         int fact = 1;
//         vector<int> numbers;

//         for(int i=1;i<=n;i++)
//         {
//             fact = fact*i;
//             numbers.push_back(i);
//         }
        
//         string ans = "";
//         k = k-1;//0 based inexing
        
//         while(true)
//         {
//             ans = ans + to_string(numbers[k/fact]);//tells us of the block
//             numbers.erase(numbers.begin() + k/fact);//removing the included number
//             if(numbers.empty())
//                 break;
            
//             k = k%fact;//sequence number
            
//             fact = fact/numbers.size();
//         }
        
//         return ans;
        int fact = 1;
      vector < int > numbers;
      for (int i = 1; i < n; i++) {
        fact = fact * i;
        numbers.push_back(i);
      }
      numbers.push_back(n);
      string ans = "";
      k = k - 1;
      while (true) {
        ans = ans + to_string(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0) {
          break;
        }

        k = k % fact;
        fact = fact / numbers.size();
      }
      return ans;
    }
};