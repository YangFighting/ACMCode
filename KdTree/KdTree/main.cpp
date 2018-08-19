#include <iostream>
#include "pf_vector.h"
#include "pf_kdtree.h"
using namespace std;
int main()
{
	std::cout << "Hello world" << std::endl;
	double tt = 2.4;
	printf("%f\n", tt);
	const int max_size = 5;
	const int kd_max_size = 2* max_size;
	pf_kdtree_t * kdtree;
	kdtree = pf_kdtree_alloc(kd_max_size);
	pf_vector_t pose;
	double value = 0.0;
	double data[max_size][2] = {{2,3}, {5,4},{9,6}, {4,7}, {8,1} };
	for (int i = 0; i < max_size; i++)
	{
		pose.v[0] = data[i][0];
		pose.v[1] = data[i][1];
		pose.v[2] = 1;

		//cout << "i = " << i << endl;
		//for (int ii = 0; ii < 3; ii++)
		//	cout << pose.v[ii] << "  ";
		//cout << endl;

		pf_kdtree_insert(kdtree, pose, value);
	}

	pf_kdtree_cluster(kdtree);
	pf_kdtree_print_node(kdtree, kdtree->root);

	pf_kdtree_free(kdtree);
	system("pause");
	return 0;
}