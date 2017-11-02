package hello;

public class mergeSort {


	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int[] arr = {12,66,89,48,16,77,36,15,72,19};

		printArray("排序前：",arr);
        MergeSort(arr);
        printArray("\n"+"排序后：",arr);
	}	
	  
	  public static void printArray(String s,int[] array) {
			System.out.print(s+"\n");
	        for(int i=0;i<array.length;i++)
	            System.out.print(array[i]+"\t");    
	        System.out.println();
		}
	  
	  
	  public static void MergeSort(int[] array) {
		  System.out.println("开始排序");
          mSort(array, 0, array.length - 1);
	  }
	  
	/** 
	     * 将两个数组进行归并，归并前面2个数组已有序，归并后依然有序 
	     *  
	     * @param array 
	     *            数组对象 
	     * @param left 
	     *            左数组的第一个元素的索引 
	     * @param center 
	     *            左数组的最后一个元素的索引，center+1是右数组第一个元素的索引 
	     * @param right 
	     *            右数组最后一个元素的索引 
	     */

		public static void mSort(int[] array, int left, int right) {
			// TODO Auto-generated method stub
			int center;
			if(left<right) {
				center = (left+right)/2;
				mSort(array,left,center);
				mSort(array,center+1,right);
				merge(array,left,center+1,right);
				}
		}
		
	
	/** 
	     * 将两个数组进行归并，归并前面2个数组已有序，归并后依然有序 
	     *  
	     * @param temp 
	     *            临时数组对象 
		 * @param tmpPos 
	     *            临时数组位置索引
	     * @param leftPos 
	     *            左数组位置索引 
	     * @param rightPos 
	     *            右数组位置索引 
		 * @param leftEnd 
	     *            左数组最后一个元素的索引
	     * @param rightEnd 
	     *            右数组最后一个元素的索引 
	     */
	
		public static void merge(int[] array, int leftPos,int rightPos,int rightEnd) {
			
			int[] temp = new int[array.length];
			int tmpPos,leftEnd,index;
			
			tmpPos = leftPos;
			leftEnd = rightPos-1;
			index = leftPos;
			
			while(leftPos<=leftEnd && rightPos<=rightEnd) {
				if(array[leftPos]<=array[rightPos]) {
					temp[tmpPos] = array[leftPos];
					tmpPos++;
					leftPos++;
				}
				else {
					temp[tmpPos] = array[rightPos];
					tmpPos++;
					rightPos++;
				}
			}
			
			while(leftPos<=leftEnd) {
				temp[tmpPos] = array[leftPos];
				tmpPos++;
				leftPos++;
			}
			
			while(rightPos<=rightEnd) {
				temp[tmpPos] = array[rightPos];
				tmpPos++;
				rightPos++;
			}
			
			System.out.println("---");
			while(index<=rightEnd){
				array[index] = temp[index];
				System.out.print(array[index]+"\t");
				index++;
			}
		}
		
		
}
