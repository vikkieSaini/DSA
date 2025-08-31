//Approach 
//find out left and right max value , than check by adding root value if it is maximum
//If it is more than max than update res. else return max of(left max +root->val, right right + root->val)

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        int value = maxValue(root, res);
        return max(res, value);
    }

    int maxValue(TreeNode* root, int &res){
        if(root == NULL)
            return 0;
        int leftValue = maxValue(root->left, res);
        int rightValue = maxValue(root->right, res);
        res = max(res,max(root->val+leftValue+rightValue,max(root->val,root->val + max(leftValue, rightValue))));
        return max(root->val,root->val+max(leftValue,rightValue));
    }
};