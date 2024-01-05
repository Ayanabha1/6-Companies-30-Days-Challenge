string encode(string s)
{     
  //Your code here 
  string ans = "";
  for(int i = 0 ; i < s.size() ; i++)
  {
      int j = i;
      while(j < s.size() && s[i] == s[j])
      {
          j++;
      }
      int cnt = j - i;
      ans += s[i];
      ans += (cnt + '0');
      i = j - 1;
  }
  return ans;
}     
