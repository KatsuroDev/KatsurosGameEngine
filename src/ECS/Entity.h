#ifndef ENTITY_H
#define ENTITY_H


class Entity
{
public:
  Entity();
  void AddComponent();
  void GetComponent();

private:
  const char* name;
  // Map this instead ? Give the name of the component itself and the component pointer;
  Component* m_ComponentList[];
};

#endif
