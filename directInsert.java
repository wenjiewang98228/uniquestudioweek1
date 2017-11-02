package hello;

public class directInsert {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int[] array = {10,31,84,54,36,77,16,16,96,48};
		
		int i,j,temp;
		for(i=1;i<array.length;i++) {
			temp = array[i];
			for(j=i;j>0&&array[j-1]>temp;j--) {
				
					array[j] = array[j-1];
					array[j-1] = temp;
				
				
			}
		}
		for(int k = 0; k<array.length; k++) {
			System.out.println(array[k]);
		}
		
}
	}
