/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: orderer/etcdraft/configuration.proto */

#ifndef PROTOBUF_C_orderer_2fetcdraft_2fconfiguration_2eproto__INCLUDED
#define PROTOBUF_C_orderer_2fetcdraft_2fconfiguration_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1002001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Etcdraft__Metadata Etcdraft__Metadata;
typedef struct _Etcdraft__Consenter Etcdraft__Consenter;
typedef struct _Etcdraft__Options Etcdraft__Options;
typedef struct _Etcdraft__RaftMetadata Etcdraft__RaftMetadata;
typedef struct _Etcdraft__RaftMetadata__ConsentersEntry Etcdraft__RaftMetadata__ConsentersEntry;


/* --- enums --- */


/* --- messages --- */

/*
 * Metadata is serialized and set as the value of ConsensusType.Metadata in
 * a channel configuration when the ConsensusType.Type is set "etcdraft".
 */
struct  _Etcdraft__Metadata
{
  ProtobufCMessage base;
  size_t n_consenters;
  Etcdraft__Consenter **consenters;
  Etcdraft__Options *options;
};
#define ETCDRAFT__METADATA__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&etcdraft__metadata__descriptor) \
    , 0,NULL, NULL }


/*
 * Consenter represents a consenting node (i.e. replica).
 */
struct  _Etcdraft__Consenter
{
  ProtobufCMessage base;
  char *host;
  protobuf_c_boolean has_port;
  uint32_t port;
  protobuf_c_boolean has_client_tls_cert;
  ProtobufCBinaryData client_tls_cert;
  protobuf_c_boolean has_server_tls_cert;
  ProtobufCBinaryData server_tls_cert;
};
#define ETCDRAFT__CONSENTER__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&etcdraft__consenter__descriptor) \
    , NULL, 0,0, 0,{0,NULL}, 0,{0,NULL} }


/*
 * Options to be specified for all the etcd/raft nodes. These can be modified on a
 * per-channel basis.
 */
struct  _Etcdraft__Options
{
  ProtobufCMessage base;
  /*
   * specified in miliseconds
   */
  protobuf_c_boolean has_tick_interval;
  uint64_t tick_interval;
  protobuf_c_boolean has_election_tick;
  uint32_t election_tick;
  protobuf_c_boolean has_heartbeat_tick;
  uint32_t heartbeat_tick;
  protobuf_c_boolean has_max_inflight_msgs;
  uint32_t max_inflight_msgs;
  protobuf_c_boolean has_max_size_per_msg;
  uint64_t max_size_per_msg;
  /*
   * take snapshot every n blocks
   */
  protobuf_c_boolean has_snapshot_interval;
  uint64_t snapshot_interval;
};
#define ETCDRAFT__OPTIONS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&etcdraft__options__descriptor) \
    , 0,0, 0,0, 0,0, 0,0, 0,0, 0,0 }


struct  _Etcdraft__RaftMetadata__ConsentersEntry
{
  ProtobufCMessage base;
  protobuf_c_boolean has_key;
  uint64_t key;
  Etcdraft__Consenter *value;
};
#define ETCDRAFT__RAFT_METADATA__CONSENTERS_ENTRY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&etcdraft__raft_metadata__consenters_entry__descriptor) \
    , 0,0, NULL }


/*
 * RaftMetadata stores data used by the Raft OSNs when
 * coordinating with each other, to be serialized into
 * block meta dta field and used after failres and restarts.
 */
struct  _Etcdraft__RaftMetadata
{
  ProtobufCMessage base;
  /*
   * Maintains a mapping between the cluster's OSNs
   * and their Raft IDs.
   */
  size_t n_consenters;
  Etcdraft__RaftMetadata__ConsentersEntry **consenters;
  /*
   * Carries the Raft ID value that will be assigned
   * to the next OSN that will join this cluster.
   */
  protobuf_c_boolean has_next_consenter_id;
  uint64_t next_consenter_id;
  /*
   * Raft cluster configurations count
   */
  protobuf_c_boolean has_conf_change_counts;
  uint64_t conf_change_counts;
  /*
   * Index of etcd/raft entry for current block.
   */
  protobuf_c_boolean has_raft_index;
  uint64_t raft_index;
};
#define ETCDRAFT__RAFT_METADATA__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&etcdraft__raft_metadata__descriptor) \
    , 0,NULL, 0,0, 0,0, 0,0 }


/* Etcdraft__Metadata methods */
void   etcdraft__metadata__init
                     (Etcdraft__Metadata         *message);
size_t etcdraft__metadata__get_packed_size
                     (const Etcdraft__Metadata   *message);
size_t etcdraft__metadata__pack
                     (const Etcdraft__Metadata   *message,
                      uint8_t             *out);
size_t etcdraft__metadata__pack_to_buffer
                     (const Etcdraft__Metadata   *message,
                      ProtobufCBuffer     *buffer);
Etcdraft__Metadata *
       etcdraft__metadata__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   etcdraft__metadata__free_unpacked
                     (Etcdraft__Metadata *message,
                      ProtobufCAllocator *allocator);
/* Etcdraft__Consenter methods */
void   etcdraft__consenter__init
                     (Etcdraft__Consenter         *message);
size_t etcdraft__consenter__get_packed_size
                     (const Etcdraft__Consenter   *message);
size_t etcdraft__consenter__pack
                     (const Etcdraft__Consenter   *message,
                      uint8_t             *out);
size_t etcdraft__consenter__pack_to_buffer
                     (const Etcdraft__Consenter   *message,
                      ProtobufCBuffer     *buffer);
Etcdraft__Consenter *
       etcdraft__consenter__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   etcdraft__consenter__free_unpacked
                     (Etcdraft__Consenter *message,
                      ProtobufCAllocator *allocator);
/* Etcdraft__Options methods */
void   etcdraft__options__init
                     (Etcdraft__Options         *message);
size_t etcdraft__options__get_packed_size
                     (const Etcdraft__Options   *message);
size_t etcdraft__options__pack
                     (const Etcdraft__Options   *message,
                      uint8_t             *out);
size_t etcdraft__options__pack_to_buffer
                     (const Etcdraft__Options   *message,
                      ProtobufCBuffer     *buffer);
Etcdraft__Options *
       etcdraft__options__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   etcdraft__options__free_unpacked
                     (Etcdraft__Options *message,
                      ProtobufCAllocator *allocator);
/* Etcdraft__RaftMetadata__ConsentersEntry methods */
void   etcdraft__raft_metadata__consenters_entry__init
                     (Etcdraft__RaftMetadata__ConsentersEntry         *message);
/* Etcdraft__RaftMetadata methods */
void   etcdraft__raft_metadata__init
                     (Etcdraft__RaftMetadata         *message);
size_t etcdraft__raft_metadata__get_packed_size
                     (const Etcdraft__RaftMetadata   *message);
size_t etcdraft__raft_metadata__pack
                     (const Etcdraft__RaftMetadata   *message,
                      uint8_t             *out);
size_t etcdraft__raft_metadata__pack_to_buffer
                     (const Etcdraft__RaftMetadata   *message,
                      ProtobufCBuffer     *buffer);
Etcdraft__RaftMetadata *
       etcdraft__raft_metadata__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   etcdraft__raft_metadata__free_unpacked
                     (Etcdraft__RaftMetadata *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Etcdraft__Metadata_Closure)
                 (const Etcdraft__Metadata *message,
                  void *closure_data);
typedef void (*Etcdraft__Consenter_Closure)
                 (const Etcdraft__Consenter *message,
                  void *closure_data);
typedef void (*Etcdraft__Options_Closure)
                 (const Etcdraft__Options *message,
                  void *closure_data);
typedef void (*Etcdraft__RaftMetadata__ConsentersEntry_Closure)
                 (const Etcdraft__RaftMetadata__ConsentersEntry *message,
                  void *closure_data);
typedef void (*Etcdraft__RaftMetadata_Closure)
                 (const Etcdraft__RaftMetadata *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor etcdraft__metadata__descriptor;
extern const ProtobufCMessageDescriptor etcdraft__consenter__descriptor;
extern const ProtobufCMessageDescriptor etcdraft__options__descriptor;
extern const ProtobufCMessageDescriptor etcdraft__raft_metadata__descriptor;
extern const ProtobufCMessageDescriptor etcdraft__raft_metadata__consenters_entry__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_orderer_2fetcdraft_2fconfiguration_2eproto__INCLUDED */