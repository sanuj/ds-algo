#include <iostream>
#include <vector>
using namespace std;

int tabulation_len_lcs(char *seq_a, char *seq_b, int len_a, int len_b) {
  vector<vector<int> > lcs_matrix(len_a+1, vector<int>(len_b+1, 0));
  for(int i=0; i<=len_a; i++)
  {
    for(int j=0; j<=len_b; j++)
    {
      if(i==0 || j==0)
        lcs_matrix[i][j] = 0;
      else if(seq_a[i-1] == seq_b[j-1])
        lcs_matrix[i][j] = 1+lcs_matrix[i-1][j-1];
      else
        lcs_matrix[i][j] = max(lcs_matrix[i-1][j], lcs_matrix[i][j-1]);
    }
  }
  return lcs_matrix[len_a][len_b];
}

int memoiz_len_lcs_helper(char *seq_a, char *seq_b, int len_a, int len_b, vector<vector<int> > &lcs_matrix) {
  if(len_a == 0 || len_b == 0)
  {
    return 0;
  }
  if(lcs_matrix[len_a-1][len_b-1] >= 0)
  {
    return lcs_matrix[len_a-1][len_b-1];
  }
  else if (seq_a[len_a-1] == seq_b[len_b-1])
  {
    lcs_matrix[len_a-1][len_b-1] = 1 + memoiz_len_lcs_helper(seq_a, seq_b, len_a-1, len_b-1, lcs_matrix);
    return lcs_matrix[len_a-1][len_b-1];
  }
  else
  {
    lcs_matrix[len_a-1][len_b-1] = max(memoiz_len_lcs_helper(seq_a, seq_b, len_a-1, len_b, lcs_matrix),
    memoiz_len_lcs_helper(seq_a, seq_b, len_a, len_b-1, lcs_matrix));
    return lcs_matrix[len_a-1][len_b-1];
    }
}

int memoiz_len_lcs(char *seq_a, char *seq_b, int len_a, int len_b) {
  vector<vector<int> > lcs_matrix( len_a, vector<int>(len_b, -1));
  // for(int i=0; i<len_a; i++) {
  //   for(int j=0; j<len_b; j++) {
  //     cout << lcs_matrix[i][j] << ", ";
  //   }
  //   cout << endl;
  // }
  // return 0;
  return memoiz_len_lcs_helper(seq_a, seq_b, len_a, len_b, lcs_matrix);
}

int naive_len_lcs(char *seq_a, char *seq_b, int len_a, int len_b) {
  if(len_a == 0 || len_b == 0)
    return 0;
  else if (seq_a[len_a-1] == seq_b[len_b-1])
    return 1 + naive_len_lcs(seq_a, seq_b, len_a-1, len_b-1);
  else
    return max(naive_len_lcs(seq_a, seq_b, len_a-1, len_b), naive_len_lcs(seq_a, seq_b, len_a, len_b-1));
}

int main() {
  int test_cases;
  cin >> test_cases;
  while(test_cases--) {
    int len_a, len_b;
    cin >> len_a >> len_b;
    char seq_a[len_a], seq_b[len_b];

    for(int i=0; i<len_a; i++)
      cin >> seq_a[i];
    for(int i=0; i<len_b; i++)
      cin >> seq_b[i];

    // cout << memoiz_len_lcs(seq_a, seq_b, len_a, len_b) << endl;
    // cout << naive_len_lcs(seq_a, seq_b, len_a, len_b) << endl;
    cout << tabulation_len_lcs(seq_a, seq_b, len_a, len_b) << endl;
  }
  return 0;
}
