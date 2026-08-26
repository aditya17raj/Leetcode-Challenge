class Solution {
    public String reverseWords(String s) {
        Stack<String> st = new Stack<>();
        String word = "";

        for(int i=0; i<s.length(); i++){
            char ch = s.charAt(i);

            if(ch != ' '){
                word += ch;
            }
            else{
                if(!word.isEmpty()){
                    word.trim();
                    st.push(word);  
                    word = "";
                } 
            }
        }

        st.push(word);

        String ans = "";
        while(!st.empty()){
            String part = st.pop();
            ans = ans + part + " ";
        }

        return ans.trim();
    }
}