#ifndef CX_OBJ_H
#define CX_OBJ_H

#include <string>
#include <memory>
#include <list>
#include <vector>
#include "CX_Export.h"
#include "CX_Type.h"
#include <iostream>

class CX_Buffer
{
public:
  CX_Buffer(const size_t& size = BUFFER_SIZE);
  ~CX_Buffer() = default;

  inline size_t GetSize() const;
  inline size_t GetFree() const;
  size_t GetData(char*& data, const size_t& size);
  friend std::ostream& operator<<(std::ostream& stream, const CX_Buffer& buf);

protected:
  size_t Free;
  char* Cursor;
  std::shared_ptr<std::vector<char>> Data;
  static size_t BUFFER_SIZE;
};

size_t CX_Buffer::GetSize() const
{
  return Data->size();
}
size_t CX_Buffer::GetFree() const
{
  return Free;
}

class CORE_EXPORT CX_Obj
{
protected:
  std::string Name;
  std::list<std::shared_ptr<CX_Buffer>> BufferList;
  std::shared_ptr<CX_Buffer> AddBuffer();
  size_t VertexCount{0};

  void BuildIndex();
  void AddData(const std::string& str);

public:
  CX_Obj(const std::string& name);
  ~CX_Obj();

  void AddData(const CX_Vector3f& vector, const CX_Vector3f& derivative);
};

#endif // !CX_OBJ_H
