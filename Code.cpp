#include <stdio.h>
#include <malloc.h>

struct object_point
{
	int len[100];//保存当前object到目的object的权值
	int max_len;//保存当前object到所有object的最大权值，存在不可达object时为-1
};

void searhTransFunc(object_point **allObject, int N);//搜索和计算到达所有object的权值
bool searhMaxFunc(object_point **allObject,int N);//找到每个object到其他object的最大权值
int searhMinFunc(object_point **allObject,int N);//在每个object的最大权值中选择最小权值

int main()
{
	int N = 0,M = 0;
	scanf("%d %d",&N,&M);// input  N & M

	int i;
	int j;
	object_point * allObject[101];
	while(N != 0)//当 N != 0 循环处理
	{
		for (i = 1; i <= N; i++)
		{//初始化N个结构体，默认长度-1，到自身长度0，
			allObject[i] = (object_point *)malloc(sizeof(object_point));
			allObject[i]->max_len = -1;
			for (j = 1; j <= N; j++)
			{
				allObject[i]->len[j] = -1;//default is -1 means can't transform
			}
			allObject[i]->len[i] = 0;
		}
		int ob1,ob2,obLen;
		for (i = 0; i < M; i++)
		{//输入长度记录到结构体中
			scanf("%d %d %d", &ob1, &ob2, &obLen);
			if (allObject[ob1]->len[ob2] == -1)
			{
				allObject[ob1]->len[ob2] = obLen;
				allObject[ob2]->len[ob1] = obLen;
			}
			else if (allObject[ob1]->len[ob2] > obLen)
			{
				allObject[ob1]->len[ob2] = obLen;
				allObject[ob2]->len[ob1] = obLen;
			}
		}

		searhTransFunc(allObject,N);//搜索和计算到达每个object的权值

		bool real = searhMaxFunc(allObject, N);//搜索所有可达object最大值，若有不可达object返回false
		if (real)
		{
			int obTake = searhMinFunc(allObject, N);
			printf("%d %d\n",obTake,allObject[obTake]->max_len);//不存在不可达object时输出
		}
		else
		{
			printf("0\n");//存在不可达object时输出
		}
		for (i = 1; i <= N; i++)
		{
			free(allObject[i]);//释放内存
		}
		scanf("%d %d",&N,&M);
	}
	return 0;
}
void searhTransFunc(object_point **allObject, int N)
{
	for (int ob_num1 = 1; ob_num1 <= N; ob_num1++)//从第一个object开始，每次加入一个新的object，搜索可达的所有路径中最短的
	{
		for (int ob_num2 = 1; ob_num2 <= N; ob_num2++)
		{
			if (ob_num2 == ob_num1 || allObject[ob_num1]->len[ob_num2] == -1)
			{
				continue;
			}
			for (int i = 1; i<= N; i++)//这是ob_num1通过ob_num2可达的节点搜索
			{
				if (allObject[ob_num2]->len[i] == -1 || allObject[ob_num2]->len[i] == 0)//当ob_num2也不可达或者是指向ob_num2本身时pass
				{
					continue;
				}
				if (allObject[ob_num1]->len[i] == -1)
				{//ob_num1不可达的object，结果就是直接把ob_num1到ob_num2的距离加上ob_num2到目标object的距离加上
					allObject[ob_num1]->len[i] = allObject[ob_num2]->len[i] + allObject[ob_num1]->len[ob_num2];
					allObject[i]->len[ob_num1] = allObject[ob_num2]->len[i] + allObject[ob_num1]->len[ob_num2];
				}
				else if (allObject[ob_num1]->len[i] > allObject[ob_num2]->len[i] + allObject[ob_num1]->len[ob_num2])
				{//ob_num1可达的object需要比较通过ob_num2的中介到达目标节点距离是否更短
					allObject[ob_num1]->len[i] = allObject[ob_num2]->len[i] + allObject[ob_num1]->len[ob_num2];
					allObject[i]->len[ob_num1] = allObject[ob_num2]->len[i] + allObject[ob_num1]->len[ob_num2];
				}
			}
		}
	}
}
bool searhMaxFunc(object_point **allObject, int N)
{
	for(int obnum1 = 1; obnum1 <= N; obnum1++)
	{//每个object中找到到达其他object最大的，obnum1是源头
		for (int obnum2 = 1; obnum2 <= N; obnum2++)
		{
			if (allObject[obnum1]->len[obnum2] == -1)
			{
				return false;//存在不可达object时返回false
			}
			if (allObject[obnum1]->len[obnum2] > allObject[obnum1]->max_len)
			{
				allObject[obnum1]->max_len = allObject[obnum1]->len[obnum2];
			}
		}
	}
	return true;//都可达时，此处已经计算完所有最大权值
}
int searhMinFunc(object_point **allObject, int N)
{
	int minLenObNum =1;//记录有最小权值的object
	int minLen = allObject[1]->max_len;//记录最小权值
	for(int obnum1 = 2; obnum1 <= N; obnum1++)
	{//遍历搜索一遍结构体指针数组找到最小权值
		if (allObject[obnum1]->max_len < minLen)
		{
			minLen = allObject[obnum1]->max_len;
			minLenObNum = obnum1;
		}
	}
	return minLenObNum;//返回最小权值的object
}
