// #include <graph_input.h>
#include <bits/stdc++.h>
using namespace std;
bool check_td(graph g, graph t, bags b);

class graph
{
  public:
	graph(int a, int b)
	{
		v = a;
		no_of_edges = b;
	}
	int v;
	int no_of_edges;
	int matrix[100][100];
	void add_edge(int a, int b)
	{
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}
	void print_matrix()
	{
		cout << "------Adjacent matrix-------" << endl;
		for (int i = 0; i < v; ++i)
		{
			for (int j = 0; j < v; ++j)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
};


void print_vector(vector<int>& x)
{
	for (int i = 0; i < x.size(); ++i)
	{
		cout << x[i] << " ";
	}
	cout << endl;
}


class bags
{
public:
	bags(int a)
	{
		width = b;
	}	
	int width;
	vector< vector<int> > bag_list;

	void add_bag(vector<int>& line)
	{
		bag_list.push_back(line);
	}
	void print_baglist()
	{
		cout << "###########Bags##########" << endl;
		for (int i = 0; i < bag_list.size(); i++)
		{
		    for (int j = 0; j < bag_list[i].size(); j++)
		    {
		        cout << bag_list[i][j] << " ";
		    }
		    cout << endl;
		}
	}
};

class node
{
	public:
	vector<node *> child;
	vector<int > sack;
};

node *newNode(vector<int> key)    								//check whether child and sack are null when new node is called
{ 
   	node *temp = new node; 
	temp->sack = key;
   	return temp; 
}


nice_tree_decomposition(graph g, graph t, bags b)
{
	vector<int> collection;
	node* root = newNode(collection); // check null is there or not for root

	node* temp = root;
	int root_vertex=0;
	for(auto i: b.bag_list[root_vertex])									// what if bag0 is disconnected
	{															// keep a loop over vertex 
		collection.push_back(i);
		node* x = newNode(collection);
		temp->child.pushback(x);
		temp = x;
	}


		int child_size=0;
		for (int i = 0; i < t.v; ++i)
		{
			if (t.matrix[root_vertex][i]==1)
			{
				child_size++;
			}
		}
		if (child_size == 0)
		{ // leaf node

		}
		else if (child_size == 1)
		{ // check intersection vertices
			intersection();
			intro();
			forget();
		}
		else if (child_size > 1)
		{
			convert_binary();   									// t have to be changed but changes wont reflect back
			temp->child.push_back( );
			temp->child.push_back( );
		}
}

extended_ntd()
{
	for (int i = 0; i < t.v; ++i)									// first convert ntd to have edges in them 
	{
		for (int j = 0; j < t.v; ++j)
		{
			if (t.matrix[i][j] == 1)								// check 2 triangle matrix
			{
				b = find_closest_node();
				c = newNode();
				c.child = b;
				b.parent.child = c;
			}
		}
	}
}

int node_type() 				// forget node adding vertex does it lead to adding edges also ??
{
	if (size == 2)
	{
		return 3;
	}
	else 
	{
		equal ;
		return 4;
	}
	else 
	{
		a = x.sack;
		b = x.child.sack;
		sort(a);
		sort(b);
		std::set_difference(a.begin(), a.end(), b.begin(), b.end(), std::inserter(a_b, a_b.begin()));
		std::set_difference(b.begin(), b.end(), a.begin(), a.end(), std::inserter(b_a, b_a.begin()));
		if (a_b.size() >= 1)
		{
			return 1;
		}
		else if(b_a.size() >= 1)
		{
			return 2;
		}
	}
}

partition_bag()
{

}

int dominating_set()
{
	int type = node_type();
	if(type == 0)													// leaf node
	{
		return ;
	}
	else if(type == 1)												// introduce vertex node
	{
		partition_bag();
		get_v();
		if ( == 0)		// white color
		{
			c(x) = std::numeric_limits<int>::max();
		}
		else if ( == -1)
		{
			c() = 
		}
		else if( == 0)
		{

		}
	}
	else if(type == 2)												// forget node
	{

	}
	else if(type == 3)												// join node
	{

	}
	else if(type == 4)												// introduce edge node
	{

	}

	return ;
}

int main(int argc, char const *argv[])
{
	fstream file;
	string line, word;

	graph g(0, 0);
	graph t(0, 0);
	bags b(0);

	file.open("g1.txt", ios::in);
	cout << "###########Graph##########" << endl;

	if (file.is_open())
	{
		getline(file, line);
		file >> word;

		file >> word;
		int v = stoi(word);
		file >> word;
		int no_of_edges = stoi(word);

		cout << "v : \t\t" << v << endl;
		cout << "no of bags : \t" << no_of_edges << endl << endl;

		g.v = v;
		g.no_of_edges = no_of_edges;

		getline(file, line); // to finish prev line 
		while(getline(file, line))
		{
			string a, b;
			istringstream parse(line);
			parse >> a;
			parse >> b;
			g.add_edge(stoi(a), stoi(b));
		}
	}

	g.print_matrix();
	cout << endl;
	file.close();

	file.open("decomposition.txt", ios::in);
	cout << "###########Tree##########" << endl;

	if (file.is_open())
	{
		getline(file, line); //First line is comment line
		file >> word;   //Reads character "s"

		file >> word;
		int no_of_bags = stoi(word);
		file >> word;
		int width = stoi(word);
		file >> word;
		cout << "v : \t\t" << no_of_bags << endl;
		cout << "width : \t" << width << endl;

		t.v = no_of_bags;
		b.width = width;

		getline(file, line); // to finish prev line 
		for (int i = 0; i < no_of_bags; ++i)
		{
			getline(file, line);
			istringstream parse(line);
			vector<int> x;
			parse >> word;
			parse >> word;
			while(parse >> word)
			{
				x.push_back(stoi(word));	
			}
			b.add_bag(x);
			// break;
		}

		while(getline(file, line))
		{
			string a, b;
			istringstream parse(line);
			parse >> a;
			parse >> b;
			t.add_edge(stoi(a), stoi(b));
		}

	}
	
	file.close();

	t.print_matrix();
	b.print_baglist();
	cout<<endl;

	if(check_td(g, t, b))
	{
		cout<< "(T,B) is not a simple tree decomposition of G" << endl;
		return 0;
	}


	nice_tree_decomposition();
	extended_ntd();
	int result = dominating_set();
	if (result)
	{
	   	cout << "Minimum dominating set size : " << result << endl;
	}
	
	return 0;
}

bool check_td(graph g, graph t, bags b)
{
	bool flag, flag1, flag2;
	for (int i = 0; i < g.v; ++i)                    // For each vertex i
	{
		flag = false;
		for (int j = 0; j < t.v; ++j)                // Searching for a bag containing i
		{
			for (auto k : b.bag_list[j])
			{
				if (i == k)
				{
					flag = true;
					break;
				}
			}
			if (flag)
			{
				break;
			}
		}
		if (!flag)                                   // If i is not found in any bag then return false
		{
			return false;
		}
	}

	for (int i = 0; i < g.v; ++i)
	{
		for (int j = 0; j < g.v; ++j)
		{
			if (g.matrix[i][j] == 1)             	// For each edge i,j
			{
				flag = false;
				for (int k = 0; k < t.v; ++k)       // Searching for a bag containing both i,j
				{
					flag1 = false;
					flag2 = false;
					for (auto l : b.bag_list[k])
					{
						if (i == l)
						{
							flag1 = true;
						}
						if (j == l)
						{
							flag2 = true;
						}
					}
					if (flag1 && flag2)
					{
						flag = true;
					}
				}
				if (!flag)							// If i is not found in any bag then return false
				{
					return false;
				}
			}
		}
	}

	for (int i = 0; i < g.v; ++i)                 	//For each vertex i
	{
		bool mark[t.v];
		for (int j = 0; j < t.v; ++j)
		{
			mark[j] = false;
		}
		for (int j = 0; j < t.v; ++j)			  	//Marking all the bags containing i 
		{
			for (auto k : b.bag_list[j])
			{
				if (k==i)
				{
					mark[j] = true;
					break;
				}
			}
		}

		for (int j = 0; j < t.v; ++j)			 	// Starting bfs with bag j containing i 
		{
			for (auto k : b.bag_list[j])
			{
				if (i == k)
				{
					bool visited[t.v];
					for (int l = 0; l < t.v; ++l)
					{
						visited[l] = false;
					}
					list<int> queue;

					visited[j] = true;				// bag j is visited
					queue.push_back(j);

					while(!queue.empty())
					{
						int s = queue.front();
						queue.pop_front();
						for (int m = 0; m < t.v; ++m)  // Exploring the child m
						{
							if (t.matrix[s][m] == 1 && !visited[m])
							{
								for (auto n : b.bag_list[m])
								{
									if (n == i)      // If child m contains i then push it to queue
									{
										visited[m] = true;
										queue.push_back(m);
										break;
									}
								}
							}
						}
					}

					for (int l = 0; l < t.v; ++l)
					{
						if (mark[l] != visited[l])
						{
							return false;
						}
					}
					break;
				}
			}
		}
	}


	for (int i = 0; i < t.v; ++i)     			// For each bag 
	{
		for (int j = 0; j < t.v; ++j)
		{
			if (i != j)
			{
				flag = false;
				map <int,int> m;
			    for(auto k : b.bag_list[j])
			    {
			        m[k]++;
			    }
			    for(auto k : b.bag_list[i])
			    {
			        if(m.find(k)==m.end()) 
			        {
			        	flag = true;
			        	break;
			        }
			    }
			    if (!flag)
			    {
			    	return false;
			    }
			}
		}
	}

	return true;
}




