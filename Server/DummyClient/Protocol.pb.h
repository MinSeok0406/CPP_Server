// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Protocol.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Protocol_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Protocol_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "Enum.pb.h"
#include "Struct.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Protocol_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Protocol_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[6]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Protocol_2eproto;
namespace Protocol {
class C_CHAT;
struct C_CHATDefaultTypeInternal;
extern C_CHATDefaultTypeInternal _C_CHAT_default_instance_;
class C_ENTER_GAME;
struct C_ENTER_GAMEDefaultTypeInternal;
extern C_ENTER_GAMEDefaultTypeInternal _C_ENTER_GAME_default_instance_;
class C_LOGIN;
struct C_LOGINDefaultTypeInternal;
extern C_LOGINDefaultTypeInternal _C_LOGIN_default_instance_;
class S_CHAT;
struct S_CHATDefaultTypeInternal;
extern S_CHATDefaultTypeInternal _S_CHAT_default_instance_;
class S_ENTER_GAME;
struct S_ENTER_GAMEDefaultTypeInternal;
extern S_ENTER_GAMEDefaultTypeInternal _S_ENTER_GAME_default_instance_;
class S_LOGIN;
struct S_LOGINDefaultTypeInternal;
extern S_LOGINDefaultTypeInternal _S_LOGIN_default_instance_;
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> ::Protocol::C_CHAT* Arena::CreateMaybeMessage<::Protocol::C_CHAT>(Arena*);
template<> ::Protocol::C_ENTER_GAME* Arena::CreateMaybeMessage<::Protocol::C_ENTER_GAME>(Arena*);
template<> ::Protocol::C_LOGIN* Arena::CreateMaybeMessage<::Protocol::C_LOGIN>(Arena*);
template<> ::Protocol::S_CHAT* Arena::CreateMaybeMessage<::Protocol::S_CHAT>(Arena*);
template<> ::Protocol::S_ENTER_GAME* Arena::CreateMaybeMessage<::Protocol::S_ENTER_GAME>(Arena*);
template<> ::Protocol::S_LOGIN* Arena::CreateMaybeMessage<::Protocol::S_LOGIN>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Protocol {

// ===================================================================

class C_LOGIN final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.C_LOGIN) */ {
 public:
  inline C_LOGIN() : C_LOGIN(nullptr) {}
  ~C_LOGIN() override;
  explicit constexpr C_LOGIN(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  C_LOGIN(const C_LOGIN& from);
  C_LOGIN(C_LOGIN&& from) noexcept
    : C_LOGIN() {
    *this = ::std::move(from);
  }

  inline C_LOGIN& operator=(const C_LOGIN& from) {
    CopyFrom(from);
    return *this;
  }
  inline C_LOGIN& operator=(C_LOGIN&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const C_LOGIN& default_instance() {
    return *internal_default_instance();
  }
  static inline const C_LOGIN* internal_default_instance() {
    return reinterpret_cast<const C_LOGIN*>(
               &_C_LOGIN_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(C_LOGIN& a, C_LOGIN& b) {
    a.Swap(&b);
  }
  inline void Swap(C_LOGIN* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(C_LOGIN* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline C_LOGIN* New() const final {
    return new C_LOGIN();
  }

  C_LOGIN* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<C_LOGIN>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const C_LOGIN& from);
  void MergeFrom(const C_LOGIN& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(C_LOGIN* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.C_LOGIN";
  }
  protected:
  explicit C_LOGIN(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:Protocol.C_LOGIN)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Protocol_2eproto;
};
// -------------------------------------------------------------------

class S_LOGIN final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.S_LOGIN) */ {
 public:
  inline S_LOGIN() : S_LOGIN(nullptr) {}
  ~S_LOGIN() override;
  explicit constexpr S_LOGIN(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  S_LOGIN(const S_LOGIN& from);
  S_LOGIN(S_LOGIN&& from) noexcept
    : S_LOGIN() {
    *this = ::std::move(from);
  }

  inline S_LOGIN& operator=(const S_LOGIN& from) {
    CopyFrom(from);
    return *this;
  }
  inline S_LOGIN& operator=(S_LOGIN&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const S_LOGIN& default_instance() {
    return *internal_default_instance();
  }
  static inline const S_LOGIN* internal_default_instance() {
    return reinterpret_cast<const S_LOGIN*>(
               &_S_LOGIN_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(S_LOGIN& a, S_LOGIN& b) {
    a.Swap(&b);
  }
  inline void Swap(S_LOGIN* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(S_LOGIN* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline S_LOGIN* New() const final {
    return new S_LOGIN();
  }

  S_LOGIN* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<S_LOGIN>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const S_LOGIN& from);
  void MergeFrom(const S_LOGIN& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(S_LOGIN* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.S_LOGIN";
  }
  protected:
  explicit S_LOGIN(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPlayerFieldNumber = 2,
    kSuccessFieldNumber = 1,
  };
  // repeated .Protocol.Player player = 2;
  int player_size() const;
  private:
  int _internal_player_size() const;
  public:
  void clear_player();
  ::Protocol::Player* mutable_player(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Protocol::Player >*
      mutable_player();
  private:
  const ::Protocol::Player& _internal_player(int index) const;
  ::Protocol::Player* _internal_add_player();
  public:
  const ::Protocol::Player& player(int index) const;
  ::Protocol::Player* add_player();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Protocol::Player >&
      player() const;

  // bool success = 1;
  void clear_success();
  bool success() const;
  void set_success(bool value);
  private:
  bool _internal_success() const;
  void _internal_set_success(bool value);
  public:

  // @@protoc_insertion_point(class_scope:Protocol.S_LOGIN)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Protocol::Player > player_;
  bool success_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Protocol_2eproto;
};
// -------------------------------------------------------------------

class C_ENTER_GAME final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.C_ENTER_GAME) */ {
 public:
  inline C_ENTER_GAME() : C_ENTER_GAME(nullptr) {}
  ~C_ENTER_GAME() override;
  explicit constexpr C_ENTER_GAME(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  C_ENTER_GAME(const C_ENTER_GAME& from);
  C_ENTER_GAME(C_ENTER_GAME&& from) noexcept
    : C_ENTER_GAME() {
    *this = ::std::move(from);
  }

  inline C_ENTER_GAME& operator=(const C_ENTER_GAME& from) {
    CopyFrom(from);
    return *this;
  }
  inline C_ENTER_GAME& operator=(C_ENTER_GAME&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const C_ENTER_GAME& default_instance() {
    return *internal_default_instance();
  }
  static inline const C_ENTER_GAME* internal_default_instance() {
    return reinterpret_cast<const C_ENTER_GAME*>(
               &_C_ENTER_GAME_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(C_ENTER_GAME& a, C_ENTER_GAME& b) {
    a.Swap(&b);
  }
  inline void Swap(C_ENTER_GAME* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(C_ENTER_GAME* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline C_ENTER_GAME* New() const final {
    return new C_ENTER_GAME();
  }

  C_ENTER_GAME* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<C_ENTER_GAME>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const C_ENTER_GAME& from);
  void MergeFrom(const C_ENTER_GAME& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(C_ENTER_GAME* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.C_ENTER_GAME";
  }
  protected:
  explicit C_ENTER_GAME(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPlayerIndexFieldNumber = 1,
  };
  // uint64 playerIndex = 1;
  void clear_playerindex();
  ::PROTOBUF_NAMESPACE_ID::uint64 playerindex() const;
  void set_playerindex(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_playerindex() const;
  void _internal_set_playerindex(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // @@protoc_insertion_point(class_scope:Protocol.C_ENTER_GAME)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::uint64 playerindex_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Protocol_2eproto;
};
// -------------------------------------------------------------------

class S_ENTER_GAME final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.S_ENTER_GAME) */ {
 public:
  inline S_ENTER_GAME() : S_ENTER_GAME(nullptr) {}
  ~S_ENTER_GAME() override;
  explicit constexpr S_ENTER_GAME(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  S_ENTER_GAME(const S_ENTER_GAME& from);
  S_ENTER_GAME(S_ENTER_GAME&& from) noexcept
    : S_ENTER_GAME() {
    *this = ::std::move(from);
  }

  inline S_ENTER_GAME& operator=(const S_ENTER_GAME& from) {
    CopyFrom(from);
    return *this;
  }
  inline S_ENTER_GAME& operator=(S_ENTER_GAME&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const S_ENTER_GAME& default_instance() {
    return *internal_default_instance();
  }
  static inline const S_ENTER_GAME* internal_default_instance() {
    return reinterpret_cast<const S_ENTER_GAME*>(
               &_S_ENTER_GAME_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  friend void swap(S_ENTER_GAME& a, S_ENTER_GAME& b) {
    a.Swap(&b);
  }
  inline void Swap(S_ENTER_GAME* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(S_ENTER_GAME* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline S_ENTER_GAME* New() const final {
    return new S_ENTER_GAME();
  }

  S_ENTER_GAME* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<S_ENTER_GAME>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const S_ENTER_GAME& from);
  void MergeFrom(const S_ENTER_GAME& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(S_ENTER_GAME* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.S_ENTER_GAME";
  }
  protected:
  explicit S_ENTER_GAME(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSuccessFieldNumber = 1,
  };
  // bool success = 1;
  void clear_success();
  bool success() const;
  void set_success(bool value);
  private:
  bool _internal_success() const;
  void _internal_set_success(bool value);
  public:

  // @@protoc_insertion_point(class_scope:Protocol.S_ENTER_GAME)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  bool success_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Protocol_2eproto;
};
// -------------------------------------------------------------------

class C_CHAT final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.C_CHAT) */ {
 public:
  inline C_CHAT() : C_CHAT(nullptr) {}
  ~C_CHAT() override;
  explicit constexpr C_CHAT(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  C_CHAT(const C_CHAT& from);
  C_CHAT(C_CHAT&& from) noexcept
    : C_CHAT() {
    *this = ::std::move(from);
  }

  inline C_CHAT& operator=(const C_CHAT& from) {
    CopyFrom(from);
    return *this;
  }
  inline C_CHAT& operator=(C_CHAT&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const C_CHAT& default_instance() {
    return *internal_default_instance();
  }
  static inline const C_CHAT* internal_default_instance() {
    return reinterpret_cast<const C_CHAT*>(
               &_C_CHAT_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    4;

  friend void swap(C_CHAT& a, C_CHAT& b) {
    a.Swap(&b);
  }
  inline void Swap(C_CHAT* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(C_CHAT* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline C_CHAT* New() const final {
    return new C_CHAT();
  }

  C_CHAT* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<C_CHAT>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const C_CHAT& from);
  void MergeFrom(const C_CHAT& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(C_CHAT* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.C_CHAT";
  }
  protected:
  explicit C_CHAT(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMsgFieldNumber = 1,
  };
  // string msg = 1;
  void clear_msg();
  const std::string& msg() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_msg(ArgT0&& arg0, ArgT... args);
  std::string* mutable_msg();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_msg();
  void set_allocated_msg(std::string* msg);
  private:
  const std::string& _internal_msg() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_msg(const std::string& value);
  std::string* _internal_mutable_msg();
  public:

  // @@protoc_insertion_point(class_scope:Protocol.C_CHAT)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr msg_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Protocol_2eproto;
};
// -------------------------------------------------------------------

class S_CHAT final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.S_CHAT) */ {
 public:
  inline S_CHAT() : S_CHAT(nullptr) {}
  ~S_CHAT() override;
  explicit constexpr S_CHAT(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  S_CHAT(const S_CHAT& from);
  S_CHAT(S_CHAT&& from) noexcept
    : S_CHAT() {
    *this = ::std::move(from);
  }

  inline S_CHAT& operator=(const S_CHAT& from) {
    CopyFrom(from);
    return *this;
  }
  inline S_CHAT& operator=(S_CHAT&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const S_CHAT& default_instance() {
    return *internal_default_instance();
  }
  static inline const S_CHAT* internal_default_instance() {
    return reinterpret_cast<const S_CHAT*>(
               &_S_CHAT_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    5;

  friend void swap(S_CHAT& a, S_CHAT& b) {
    a.Swap(&b);
  }
  inline void Swap(S_CHAT* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(S_CHAT* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline S_CHAT* New() const final {
    return new S_CHAT();
  }

  S_CHAT* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<S_CHAT>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const S_CHAT& from);
  void MergeFrom(const S_CHAT& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(S_CHAT* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.S_CHAT";
  }
  protected:
  explicit S_CHAT(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kMsgFieldNumber = 2,
    kPlayerIdFieldNumber = 1,
  };
  // string msg = 2;
  void clear_msg();
  const std::string& msg() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_msg(ArgT0&& arg0, ArgT... args);
  std::string* mutable_msg();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_msg();
  void set_allocated_msg(std::string* msg);
  private:
  const std::string& _internal_msg() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_msg(const std::string& value);
  std::string* _internal_mutable_msg();
  public:

  // uint64 playerId = 1;
  void clear_playerid();
  ::PROTOBUF_NAMESPACE_ID::uint64 playerid() const;
  void set_playerid(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_playerid() const;
  void _internal_set_playerid(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // @@protoc_insertion_point(class_scope:Protocol.S_CHAT)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr msg_;
  ::PROTOBUF_NAMESPACE_ID::uint64 playerid_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Protocol_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// C_LOGIN

// -------------------------------------------------------------------

// S_LOGIN

// bool success = 1;
inline void S_LOGIN::clear_success() {
  success_ = false;
}
inline bool S_LOGIN::_internal_success() const {
  return success_;
}
inline bool S_LOGIN::success() const {
  // @@protoc_insertion_point(field_get:Protocol.S_LOGIN.success)
  return _internal_success();
}
inline void S_LOGIN::_internal_set_success(bool value) {
  
  success_ = value;
}
inline void S_LOGIN::set_success(bool value) {
  _internal_set_success(value);
  // @@protoc_insertion_point(field_set:Protocol.S_LOGIN.success)
}

// repeated .Protocol.Player player = 2;
inline int S_LOGIN::_internal_player_size() const {
  return player_.size();
}
inline int S_LOGIN::player_size() const {
  return _internal_player_size();
}
inline ::Protocol::Player* S_LOGIN::mutable_player(int index) {
  // @@protoc_insertion_point(field_mutable:Protocol.S_LOGIN.player)
  return player_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Protocol::Player >*
S_LOGIN::mutable_player() {
  // @@protoc_insertion_point(field_mutable_list:Protocol.S_LOGIN.player)
  return &player_;
}
inline const ::Protocol::Player& S_LOGIN::_internal_player(int index) const {
  return player_.Get(index);
}
inline const ::Protocol::Player& S_LOGIN::player(int index) const {
  // @@protoc_insertion_point(field_get:Protocol.S_LOGIN.player)
  return _internal_player(index);
}
inline ::Protocol::Player* S_LOGIN::_internal_add_player() {
  return player_.Add();
}
inline ::Protocol::Player* S_LOGIN::add_player() {
  // @@protoc_insertion_point(field_add:Protocol.S_LOGIN.player)
  return _internal_add_player();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::Protocol::Player >&
S_LOGIN::player() const {
  // @@protoc_insertion_point(field_list:Protocol.S_LOGIN.player)
  return player_;
}

// -------------------------------------------------------------------

// C_ENTER_GAME

// uint64 playerIndex = 1;
inline void C_ENTER_GAME::clear_playerindex() {
  playerindex_ = uint64_t{0u};
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 C_ENTER_GAME::_internal_playerindex() const {
  return playerindex_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 C_ENTER_GAME::playerindex() const {
  // @@protoc_insertion_point(field_get:Protocol.C_ENTER_GAME.playerIndex)
  return _internal_playerindex();
}
inline void C_ENTER_GAME::_internal_set_playerindex(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  playerindex_ = value;
}
inline void C_ENTER_GAME::set_playerindex(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_playerindex(value);
  // @@protoc_insertion_point(field_set:Protocol.C_ENTER_GAME.playerIndex)
}

// -------------------------------------------------------------------

// S_ENTER_GAME

// bool success = 1;
inline void S_ENTER_GAME::clear_success() {
  success_ = false;
}
inline bool S_ENTER_GAME::_internal_success() const {
  return success_;
}
inline bool S_ENTER_GAME::success() const {
  // @@protoc_insertion_point(field_get:Protocol.S_ENTER_GAME.success)
  return _internal_success();
}
inline void S_ENTER_GAME::_internal_set_success(bool value) {
  
  success_ = value;
}
inline void S_ENTER_GAME::set_success(bool value) {
  _internal_set_success(value);
  // @@protoc_insertion_point(field_set:Protocol.S_ENTER_GAME.success)
}

// -------------------------------------------------------------------

// C_CHAT

// string msg = 1;
inline void C_CHAT::clear_msg() {
  msg_.ClearToEmpty();
}
inline const std::string& C_CHAT::msg() const {
  // @@protoc_insertion_point(field_get:Protocol.C_CHAT.msg)
  return _internal_msg();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void C_CHAT::set_msg(ArgT0&& arg0, ArgT... args) {
 
 msg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Protocol.C_CHAT.msg)
}
inline std::string* C_CHAT::mutable_msg() {
  // @@protoc_insertion_point(field_mutable:Protocol.C_CHAT.msg)
  return _internal_mutable_msg();
}
inline const std::string& C_CHAT::_internal_msg() const {
  return msg_.Get();
}
inline void C_CHAT::_internal_set_msg(const std::string& value) {
  
  msg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* C_CHAT::_internal_mutable_msg() {
  
  return msg_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* C_CHAT::release_msg() {
  // @@protoc_insertion_point(field_release:Protocol.C_CHAT.msg)
  return msg_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void C_CHAT::set_allocated_msg(std::string* msg) {
  if (msg != nullptr) {
    
  } else {
    
  }
  msg_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), msg,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Protocol.C_CHAT.msg)
}

// -------------------------------------------------------------------

// S_CHAT

// uint64 playerId = 1;
inline void S_CHAT::clear_playerid() {
  playerid_ = uint64_t{0u};
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 S_CHAT::_internal_playerid() const {
  return playerid_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 S_CHAT::playerid() const {
  // @@protoc_insertion_point(field_get:Protocol.S_CHAT.playerId)
  return _internal_playerid();
}
inline void S_CHAT::_internal_set_playerid(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  playerid_ = value;
}
inline void S_CHAT::set_playerid(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_playerid(value);
  // @@protoc_insertion_point(field_set:Protocol.S_CHAT.playerId)
}

// string msg = 2;
inline void S_CHAT::clear_msg() {
  msg_.ClearToEmpty();
}
inline const std::string& S_CHAT::msg() const {
  // @@protoc_insertion_point(field_get:Protocol.S_CHAT.msg)
  return _internal_msg();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void S_CHAT::set_msg(ArgT0&& arg0, ArgT... args) {
 
 msg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Protocol.S_CHAT.msg)
}
inline std::string* S_CHAT::mutable_msg() {
  // @@protoc_insertion_point(field_mutable:Protocol.S_CHAT.msg)
  return _internal_mutable_msg();
}
inline const std::string& S_CHAT::_internal_msg() const {
  return msg_.Get();
}
inline void S_CHAT::_internal_set_msg(const std::string& value) {
  
  msg_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* S_CHAT::_internal_mutable_msg() {
  
  return msg_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* S_CHAT::release_msg() {
  // @@protoc_insertion_point(field_release:Protocol.S_CHAT.msg)
  return msg_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void S_CHAT::set_allocated_msg(std::string* msg) {
  if (msg != nullptr) {
    
  } else {
    
  }
  msg_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), msg,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Protocol.S_CHAT.msg)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Protocol_2eproto
