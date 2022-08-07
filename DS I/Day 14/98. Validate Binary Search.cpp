public class Solution {
    public boolean isValidBST(TreeNode root) {
        return check(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    public boolean check(TreeNode node, long MIN, long MAX) {
        if (node == null) {
            return true;
        }
        if (node.val > MIN && node.val < MAX &&
            check(node.left, MIN, node.val) &&
            check(node.right, node.val, MAX)) {
            return true;
        } else {
            return false;
        }
    }
}