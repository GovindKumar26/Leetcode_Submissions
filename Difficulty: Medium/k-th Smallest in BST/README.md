<h2><a href="https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1">k-th Smallest in BST</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a BST and an integer <strong>k</strong>. Find the <strong>kth</strong> smallest element in the BST using O(1) extra space. If there is no kth smallest element present then return -1.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> root = [2, 1, 3] k = 2
&nbsp;     2
&nbsp;   /   \
&nbsp;  1     3
<strong>Output: </strong>2
<strong>Explanation:</strong> 2 is the 2nd smallest element in the BST</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> root = [2, 1, 3] k = 5<strong><br></strong>
        2
&nbsp;     /  \
&nbsp;    1    3

<strong>Output: </strong>-1
<strong>Explanation:</strong> There is no 5th smallest element in the BST as the size of BST is 3</span>
</pre>
<p>&nbsp;</p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> root = [5, 1, 3] k = 1
&nbsp;     5
&nbsp;   /   \
&nbsp;  1     3
<strong>Output: </strong>1
<strong>Explanation:</strong> 1 is the 2nd smallest element in the BST</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= number of nodes &lt;= 10<sup>5<br></sup>1 &lt;= node-&gt;data &lt;= 10<sup>5</sup><sup><br></sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Accolite</code>&nbsp;<code>Amazon</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Binary Search Tree</code>&nbsp;<code>Data Structures</code>&nbsp;