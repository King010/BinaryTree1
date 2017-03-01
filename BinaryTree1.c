
template<class T>
struct BinaryTreeNode
{
	BinaryTreeNode(const T& data = T())
	:_data(data)
	, _pLeftChild(NULL)
	, _pRightChild(NULL)
	{}

	T _data;
	BinaryTreeNode<T>* _pLeftChild;
	BinaryTreeNode<T>* _pRightChild;
};

template<class T>
class BinaryTree
{
public:
	BinaryTree()
		:_pRoot(NULL)
	{}
	BinaryTree(const T array[], size_t size)
		:_pRoot(NULL)
	{
		size_t index = 0;
		_CreatBinaryTree(_pRoot, array, size, index);
	}
	BinaryTree(BinaryTree<T>& tree)
	{
		_pRoot = _CopyBinartTree(tree._pRoot);
	}
	BinaryTree<T>& operator=(BinaryTree<T>& tree)
	{
		if (this != &tree)
		{
			this->~BinaryTree();
			_pRoot = _CopyBinartTree(tree._pRoot);
		}
		return *this;
	}
	void PreOrder()
	{
		_PreOreder(_pRoot);
	}
	void InOrder()
	{
		_InOrder(_pRoot);
	}
	void PostOrder()
	{
		_PostOrder(_pRoot);
	}

	void LevelOrder()
	{
		_LevelOrder();
	}
	~BinaryTree()
	{
		_DestoryBinaryTree(_pRoot);
	}

private:
	void _CreatBinaryTree(BinaryTreeNode<T>*& pRoot, const T array[], size_t size, size_t& index)//构造二叉树
	{
		if (index < size && '#' != array[index])
		{
			pRoot = new BinaryTreeNode<T>(array[index]);
			_CreatBinaryTree(pRoot->_pLeftChild, array, size, ++index);
			_CreatBinaryTree(pRoot->_pRightChild, array, size, ++index);
		}
	}
	
	void _DestoryBinaryTree(BinaryTreeNode<T>*& pRoot)//销毁二叉树
	{
		if (pRoot)
		{
			_DestoryBinaryTree(pRoot->_pLeftChild);
			_DestoryBinaryTree(pRoot->_pRightChild);
			delete pRoot;
			pRoot = NULL;
		}
	}

	void _PreOreder(BinaryTreeNode<T>* proot) //前序遍历
	{
		if (proot)
		{
			cout << proot->_data << " ";
			_PreOreder(proot->_pLeftChild);
			_PreOreder(proot->_pRightChild);
		}
	}
	void _InOrder(BinaryTreeNode<T>* proot) //中序遍历
	{
		if (proot)
		{
			_InOrder(proot->_pLeftChild);
			cout << proot->_data << " ";
			_InOrder(proot->_pRightChild);
		}
	}
	void _PostOrder(BinaryTreeNode<T>* proot)  //后续遍历
	{
		if (proot)
		{
			_PostOrder(proot->_pLeftChild);
			_PostOrder(proot->_pRightChild);
			cout << proot->_data << " ";
		}
	}
	void _LevelOrder()//层序遍历
	{
		if (NULL == _pRoot)
			return;
		queue<BinaryTreeNode<T>*>q;
		q.push(_pRoot);
		while (!q.empty())
		{
			BinaryTreeNode<T>*pCur = q.front();
			cout << pCur->_data << " ";
			if (pCur->_pLeftChild)
				q.push(pCur->_pLeftChild);
			if (pCur->_pRightChild)
				q.push(pCur->_pRightChild);
			q.pop();
		}
	}
private:
	BinaryTreeNode<T>* _pRoot;
};