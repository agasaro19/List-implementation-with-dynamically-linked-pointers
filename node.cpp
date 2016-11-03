#include<iostream>
#include"Node.h"

Node::Node(){
	flink=blink= 0;
	payload=0;}
Node::~Node(){}
void Node::SetFlink(Node * np){
	flink=np;}
Node * Node::GetFlink(){
	return flink;}
void Node::SetBlink(Node * np){
	blink=np;}
Node * Node::GetBlink(){
	return blink;}
void Node::SetPayload(int payload){
	this->payload=payload;};
int Node::GetPayload(){
	return payload;}