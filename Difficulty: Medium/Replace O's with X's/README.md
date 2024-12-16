<h2><a href="https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1">Replace O's with X's</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a matrix <strong>mat</strong>&nbsp;where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'. </span></p>
<p><span style="font-size: 18px;">A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.</span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> mat = [['X', 'X', 'X', 'X'], ['X', 'O', 'X', 'X'], ['X', 'O', 'O', 'X'], ['X', 'O', 'X', 'X'], ['X', 'X', 'O', 'O']]
<strong>Output:</strong> [['X', 'X', 'X', 'X'], ['X', 'X', 'X', 'X'], ['X', 'X', 'X', 'X'], ['X', 'X', 'X', 'X'], ['X', 'X', 'O', 'O']]
<strong>Explanation:</strong> Following the rule the above matrix is the resultant matrix. </span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> mat = [['X', 'O', 'X', 'X'], ['X', 'O', 'X', 'X'], ['X', 'O', 'O', 'X'], ['X', 'O', 'X', 'X'], ['X', 'X', 'O', 'O']]
<strong>Output:</strong> [['X', 'O', 'X', 'X'], ['X', 'O', 'X', 'X'], ['X', 'O', 'O', 'X'], ['X', 'O', 'X', 'X'], ['X', 'X', 'O', 'O']]
<strong>Explanation:</strong> Following the rule the above matrix is the resultant matrix.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> mat = [['X', 'X', 'X'], ['X', 'O', 'X'], ['X', 'X', 'X']]
<strong>Output:</strong> [['X', 'X', 'X'], ['X', 'X', 'X'], ['X', 'X', 'X']]
<strong>Explanation:</strong> Following the rule the above matrix is the resultant matrix.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ mat.size() ≤ 100<br>1 ≤ mat[0].size() ≤ 100<br></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Recursion</code>&nbsp;<code>Matrix</code>&nbsp;<code>Graph</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;