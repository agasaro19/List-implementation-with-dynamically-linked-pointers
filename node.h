#ifndef NODE_H
#define NODE_H
class Node
{
private:
	Node * flink;
	Node * blink;
	int payload;
public:
	Node();
	~Node();
	void SetFlink(Node * np);
	Node * GetFlink();
	void SetBlink(Node * np);
	Node * GetBlink();
	void SetPayload(int payload);
	int GetPayload();
};
#endif
