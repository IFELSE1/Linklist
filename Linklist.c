/**
  ******************************************************************************
  * @file      Linklist.c
  * @author    青椒san
  * @version   V1.0
  * @date      2017-1-16
  * @brief     单链表-链表操作的C语言实现
  *
  ******************************************************************************
  * @attention
  *  参照《大话数据结构》线性表章节
  *
  ******************************************************************************
  */
  
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
 
/* Private define ------------------------------------------------------------*/

#define  TRUE   1
#define  FALSE  0  
/* Private typedef -----------------------------------------------------------*/

/**
  * @brief 定义 Elem_TypeDef 的类型为int型
  */
typedef int Elem_TypeDef;

/**
  * @brief 定义单链表的单链表存储结构
  */
typedef struct Node{
	Elem_TypeDef data;
	struct Node *next;
}Node_TypeDef;
/**
  * @brief 定义 Linklist_TypeDef
  */
typedef Node_TypeDef*  Linklist_TypeDef;

/**
  * @brief 定义函数的返回值状态
  */
typedef enum{
	FUN_OK,
	FUN_ERROR
}FUN_Status_TypeDef;
/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/




/* Private function prototypes -----------------------------------------------*/


/* Private functions ---------------------------------------------------------*/

/**
  * @brief 	建立一个空的单链表(头插法)
  * @param  linklist:单链表指针        
  *            
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef LinkList_CreateHead(Linklist_TypeDef * linklist,int n)
{
	Linklist_TypeDef p;
	int i;
	*linklist = (Linklist_TypeDef)malloc(sizeof(Node_TypeDef));
	if ( *linklist == NULL ){
		printf("建立链表失败");
		return FUN_ERROR;
	}
	/* 先建立一个带头结点的链表 */
	(*linklist)->next = NULL;   
	
	for (i=0;i<n;i++){
		/* 申请新结点 */
		p = (Linklist_TypeDef)malloc(sizeof(Node_TypeDef));
		if ( p == NULL){
			printf("申请新结点失败");
			return FUN_ERROR;
		}
		/* 为新结点赋值 */
		p->data = 0x00;
		/* 新结点插入到表头 */
		p->next = (*linklist)->next;
		(*linklist)->next = p;
	}
	return FUN_OK;
}

/**
  * @brief 	建立一个空的单链表(尾插法)
  * @param  linklist:单链表指针        
  *            
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef LinkList_CreateTail(Linklist_TypeDef * linklist,int n)
{
	Linklist_TypeDef p,r;
	int i;
	*linklist = (Linklist_TypeDef)malloc(sizeof(Node_TypeDef));
	if ( *linklist == NULL ){
		printf("建立链表失败");
		return FUN_ERROR;
	}
	/* 先建立一个带头结点的链表 */
	(*linklist)->next = NULL;   
	
	r = (*linklist);
	for (i=0;i<n;i++){
		/* 申请新结点 */
		p = (Linklist_TypeDef)malloc(sizeof(Node_TypeDef));
		if ( p == NULL){
			printf("申请新结点失败");
			return FUN_ERROR;
		}
		/* 为新结点赋值 */
		p->data = 0x00;
		/* 新结点插入到表尾 */
		r->next = p;
		r = p;
		r->next = NULL;
	}
	return FUN_OK;
}
/**
  * @brief  判断表是否为空
  * @param  
  *            
  * @retval TRUE:单链表为空
  *			FALSE：单链表为非空
  */
int ListEmpty(Linklist_TypeDef linklist)
{

}

/**
  * @brief 	将单链表清空
  * @param  sqlist:单链表指针       
  *            
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef LinkList_Clean(Linklist_TypeDef* linklist)
{
	Linklist_TypeDef p,q;
	/* p指向第一个结点 */
	p = (*linklist)->next;
	
	while(p){
		q = p->next;
		free(p);
		p = q;
	}
	(*linklist)->next = NULL;
	return FUN_OK;
}

/**
  * @brief  获取单链表的某个元素的值
  * @param  linklist:单链表
  * @param  i:要获取的元素的位置
  * @param  e:获取的元素的值的指针        
  *            
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef LinkList_GetElem(Linklist_TypeDef linklist,int i,Elem_TypeDef *e)
{
	int cont=0;
	Linklist_TypeDef  p;
	if ( i<0 || i>LinkList_Length(linklist)){
		printf("line 113 i的取值不对");
		return FUN_ERROR;
	}
	p = linklist->next;
	cont = 1;
	/* p不为空和计数器小于i时，循环继续 */
	while (p && cont<i){
		p = p->next;
		++cont;
	}
	/* 第i个元素不存在 */
	if ( !p || cont>i){
		return FUN_ERROR;
	} 
	/* 取得第I个元素的数据 */
	*e = p->data;
	
	return FUN_OK;
}


/**
  * @brief 	在单链表中查找给定值e的元素，并返回其序号
  * @param  sqlist:单链表指针       
  * @param  e:要查找的值       
  * @retval 查找成功： 返回序号
  *			查找失败： 返回 -1
  */
int LinkList_LocateElem(Linklist_TypeDef linklist,Elem_TypeDef e)
{
	
}

/**
  * @brief 	单链表中插入新元素
  * @param  linklist:单链表指针   
  * @param  i:插入的位置  
  * @param  e:新元素的值      
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef LinkList_Insert(Linklist_TypeDef *linklist,int i,Elem_TypeDef e)
{
	Linklist_TypeDef p,r;
	r = (*linklist);
	/* 新建结点 */
	p = (Linklist_TypeDef)malloc(sizeof(Node_TypeDef));
	p->data = e;
	if ( i>LinkList_Length(*linklist) || i<0  ){
		return FUN_ERROR;
	}
	/* 插入位置为表尾 */
	else if ( i == LinkList_Length(*linklist)){
		while(r!=NULL){
			 r = r->next; 
		}
		/* 插入表尾 */
		r->next = p;
		p->next = NULL;
	}
	/* 插入位置为表头或者其他位置 */
	else {
		while(i!=0){
			r = r->next;
			i--;
		}
		/* 插入新结点 */
		p->next = r->next;
		r->next = p;
	}
	return FUN_OK;
}

/**
  * @brief 	删除单链表中的元素
  * @param  sqlist:单链表指针   
  * @param  i:删除的元素的位置  
  * @param  e:被删除的元素的值    
  * @retval FUN_OK:成功
  *			FUN_ERROR：失败
  */
FUN_Status_TypeDef LinkList_Delete(Linklist_TypeDef *linklist,int i,Elem_TypeDef *e){
	
	int j;
	Linklist_TypeDef r,p;
	/* 将头指针赋予r */
	r = (*linklist)->next;
	if ( i<0 || i>LinkList_Length(*linklist) ){
		printf("要删除的元素超出链表范围");
		return FUN_ERROR;
	}
	else {
		while(i){
			r = r->next;
			i--;
		}
		p = r->next;
		r->next = p->next;
		*e = p->data;
		free(p);	
	}
	return FUN_OK;
}

/**
  * @brief 	获取单链表的元素个数
  * @param  sqlist:单链表   
  * @retval 单链表元素个数
  *			
  */
int LinkList_Length(Linklist_TypeDef linklist){
	int len=0;
	Linklist_TypeDef r;
	r = linklist->next;
	while(r){
		r = r->next;
		len++;
	}
	return len;
}
	
/* Exported functions --------------------------------------------------------*/

int main(void)
{
	int i;
	int l;
	Linklist_TypeDef linklist;
	Linklist_TypeDef r;
	if (LinkList_CreateTail(&linklist,12) == FUN_OK){
		printf("单链表创建成功\n");
	}
	l = LinkList_Length(linklist);
	printf("len=%d\n",l);
	/*
	LinkList_Insert(&linklist,0,9999);
	LinkList_Insert(&linklist,5,55);
	LinkList_Insert(&linklist,6,66);
	LinkList_Insert(&linklist,7,77);
	LinkList_Insert(&linklist,10,100);
	*/
	r = linklist->next;
	while(r){
		printf("%d\n",r->data);
		r = r->next;
	}

}



/********************************************************END OF FILE****/
