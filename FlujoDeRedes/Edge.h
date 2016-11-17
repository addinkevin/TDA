
#ifndef EDGE_H_
#define EDGE_H_

class Edge {
private:
	int source;
	int dest;
    int capacity;

public:
	Edge(int source, int dest, int capacity);
	int getSource();
	int getDest();

    int getCapacity();
	void setCapacity(int capacity);

	~Edge();
};

#endif /* EDGE_H_ */
