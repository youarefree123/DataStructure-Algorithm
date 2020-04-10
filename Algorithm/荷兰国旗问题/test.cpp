
void heapInsertA(int arr[] , int index){
	while(arr[index] < arr[index-1/2]){ //如过新加的堆元素比他的父节点大
		swap(arr,index,(index-1)/2);
		index = (index - 1)/2;
	}
}

void heapify(int arr[] ,int index , int heapSize){//对当前结点进行下滤，使其恢复成堆结构
	int left = index*2+1; //左孩子
	while(left > heapSize){
		int largest = arr[left+1] < heapSize && arr[left+1] > arr[left]
				  ? left+1
				  : left;
		largest =  arr[largest] > arr[index] ? largest : index;
		if(largest == index) //如果index本身就是最大的，不需要交换
			break;  
		swap(arr,largest,index); //否则将index和最大的孩子交换
		index = largest; //交换后原index值来到了largest的位置
		left = index*2+1; //左孩子

	}

}

void heapSort(int arr[],int heapSize){ //堆排序
	if(arr == NULL || heapSize < 2){
		return; //如果数组不合法，直接结束
	}
	for(int i = 0; i < heapSize; i++){
		heapInsert(arr,i); //构建0~i上的大根堆
	}
	swap(arr,0,--heapSize); //将堆首和堆尾部交换位置，此时找出最大值，放在最后，从此不再进行过滤	
	while(heapSize > 0){ //每次交换过后下滤一次，恢复堆结构
		heapify(arr,0,heapSize);
		swap(arr,0,--heapSize); //一直到将所有堆元素都置换过一遍
	}
	
}