package hello;

public class quickSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int[] arr = {13,75,48,57,74,26,42,18,49,85};
		int start = 0;
		int end = arr.length-1;
		
		printArray("≈≈–Ú«∞£∫",arr);
        QuickSort(arr,0,arr.length-1);
        printArray("\n"+"≈≈–Ú∫Û£∫",arr);
	}

	
	public static void printArray(String s,int[] array) {
		System.out.print(s+"\n");
        for(int i=0;i<array.length;i++)
            System.out.print(array[i]+"\t");    
        System.out.println();
	}
	
	public static void QuickSort(int[] array,int low,int high) {
		int start = low;
		int end = high;
		int key = array[low];
		
		while(end>start) {
			while(end>start&&array[end]>=key) 
				end--;
			
				if(array[end]<=key) {
					int temp = array[end];
					array[end] = array[start];
					array[start]=temp;
				}
				
			while(end>start&&array[start]<=key) 
				start++;
			
				if(array[start]>=key) {
					int temp = array[start];
					array[start] = array[end];
					array[end] = temp;
				}
				
		}
				if(start>low) QuickSort(array,low,start-1);
				if(end<high) QuickSort(array,end+1,high);
		
		}
	
}
