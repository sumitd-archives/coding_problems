import java.util.*;
public class MainClass {
	public static void main(String[] Args) {
		Scanner intScan = new Scanner(System.in);
		int length = intScan.nextInt();
		Vector inputStrings = new Vector(length);
		Scanner stringScan = new Scanner(System.in);
		for (int i = 0 ; i < length ; i++) {
			inputStrings.addElement(stringScan.next());
		}
		//display
		Iterator itr = inputStrings.iterator();
		while (itr.hasNext()) {
			int count = 0;
			TrieStruct struct = new TrieStruct();
			String input = (String)itr.next();
			for (int i = 0 ; i < input.length(); i++) {
				StringBuilder current = new StringBuilder();
				
				for (int j = i ; j < input.length(); j++) {
					current.append(input.charAt(j));
					String reverse = new StringBuilder(current).reverse().toString();
					Boolean ret1 = struct.checkAndAdd(reverse , false);
					Boolean ret2 = struct.checkAndAdd(current.toString() , true);
					if (ret1 || ret2) {
						count++;	
					}
				} 	 
			}
			System.out.println(count);	
		}
	}
}