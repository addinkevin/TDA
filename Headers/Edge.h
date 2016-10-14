
#ifndef EDGE_H_
#define EDGE_H_

class Edge {
private:
	int source;
	int dest;
	double weight;
public:
	Edge(int source, int dest, double weight);
	int getSource();
	int getDest();
	double getWeight();


	~Edge();
};

#endif /* EDGE_H_ */
