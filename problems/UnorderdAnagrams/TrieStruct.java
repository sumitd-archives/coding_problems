import java.util.*;
public class TrieStruct {
	TrieNode root;
    TrieStruct() {
    	root = new TrieNode();
    }
    public Boolean checkAndAdd(String subString , Boolean add) {
    	int length = subString.length();
    	Boolean ret = true;
    	TrieNode current = root;
    	for (int i = 0 ; i < length ; i++) {
    		char ch = subString.charAt(i);
    		int index = (int)ch - 97;
    		if (current.node[index] == null) {
    			ret = false;
    			if (add) {
    				current.node[index] = new TrieNode();	
    			}
    			else {
    				return false;
    			}
    	    }
    		current = current.node[index];
    	}
    	return ret;
    }
}
   
