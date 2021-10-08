/* 查找表内数据的时间操作近似为o(1) */

/*1.直接哈希函数
    直接哈希函数是直接取关键字或关键字的某个线性函数作为哈希函数
    其特点是关键字与哈希地址之间是一对一的关系
    因此不会发生冲突
    但它的空间浪费严重
    因为在大多数情况下
    由哈希函数计算出来的地址不是连续的
*/

/*2.哈希冲突
    在哈希表的建表过程中
    若对于某个哈希函数H(k)
    若有两个或两个以上的关键字映射的哈希地址相同
    即H(key1)= H(key2)(key1≠key2)则发生冲突
    选择哈希函数时应选择均匀的，冲突较少的
    但在大多数情况下
    冲突是不可避免的
    因此解决冲突是哈希查找中的主要研究内容
*/

/*解决哈希冲突方案
    1.开放地址法
    将整个哈希地址区看成一个线性环形表(数组)
    当冲突发生时
    根据某种解决冲突的方法
    为发生冲突的关键字找出一个“空”的地址单元作为该关键字的哈希地址
    若插入元素
    则碰到空的地址单元就存放要插入的同义词。
    若检索元素
    则需要碰到空的地址单元后
    才能说明表中没有待查的元素(检索失败)。 


*/
#include<iostream>
using namespace std;

enum Error_code{not_present, overflow, duplicate_error, success};
const int hash_size = 97;

class Hash_table {
public:
    Hash_table();
	void clear( );
	Error_code insert(const Record &new_entry);
	Error_code retrieve(const Key &target, Record &found) const;
	Error_code remove(const Key &target, Record &found);
private:
	Record table[hash_size];  //数组
};

int hash(const Record &new_entry);
int hash(const Key &new_entry);

class Key {
	int key;
public:
	Key (int x = 0);
	int the_key( ) const;
};

bool operator == (const Key &x, const Key &y);

class Record{
public:
	operator Key( ); // implicit conversion from Record to Key .
	Record(int x=0, int y=0);
	int the_key( ) const;
	int the_other() const;

private:
	int key;
	int other;
};

bool operator != (const Record &x, const Record &y);
bool operator == (const Record &x, const Record &y);

void Hash_table :: clear(){
	for(int i=0; i<hash_size; i++){
		Record tmp;
		table[i]=tmp; 
	}
}

int hash(const Record &new_entry){
	return new_entry.the_key()%hash_size;
}

int hash(const Key &new_entry){
	return new_entry.the_key()%hash_size;
}

Error_code Hash_table :: insert(const Record &new_entry)
{
	Error_code result = success;
	int probe_count, // Counter to be sure that table is not full.
	increment, // Increment used for quadratic probing.
	probe; // Position currently probed in the hash table.
	probe = hash(new_entry);
	probe_count = 0; increment = 1;
	if(retrieve((Record)new_entry, (Record)new_entry)==success) return  duplicate_error;
	while (table[probe] != 0 // Is the location empty?
		&& table[probe] != -1 // empty because delete
		&& probe_count < (hash_size + 1)/2) { // Has overflow occurred?   //这种判断哈希表是否已经满的方式值得商榷？？ 似乎并不妥当
		probe_count++;
		probe = (probe + increment)%hash_size;
		increment += 2; // Prepare increment for next iteration.每次递增2。
	}
	if (table[probe] == 0) table[probe] = new_entry;
	if (table[probe] == -1) table[probe] = new_entry;
	// Insert new entry.
	else result = overflow; // The table is full.
	return result;
}

Error_code Hash_table :: retrieve(const Key &target, Record &found) const{
	int probe_count, // Counter to be sure that table is not full.
	increment, // Increment used for quadratic probing.
	probe; // Position currently probed in the hash table.
	probe = hash(target);
	probe_count = 0;
	increment = 1;
	while (table[probe] != 0 // Is the location empty?
		&& table[probe].the_key() != target.the_key() // not found
		&& probe_count < (hash_size + 1)/2) { // Has overflow occurred?
		probe_count++;
		probe = (probe + increment)%hash_size;
		increment += 2; // Prepare increment for next iteration.
	}
        if (table[probe].the_key() == target.the_key()){
		found = table[probe];
		return success;
	}
	else return not_present;
}

Error_code Hash_table :: remove(const Key &target, Record &found){
	
        int probe_count, // Counter to be sure that table is not full.
	increment, // Increment used for quadratic probing.
	probe; // Position currently probed in the hash table.
	probe = hash(target);
	probe_count = 0;
	increment = 1;
	while (table[probe] != 0 // Is the location empty?
		&& table[probe].the_key() != target.the_key() // not found
		&& probe_count < (hash_size + 1)/2) { // Has overflow occurred?
		probe_count++;
		probe = (probe + increment)%hash_size;
		increment += 2; // Prepare increment for next iteration.
	}
        if (table[probe].the_key() == target.the_key()){
		found=table[probe];
		table[probe]=-1;  //attention
		return success;
	}
	else return not_present;
}

void main(){
	Hash_table myhash;
	myhash.insert(Record(3,20));
	myhash.insert(Record(5,30));
	myhash.insert(Record(9,50));
	Record target;
	myhash.retrieve(Key(5),target);
	cout<<"Key: "<<target.the_key()<<"  The other: "<<target.the_other()<<endl;
	target=Record(0,0);
	myhash.retrieve(Key(3),target);
	cout<<"Key: "<<target.the_key()<<"  The other: "<<target.the_other()<<endl;
