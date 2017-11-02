package hello;

public class heapSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int[] arr = {48,45,99,68,17,31,75,36,15,69};
		
		printArray("ÅÅĞòÇ°£º",arr);
        HeapSort(arr);
	}
	
	public static void HeapSort(int[] array) {
		int i;
		for(i = array.length/2-1; i>=0; i--) {
			maxHeapify(array,i,array.length-1);
		}
	
		for (i = array.length - 1; i >= 0; i--) {
            int temp = array[0];
            array[0] = array[i];
            array[i] = temp;
           maxHeapify(array, 0, i - 1);
        }
		printArray("\n"+"ÅÅĞòºó£º",array);
	}

	public static void maxHeapify(int[] array,int i,int len) {
		
		int temp, j;
        temp = array[i];
        for (j = 2 * i; j < len; j *= 2) {
            if (j < len && array[j] < array[j + 1])
                ++j; 
            if (temp >= array[j])
                break;
            array[i] = array[j];
            i = j;
        }
        array[i] = temp;
 	} 
	
	public static void printArray(String s,int[] array) {
		System.out.print(s+"\n");
        for(int i=0;i<array.length;i++)
            System.out.print(array[i]+"\t");    
        System.out.println();
	}
}
