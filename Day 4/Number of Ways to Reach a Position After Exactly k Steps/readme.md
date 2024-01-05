# Just a simple DP problem
The only catch is that pos can be negative
-999 <= pos <= 2000  
How to handle it in DP?  
=> Simple. Just take the maximum state size of position as 3001  
   Now if pos = -999, just put it in **dp[-999 + 1000][k]**  
   On the other hand if pos = 2000, put it in **dp[2000 + 1000]**  
   So basically whatever the position is, add 1000 to it and then store it in dp  

dp[3001][k]  
put everything in dp[pos + 1000][k]
