// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#include "test.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace protobuf_test_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_test_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_Point;
}  // namespace protobuf_test_2eproto
namespace liyee {
namespace proto {
class PointDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Point>
      _instance;
} _Point_default_instance_;
class test_protobufDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<test_protobuf>
      _instance;
} _test_protobuf_default_instance_;
}  // namespace proto
}  // namespace liyee
namespace protobuf_test_2eproto {
static void InitDefaultsPoint() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::liyee::proto::_Point_default_instance_;
    new (ptr) ::liyee::proto::Point();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::liyee::proto::Point::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Point =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsPoint}, {}};

static void InitDefaultstest_protobuf() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::liyee::proto::_test_protobuf_default_instance_;
    new (ptr) ::liyee::proto::test_protobuf();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::liyee::proto::test_protobuf::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_test_protobuf =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultstest_protobuf}, {
      &protobuf_test_2eproto::scc_info_Point.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Point.base);
  ::google::protobuf::internal::InitSCC(&scc_info_test_protobuf.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::liyee::proto::Point, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::liyee::proto::Point, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::liyee::proto::Point, x_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::liyee::proto::Point, y_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::liyee::proto::Point, z_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::liyee::proto::Point, roll_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::liyee::proto::Point, pitch_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::liyee::proto::Point, yaw_),
  0,
  1,
  2,
  3,
  4,
  5,
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::liyee::proto::test_protobuf, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::liyee::proto::test_protobuf, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::liyee::proto::test_protobuf, goal_),
  ~0u,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 11, sizeof(::liyee::proto::Point)},
  { 17, 23, sizeof(::liyee::proto::test_protobuf)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::liyee::proto::_Point_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::liyee::proto::_test_protobuf_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "test.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\ntest.proto\022\013liyee.proto\"R\n\005Point\022\t\n\001x\030"
      "\001 \001(\002\022\t\n\001y\030\002 \001(\002\022\t\n\001z\030\003 \001(\002\022\014\n\004roll\030\004 \001("
      "\002\022\r\n\005pitch\030\005 \001(\002\022\013\n\003yaw\030\006 \001(\002\"1\n\rtest_pr"
      "otobuf\022 \n\004goal\030\001 \003(\0132\022.liyee.proto.Point"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 160);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "test.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_test_2eproto
namespace liyee {
namespace proto {

// ===================================================================

void Point::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Point::kXFieldNumber;
const int Point::kYFieldNumber;
const int Point::kZFieldNumber;
const int Point::kRollFieldNumber;
const int Point::kPitchFieldNumber;
const int Point::kYawFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Point::Point()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_test_2eproto::scc_info_Point.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:liyee.proto.Point)
}
Point::Point(const Point& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&x_, &from.x_,
    static_cast<size_t>(reinterpret_cast<char*>(&yaw_) -
    reinterpret_cast<char*>(&x_)) + sizeof(yaw_));
  // @@protoc_insertion_point(copy_constructor:liyee.proto.Point)
}

void Point::SharedCtor() {
  ::memset(&x_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&yaw_) -
      reinterpret_cast<char*>(&x_)) + sizeof(yaw_));
}

Point::~Point() {
  // @@protoc_insertion_point(destructor:liyee.proto.Point)
  SharedDtor();
}

void Point::SharedDtor() {
}

void Point::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Point::descriptor() {
  ::protobuf_test_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_test_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Point& Point::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_test_2eproto::scc_info_Point.base);
  return *internal_default_instance();
}


void Point::Clear() {
// @@protoc_insertion_point(message_clear_start:liyee.proto.Point)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 63u) {
    ::memset(&x_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&yaw_) -
        reinterpret_cast<char*>(&x_)) + sizeof(yaw_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool Point::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:liyee.proto.Point)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional float x = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(13u /* 13 & 0xFF */)) {
          set_has_x();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &x_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional float y = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(21u /* 21 & 0xFF */)) {
          set_has_y();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &y_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional float z = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(29u /* 29 & 0xFF */)) {
          set_has_z();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &z_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional float roll = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(37u /* 37 & 0xFF */)) {
          set_has_roll();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &roll_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional float pitch = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(45u /* 45 & 0xFF */)) {
          set_has_pitch();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &pitch_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional float yaw = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(53u /* 53 & 0xFF */)) {
          set_has_yaw();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, &yaw_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:liyee.proto.Point)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:liyee.proto.Point)
  return false;
#undef DO_
}

void Point::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:liyee.proto.Point)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional float x = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(1, this->x(), output);
  }

  // optional float y = 2;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(2, this->y(), output);
  }

  // optional float z = 3;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(3, this->z(), output);
  }

  // optional float roll = 4;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(4, this->roll(), output);
  }

  // optional float pitch = 5;
  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(5, this->pitch(), output);
  }

  // optional float yaw = 6;
  if (cached_has_bits & 0x00000020u) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(6, this->yaw(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:liyee.proto.Point)
}

::google::protobuf::uint8* Point::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:liyee.proto.Point)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional float x = 1;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(1, this->x(), target);
  }

  // optional float y = 2;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(2, this->y(), target);
  }

  // optional float z = 3;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(3, this->z(), target);
  }

  // optional float roll = 4;
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(4, this->roll(), target);
  }

  // optional float pitch = 5;
  if (cached_has_bits & 0x00000010u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(5, this->pitch(), target);
  }

  // optional float yaw = 6;
  if (cached_has_bits & 0x00000020u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFloatToArray(6, this->yaw(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:liyee.proto.Point)
  return target;
}

size_t Point::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:liyee.proto.Point)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (_has_bits_[0 / 32] & 63u) {
    // optional float x = 1;
    if (has_x()) {
      total_size += 1 + 4;
    }

    // optional float y = 2;
    if (has_y()) {
      total_size += 1 + 4;
    }

    // optional float z = 3;
    if (has_z()) {
      total_size += 1 + 4;
    }

    // optional float roll = 4;
    if (has_roll()) {
      total_size += 1 + 4;
    }

    // optional float pitch = 5;
    if (has_pitch()) {
      total_size += 1 + 4;
    }

    // optional float yaw = 6;
    if (has_yaw()) {
      total_size += 1 + 4;
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Point::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:liyee.proto.Point)
  GOOGLE_DCHECK_NE(&from, this);
  const Point* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Point>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:liyee.proto.Point)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:liyee.proto.Point)
    MergeFrom(*source);
  }
}

void Point::MergeFrom(const Point& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:liyee.proto.Point)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 63u) {
    if (cached_has_bits & 0x00000001u) {
      x_ = from.x_;
    }
    if (cached_has_bits & 0x00000002u) {
      y_ = from.y_;
    }
    if (cached_has_bits & 0x00000004u) {
      z_ = from.z_;
    }
    if (cached_has_bits & 0x00000008u) {
      roll_ = from.roll_;
    }
    if (cached_has_bits & 0x00000010u) {
      pitch_ = from.pitch_;
    }
    if (cached_has_bits & 0x00000020u) {
      yaw_ = from.yaw_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void Point::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:liyee.proto.Point)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Point::CopyFrom(const Point& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:liyee.proto.Point)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Point::IsInitialized() const {
  return true;
}

void Point::Swap(Point* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Point::InternalSwap(Point* other) {
  using std::swap;
  swap(x_, other->x_);
  swap(y_, other->y_);
  swap(z_, other->z_);
  swap(roll_, other->roll_);
  swap(pitch_, other->pitch_);
  swap(yaw_, other->yaw_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Point::GetMetadata() const {
  protobuf_test_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_test_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void test_protobuf::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int test_protobuf::kGoalFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

test_protobuf::test_protobuf()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_test_2eproto::scc_info_test_protobuf.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:liyee.proto.test_protobuf)
}
test_protobuf::test_protobuf(const test_protobuf& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      goal_(from.goal_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:liyee.proto.test_protobuf)
}

void test_protobuf::SharedCtor() {
}

test_protobuf::~test_protobuf() {
  // @@protoc_insertion_point(destructor:liyee.proto.test_protobuf)
  SharedDtor();
}

void test_protobuf::SharedDtor() {
}

void test_protobuf::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* test_protobuf::descriptor() {
  ::protobuf_test_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_test_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const test_protobuf& test_protobuf::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_test_2eproto::scc_info_test_protobuf.base);
  return *internal_default_instance();
}


void test_protobuf::Clear() {
// @@protoc_insertion_point(message_clear_start:liyee.proto.test_protobuf)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  goal_.Clear();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool test_protobuf::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:liyee.proto.test_protobuf)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .liyee.proto.Point goal = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
                input, add_goal()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:liyee.proto.test_protobuf)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:liyee.proto.test_protobuf)
  return false;
#undef DO_
}

void test_protobuf::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:liyee.proto.test_protobuf)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .liyee.proto.Point goal = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->goal_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1,
      this->goal(static_cast<int>(i)),
      output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:liyee.proto.test_protobuf)
}

::google::protobuf::uint8* test_protobuf::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:liyee.proto.test_protobuf)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .liyee.proto.Point goal = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->goal_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->goal(static_cast<int>(i)), deterministic, target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:liyee.proto.test_protobuf)
  return target;
}

size_t test_protobuf::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:liyee.proto.test_protobuf)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // repeated .liyee.proto.Point goal = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->goal_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->goal(static_cast<int>(i)));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void test_protobuf::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:liyee.proto.test_protobuf)
  GOOGLE_DCHECK_NE(&from, this);
  const test_protobuf* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const test_protobuf>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:liyee.proto.test_protobuf)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:liyee.proto.test_protobuf)
    MergeFrom(*source);
  }
}

void test_protobuf::MergeFrom(const test_protobuf& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:liyee.proto.test_protobuf)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  goal_.MergeFrom(from.goal_);
}

void test_protobuf::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:liyee.proto.test_protobuf)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void test_protobuf::CopyFrom(const test_protobuf& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:liyee.proto.test_protobuf)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool test_protobuf::IsInitialized() const {
  return true;
}

void test_protobuf::Swap(test_protobuf* other) {
  if (other == this) return;
  InternalSwap(other);
}
void test_protobuf::InternalSwap(test_protobuf* other) {
  using std::swap;
  CastToBase(&goal_)->InternalSwap(CastToBase(&other->goal_));
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata test_protobuf::GetMetadata() const {
  protobuf_test_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_test_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace proto
}  // namespace liyee
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::liyee::proto::Point* Arena::CreateMaybeMessage< ::liyee::proto::Point >(Arena* arena) {
  return Arena::CreateInternal< ::liyee::proto::Point >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::liyee::proto::test_protobuf* Arena::CreateMaybeMessage< ::liyee::proto::test_protobuf >(Arena* arena) {
  return Arena::CreateInternal< ::liyee::proto::test_protobuf >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
