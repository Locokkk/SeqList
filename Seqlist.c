#include"Seqlist.h"

void SeqlistInit(Seqlist* ps,size_t capacity)
{
	if (capacity == 0)
	{
		size_t _size = 0;
		ps->_size = 0;
		ps->_array = NULL;
		size_t capacity = 0;
	}
	else {
		size_t _size = 0;
		ps->_size = 0;
		size_t Capacity = capacity;
		ps->_array = (DataType*)malloc(sizeof(DataType)*capacity);
		assert(ps->_array);
	}
}

void SeqlistDestory(Seqlist* ps)
{
	assert(ps);
	if (ps->_array)
	{
       free(ps);
	   ps->_array = NULL;
	   ps->_size = ps->capacity = 0;
	}
}

void CheckCapacity(Seqlist* ps)
{
	assert(ps);
	if (ps->_size == ps->capacity)
	{
		size_t newcapacity = (ps->capacity == 0 ? 4 : ps->capacity * 2);
		ps->_array = realloc(ps->_array, sizeof(DataType)*newcapacity);
		ps->capacity = newcapacity;
	}
}

void SeqlistPushBack(Seqlist* ps, DataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size] = x;
	ps->_size++;
}

void SeqlistPopBack(Seqlist* ps)
{
	/*free(ps->_array[ps->size]);*/
	--ps->_size;
}

void SeqlistPushFront(Seqlist* ps, DataType x)
{
	CheckCapacity(ps);
	int  end = ps->_size - 1;
	for (end;end>=0;end--)
	{
		ps->_array[end + 1] = ps->_array[end];
	}
	ps->_array[0] = x;
	SeqlistPopBack(ps);
}

void SeqlistPopFront(Seqlist* ps)
{
	assert(ps);
	size_t start = ps->_array[0];
	size_t end = ps->_size - 1;
	for (start;start<=end;start++)
	{
		ps->_array[start] = ps->_array[start + 1];
	}
}

int SeqlistFind(Seqlist* ps, DataType x)//寻找某个指定的值
{
	assert(ps);
	size_t i = 0;
	for (i = 0;i < ps->_size;i++)
	{
		if (ps->_array[i] == x)
		{
			return i;
		}
		return -1;
	}
}
void SeqlistInsert(Seqlist* ps, size_t pos, DataType x)//指定位置添加
{
	assert(ps);
	CheckCapacity(ps);
	size_t i = 0;
	for (i = ps->_size;i>=pos;i--)
	{
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[pos] = x;
	ps->_size++;
}
void SeqlistErase(Seqlist *ps, size_t pos)//指定位置删除
{
	assert(ps);
	size_t i = 0;
	for (i = pos + 1;i <= ps->_size;i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}
void SeqlistRemove(Seqlist* ps, DataType x)//指定内容删除
{
	assert(ps);
	size_t pos=0;
	SeqlistFind(ps, x);
	if (pos != -1)
	{
		SeqlistErase(ps, pos);
	}
}
void SeqlistModify(Seqlist* ps, size_t pos, DataType x)//指定位置修改
{
	assert(ps);
	ps->_array[pos] = x;
}
void SeqlistPrint(Seqlist* ps)//打印
{
	assert(ps);
	for (size_t i = 0;i < ps->_size;i++)
	{
		printf("%3d", ps->_array[i]);
	}
	printf("\n");
}









