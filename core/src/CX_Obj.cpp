#include "CX_Obj.h"
#include <format>
#include <fstream>

size_t CX_Buffer::BUFFER_SIZE{4096};

CX_Buffer::CX_Buffer(const size_t& size)
    : Free(size), Data(std::make_shared<std::vector<char>>(size))
{
  Cursor = Data->data();
}

std::ostream& operator<<(std::ostream& stream, const CX_Buffer& buf)
{
  stream.write(buf.Data->data(), buf.Data->size() - buf.Free);
  return stream;
}

CX_Obj::CX_Obj(const std::string& name)
    : Name(name)
{
}

CX_Obj::~CX_Obj()
{
  BuildIndex();

  std::ofstream stream;
  auto path = std::format("Models/{:s}.obj", Name);
  stream.open(path);
  stream << "mtllib untitled.mtl" << std::endl;

  for (auto& buf : BufferList)
  {
    stream << (*buf);
  }
  stream.close();
}

size_t CX_Buffer::GetData(char*& data, const size_t& size)
{
  data = Cursor;

  size_t result = (size >= Free) ? Free : size;
  Cursor += result;
  Free -= result;

  return result;
}

std::shared_ptr<CX_Buffer> CX_Obj::AddBuffer()
{
  auto buffer = std::make_shared<CX_Buffer>();
  BufferList.push_back(buffer);
  return buffer;
}

void CX_Obj::AddData(const std::string& str_data)
{
  std::shared_ptr<CX_Buffer> buffer;
  if (BufferList.size() > 0)
  {
    buffer = *BufferList.begin();
  }
  else
  {
    buffer = std::move(AddBuffer());
  }

  auto str_size = str_data.size();
  size_t offset{0};
  do
  {
    if (buffer->GetFree() <= 0)
    {
      buffer = AddBuffer();
    }

    char* data{nullptr};
    auto data_size = buffer->GetData(data, str_size);

    std::memcpy(data, str_data.c_str() + offset, data_size);

    offset = data_size;
    str_size -= data_size;
  } while (str_size > 0);
}

void CX_Obj::AddData(const CX_Vector3f& vector, const CX_Vector3f& derivative)
{
  auto s1 = vector.GetString();
  auto s2 = derivative.GetString();

  auto str_data = std::format("v {}\nv {}\n", s1, s2);
  AddData(str_data);

  VertexCount += 2;
}

void CX_Obj::BuildIndex()
{
  AddData("l 1 2\n");
  for (size_t i2 = 3; i2 <= VertexCount; i2 += 2)
  {
    auto i1 = i2 - 2;
    auto i3 = i2 + 1;
    auto str_data = std::format("l {} {} {} {}\n", i1, i2, i2, i3);
    AddData(str_data);
  }
}
