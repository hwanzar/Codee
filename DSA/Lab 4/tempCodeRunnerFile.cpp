int arr[] = {-1, 0, 0, 2, 2, 3, 3, 5};
    int value[] = {1, 5, 4, 7, 12, 4, 8, 2};
    BTNode *root = BTNode::createTree(arr, sizeof(arr) / sizeof(int), value);
    cout << longestPathSum(root);