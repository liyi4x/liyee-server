#ifndef _IO_H_
#define _IO_H_

#include "log/log.h"
#include <string>
#include <fcntl.h>
#include <google/protobuf/message.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/text_format.h>

namespace liyee
{
const int kProtoReadBytesLimit = INT_MAX;  // Max size of 2 GB minus 1 byte.

template<class T>
inline bool ReadProtoFromTextFile(const std::string& fileName, T* proto)
{
  bool res = false;
  auto logger = LogMng::get()->GetLogger();

  int fd = open(fileName.c_str(), O_RDONLY);
  if(fd == -1)
  {
  int fd2 = creat(fileName.c_str(), O_CREAT);

    LIYEE_LOG_ERROR(logger) << "File not found: " << fileName << std::endl;
    res = false;
  }
  else
  {
    google::protobuf::io::FileInputStream fileIn(fd);
    res = google::protobuf::TextFormat::Parse(&fileIn, proto);
  }

  close(fd);
  return res;
}

template<class T>
inline bool ReadProtoFromBinaryFile(const std::string& fileName, T *proto) {
  using google::protobuf::io::FileInputStream;
  using google::protobuf::io::FileOutputStream;
  using google::protobuf::io::ZeroCopyInputStream;
  using google::protobuf::io::CodedInputStream;
  using google::protobuf::io::ZeroCopyOutputStream;
  using google::protobuf::io::CodedOutputStream;
  using google::protobuf::Message;

  auto logger = LogMng::get()->GetLogger();

  int fd = open(fileName.c_str(), O_RDONLY);
  if (fd == -1) {
    proto = NULL;
    LIYEE_LOG_ERROR(logger) << "File not found: " << fileName << std::endl;
  }

  ZeroCopyInputStream *raw_input = new FileInputStream(fd);
  CodedInputStream *coded_input = new CodedInputStream(raw_input);
  coded_input->SetTotalBytesLimit(kProtoReadBytesLimit, 536870912);

  bool success = proto->ParseFromCodedStream(coded_input);

  delete coded_input;
  delete raw_input;
  close(fd);
  return success;
}

}//!namespace

#endif // !_IO_H_
