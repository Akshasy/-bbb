/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: chainmaker_network.proto */

#ifndef PROTOBUF_C_chainmaker_5fnetwork_2eproto__INCLUDED
#define PROTOBUF_C_chainmaker_5fnetwork_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003003 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _Common__ChainmakerNetworks Common__ChainmakerNetworks;
typedef struct _Common__ChainmakerNetworkData Common__ChainmakerNetworkData;


/* --- enums --- */


/* --- messages --- */

struct  _Common__ChainmakerNetworks
{
  ProtobufCMessage base;
  uint32_t networknum;
  Common__ChainmakerNetworkData *networks;
};
#define COMMON__CHAINMAKER_NETWORKS__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__chainmaker_networks__descriptor) \
    , 0, NULL }


struct  _Common__ChainmakerNetworkData
{
  ProtobufCMessage base;
  uint32_t index;
  uint32_t client_member_type;
  char *client_sign_cert_content;
  char *node_url;
  char *host_name;
  char *chain_id;
  char *org_id;
  char *ca_tls_cert_content;
  char *client_tls_cert_content;
  char *client_tls_privkey_data;
};
#define COMMON__CHAINMAKER_NETWORK_DATA__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__chainmaker_network_data__descriptor) \
    , 0, 0, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string }


/* Common__ChainmakerNetworks methods */
void   common__chainmaker_networks__init
                     (Common__ChainmakerNetworks         *message);
size_t common__chainmaker_networks__get_packed_size
                     (const Common__ChainmakerNetworks   *message);
size_t common__chainmaker_networks__pack
                     (const Common__ChainmakerNetworks   *message,
                      uint8_t             *out);
size_t common__chainmaker_networks__pack_to_buffer
                     (const Common__ChainmakerNetworks   *message,
                      ProtobufCBuffer     *buffer);
Common__ChainmakerNetworks *
       common__chainmaker_networks__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__chainmaker_networks__free_unpacked
                     (Common__ChainmakerNetworks *message,
                      ProtobufCAllocator *allocator);
/* Common__ChainmakerNetworkData methods */
void   common__chainmaker_network_data__init
                     (Common__ChainmakerNetworkData         *message);
size_t common__chainmaker_network_data__get_packed_size
                     (const Common__ChainmakerNetworkData   *message);
size_t common__chainmaker_network_data__pack
                     (const Common__ChainmakerNetworkData   *message,
                      uint8_t             *out);
size_t common__chainmaker_network_data__pack_to_buffer
                     (const Common__ChainmakerNetworkData   *message,
                      ProtobufCBuffer     *buffer);
Common__ChainmakerNetworkData *
       common__chainmaker_network_data__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__chainmaker_network_data__free_unpacked
                     (Common__ChainmakerNetworkData *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Common__ChainmakerNetworks_Closure)
                 (const Common__ChainmakerNetworks *message,
                  void *closure_data);
typedef void (*Common__ChainmakerNetworkData_Closure)
                 (const Common__ChainmakerNetworkData *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor common__chainmaker_networks__descriptor;
extern const ProtobufCMessageDescriptor common__chainmaker_network_data__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_chainmaker_5fnetwork_2eproto__INCLUDED */
