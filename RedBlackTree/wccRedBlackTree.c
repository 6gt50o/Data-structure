#include<stdio.h>


#define RED			0
#define BLACK		1

#define  TRUE		2
#define  FALSE		-1
#define      boolean          unsigned  char

typedef   int   Elementype;

typedef struct RedBlackTree{

	int color;
	Elementype  data;
	RedBlackTree  *left;
	RedBlackTree *right;
	RedBlackTree *parent;

}RedBlackTree;

//���в������
boolean rbTreeInsertNode(RedBlackTree **rbTree, Elementype data);

//��������
void rbTreeInsertFixup(RedBlackTree **rbTree, RedBlackTree *node);

//��������ת
void rbTreeLeftRotate(RedBlackTree **rbTree, RedBlackTree *node);

//��������ת
void rbTreeRightRotate(RedBlackTree **rbTree, RedBlackTree *node);



void rbTreeRightRotate(RedBlackTree **rbTree, RedBlackTree *node){

	RedBlackTree *y;

	y = node->left;
	node->left = y->right;
	if(y->right != NULL){
		y->right->parent = node;
	}
	y->parent = node->parent;

	// nodeΪ����
	if(node->parent == NULL){
		*rbTree = y;
	}else{
		if(node->parent->left == node){
			node->parent->left = y;
		}else{
			node->parent->right = y;
		}
	}

	y->right= node;
	node->parent = y;

}


void rbTreeLeftRotate(RedBlackTree **rbTree, RedBlackTree *node){
	
	RedBlackTree *y;

	y = node->right;
	node->right = y->left;
	if(y->left != NULL){
		y->left->parent = node;
	}
	y->parent = node->parent;

	// nodeΪ����
	if(node->parent == NULL){
		*rbTree = y;
	}else{
		if(node->parent->left == node){
			node->parent->left = y;
		}else{
			node->parent->right = y;
		}
	}

	y->left = node;
	node->parent = y;
	
}



void rbTreeInsertFixup(RedBlackTree **rbTree, RedBlackTree *node){
	
	RedBlackTree *p = NULL;
	RedBlackTree *gparent = NULL;
	RedBlackTree *uncle = NULL;

	//���� ����2

	while((p = node->parent) != NULL && p->color == RED){
		gparent = p->parent;
		//������ڵ����游�ڵ������(��Ϊ���ڵ��Ǻ�ɫ�ڵ㣬���Կ϶����游�ڵ�
		if(p == gparent->left){
			//uncle ���׵��ֵܽڵ�
			uncle = gparent->right;
			//���1: ��������常�ڵ㣬�����常�ڵ���ɫΪ��ɫ�������ͨ���ı��游
			//���常�ڵ����ɫ
			
			//ʹ�� ��ǰ�����ƻ����ʵĽڵ������������� node ��Ϊ�游
			if(uncle != NULL && uncle->color == RED){
				gparent->color = RED;
				p->color = BLACK;
				uncle->color = BLACK;
				node = gparent;

				//�常�����ڻ��ߴ��ڵ��� ��ɫ�Ǻ�ɫ�ģ������ͨ����ת����ϸı�����������2
			}else{
				// ���2   xΪ�� ���ڵ���Һ��ӣ�ͨ������תת��Ϊ���3
				if(node == p->right){
					// ����x�ĸ��ڵ����������ԭx���Ϊ x'
					node = p;
					rbTreeLeftRotate(rbTree, node);
					// ��ת������node ��ʹ����ȻΪnode���ĸ��ڵ�()
					p = node->parent;
				}
			}			
		}
	}
}

boolean rbTreeInsertNode(RedBlackTree **rbTree, Elementype data){
	
	//����һ���½ڵ�
	RedBlackTree* node = NULL;
	RedBlackTree* curNode = NULL;
	RedBlackTree* p = NULL;

	if(node = (RedBlackTree *)malloc(sizeof(RedBlackTree))){
		node->data = data;
		node->color = RED;
		node->left = NULL;
		node->right = NULL;
		node->parent = NULL;
	}

	curNode = *rbTree;

	//�ҵ��½ڵ�Ĳ���λ�ã�p �����Ŵ�����綨�ĸ��ڵ�
	while(curNode != NULL){
		p = curNode;
		if(data < curNode->data){
			curNode = curNode->left;
		}else{
			curNode = curNode->right;
		}
	}

	//���Ϊ�������½ڵ�ֱ��Ϊ���ڵ�
	if(NULL == p){
		*rbTree = node;
	}else{
		//�Ƚϴ�С��Ȼ������ǲ�����߻����ұ�
		if(data < p->data){
			p->left = node;
		}else{
			p->right = node;
		}
	}

	node->parent = p;
	
	// ��������� ���Ա���������

	//rbTreeInsertFixup();

	return TRUE;

}


void main(void){


}




