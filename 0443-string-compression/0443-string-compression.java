class Solution {
    public int compress(char[] chars) {
        StringBuilder sb = new StringBuilder();
        int i=0;
        int n = chars.length;
        while(i<n){
            char ch=chars[i];
            int count = 0;
            while(i<n && ch ==chars[i]){
                count++;
                i++;
            }
            sb.append(ch);
            if(count>1){
                sb.append(count);
            }
        }
        for(int k =0;k<sb.length();k++){
            chars[k]=sb.charAt(k);
        }
        return sb.length();
    }
}