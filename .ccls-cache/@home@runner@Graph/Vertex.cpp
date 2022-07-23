#include "Vertex.h"
Vertex::Vertex(){
	m_id=0;
	m_value =0;
}
Vertex::Vertex(int id, int value){
  m_id = id;
  m_value = value;
}; //constructor
Vertex::Vertex(const Vertex& old_copy){
      m_id = old_copy.m_id;
      m_value = old_copy.m_value; 
    }; //copy constructor


    //getters/setters
		int Vertex::get_id()const{
      return m_id;
    }; 
		int Vertex::get_value(){
      return m_value;
    };

		void Vertex::set_id(int id){
      m_id = id;
    };
		void Vertex::set_value(int value){
      m_value = value;
    };