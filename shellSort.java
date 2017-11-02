package hello;

public class shellSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int[] array = {10,31,84,22,36,77,19,16,96,48};
		
		int i;
		
		shellSort(array);
}
	
	static void shellSort(int[] array) {
		int count = 1;
		for(int m=array.length; m>0;m=m/2) {
			System.out.println("\n"+"第"+count+"个增量为："+m);
			for(int n=0;n+m<array.length;n++) {
				if(array[n]>array[n+m]) {
					int temp = array[n];
					array[n] = array[n+m];
					array[n+m] = temp;
				}
			}
			count++;
			System.out.println("ÅÅÐòºóÎª");
			for(int k=0;k<array.length;k++) {
				System.out.print(array[k]+"\t");
			}
		}
	}
}
