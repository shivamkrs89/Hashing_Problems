You are given a two-dimensional list of integers relations. Each element relations[i] contains [a, b] meaning that person a is following person b on Twitter.

Return the list of people who follow someone that follows them back, sorted in ascending order.

Constraints

    0 ≤ n ≤ 100,000 where n is the length of relations

Example 1
Input

relations = [
    [0, 1],
    [2, 3],
    [3, 4],
    [1, 0]
]

Output

[0, 1]

Explanation

0 follows 1 and 1 follows 0.
Example 2
Input

relations = [
    [0, 1],
    [1, 2],
    [2, 3],
    [3, 0]
]

Output

[]

Explanation

There aren't any mutual followers.

  vector<int> solve(vector<vector<int>>& relations) {
    int n = relations.size();
    vector<int> v1;
    int i, j, k;
  map<pair<int,int>,bool> mat; 
    bool vmat[n];
    memset(vmat, 0, sizeof(vmat));


    for (k = 0; k < n; k++) {
        i = relations[k][0];
        j = relations[k][1];

        mat[{i,j}] = 1;
    }
    for (k = 0; k < n; k++) {
        i = relations[k][0];
        j = relations[k][1];

        if (mat[{j,i}] && !vmat[i]) {
            v1.push_back(i);
            vmat[i] = 1;
        }
    }

    sort(v1.begin(), v1.end());
    return v1;
}
