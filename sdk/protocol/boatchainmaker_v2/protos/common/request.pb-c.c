/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: common/request.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "common/request.pb-c.h"
void   common__tx_request__init
                     (Common__TxRequest         *message)
{
  static const Common__TxRequest init_value = COMMON__TX_REQUEST__INIT;
  *message = init_value;
}
size_t common__tx_request__get_packed_size
                     (const Common__TxRequest *message)
{
  assert(message->base.descriptor == &common__tx_request__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t common__tx_request__pack
                     (const Common__TxRequest *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &common__tx_request__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t common__tx_request__pack_to_buffer
                     (const Common__TxRequest *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &common__tx_request__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Common__TxRequest *
       common__tx_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Common__TxRequest *)
     protobuf_c_message_unpack (&common__tx_request__descriptor,
                                allocator, len, data);
}
void   common__tx_request__free_unpacked
                     (Common__TxRequest *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &common__tx_request__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   common__raw_tx_request__init
                     (Common__RawTxRequest         *message)
{
  static const Common__RawTxRequest init_value = COMMON__RAW_TX_REQUEST__INIT;
  *message = init_value;
}
size_t common__raw_tx_request__get_packed_size
                     (const Common__RawTxRequest *message)
{
  assert(message->base.descriptor == &common__raw_tx_request__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t common__raw_tx_request__pack
                     (const Common__RawTxRequest *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &common__raw_tx_request__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t common__raw_tx_request__pack_to_buffer
                     (const Common__RawTxRequest *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &common__raw_tx_request__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Common__RawTxRequest *
       common__raw_tx_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Common__RawTxRequest *)
     protobuf_c_message_unpack (&common__raw_tx_request__descriptor,
                                allocator, len, data);
}
void   common__raw_tx_request__free_unpacked
                     (Common__RawTxRequest *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &common__raw_tx_request__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   common__chainmaker_payload__init
                     (Common__ChainmakerPayload         *message)
{
  static const Common__ChainmakerPayload init_value = COMMON__CHAINMAKER_PAYLOAD__INIT;
  *message = init_value;
}
size_t common__chainmaker_payload__get_packed_size
                     (const Common__ChainmakerPayload *message)
{
  assert(message->base.descriptor == &common__chainmaker_payload__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t common__chainmaker_payload__pack
                     (const Common__ChainmakerPayload *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &common__chainmaker_payload__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t common__chainmaker_payload__pack_to_buffer
                     (const Common__ChainmakerPayload *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &common__chainmaker_payload__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Common__ChainmakerPayload *
       common__chainmaker_payload__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Common__ChainmakerPayload *)
     protobuf_c_message_unpack (&common__chainmaker_payload__descriptor,
                                allocator, len, data);
}
void   common__chainmaker_payload__free_unpacked
                     (Common__ChainmakerPayload *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &common__chainmaker_payload__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   common__endorsement_entry__init
                     (Common__EndorsementEntry         *message)
{
  static const Common__EndorsementEntry init_value = COMMON__ENDORSEMENT_ENTRY__INIT;
  *message = init_value;
}
size_t common__endorsement_entry__get_packed_size
                     (const Common__EndorsementEntry *message)
{
  assert(message->base.descriptor == &common__endorsement_entry__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t common__endorsement_entry__pack
                     (const Common__EndorsementEntry *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &common__endorsement_entry__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t common__endorsement_entry__pack_to_buffer
                     (const Common__EndorsementEntry *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &common__endorsement_entry__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Common__EndorsementEntry *
       common__endorsement_entry__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Common__EndorsementEntry *)
     protobuf_c_message_unpack (&common__endorsement_entry__descriptor,
                                allocator, len, data);
}
void   common__endorsement_entry__free_unpacked
                     (Common__EndorsementEntry *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &common__endorsement_entry__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   common__key_value_pair__init
                     (Common__KeyValuePair         *message)
{
  static const Common__KeyValuePair init_value = COMMON__KEY_VALUE_PAIR__INIT;
  *message = init_value;
}
size_t common__key_value_pair__get_packed_size
                     (const Common__KeyValuePair *message)
{
  assert(message->base.descriptor == &common__key_value_pair__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t common__key_value_pair__pack
                     (const Common__KeyValuePair *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &common__key_value_pair__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t common__key_value_pair__pack_to_buffer
                     (const Common__KeyValuePair *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &common__key_value_pair__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Common__KeyValuePair *
       common__key_value_pair__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Common__KeyValuePair *)
     protobuf_c_message_unpack (&common__key_value_pair__descriptor,
                                allocator, len, data);
}
void   common__key_value_pair__free_unpacked
                     (Common__KeyValuePair *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &common__key_value_pair__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   common__limit__init
                     (Common__Limit         *message)
{
  static const Common__Limit init_value = COMMON__LIMIT__INIT;
  *message = init_value;
}
size_t common__limit__get_packed_size
                     (const Common__Limit *message)
{
  assert(message->base.descriptor == &common__limit__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t common__limit__pack
                     (const Common__Limit *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &common__limit__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t common__limit__pack_to_buffer
                     (const Common__Limit *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &common__limit__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Common__Limit *
       common__limit__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Common__Limit *)
     protobuf_c_message_unpack (&common__limit__descriptor,
                                allocator, len, data);
}
void   common__limit__free_unpacked
                     (Common__Limit *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &common__limit__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor common__tx_request__field_descriptors[3] =
{
  {
    "payload",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Common__TxRequest, payload),
    &common__chainmaker_payload__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "sender",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Common__TxRequest, sender),
    &common__endorsement_entry__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "endorsers",
    3,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Common__TxRequest, n_endorsers),
    offsetof(Common__TxRequest, endorsers),
    &common__endorsement_entry__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned common__tx_request__field_indices_by_name[] = {
  2,   /* field[2] = endorsers */
  0,   /* field[0] = payload */
  1,   /* field[1] = sender */
};
static const ProtobufCIntRange common__tx_request__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor common__tx_request__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "common.TxRequest",
  "TxRequest",
  "Common__TxRequest",
  "common",
  sizeof(Common__TxRequest),
  3,
  common__tx_request__field_descriptors,
  common__tx_request__field_indices_by_name,
  1,  common__tx_request__number_ranges,
  (ProtobufCMessageInit) common__tx_request__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor common__raw_tx_request__field_descriptors[1] =
{
  {
    "rawTx",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    offsetof(Common__RawTxRequest, rawtx),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned common__raw_tx_request__field_indices_by_name[] = {
  0,   /* field[0] = rawTx */
};
static const ProtobufCIntRange common__raw_tx_request__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor common__raw_tx_request__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "common.RawTxRequest",
  "RawTxRequest",
  "Common__RawTxRequest",
  "common",
  sizeof(Common__RawTxRequest),
  1,
  common__raw_tx_request__field_descriptors,
  common__raw_tx_request__field_indices_by_name,
  1,  common__raw_tx_request__number_ranges,
  (ProtobufCMessageInit) common__raw_tx_request__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor common__chainmaker_payload__field_descriptors[10] =
{
  {
    "chain_id",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Common__ChainmakerPayload, chain_id),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "tx_type",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_ENUM,
    0,   /* quantifier_offset */
    offsetof(Common__ChainmakerPayload, tx_type),
    &common__tx_type__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "tx_id",
    3,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Common__ChainmakerPayload, tx_id),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "timestamp",
    4,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT64,
    0,   /* quantifier_offset */
    offsetof(Common__ChainmakerPayload, timestamp),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "expiration_time",
    5,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_INT64,
    0,   /* quantifier_offset */
    offsetof(Common__ChainmakerPayload, expiration_time),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "contract_name",
    6,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Common__ChainmakerPayload, contract_name),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "method",
    7,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Common__ChainmakerPayload, method),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "parameters",
    8,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Common__ChainmakerPayload, n_parameters),
    offsetof(Common__ChainmakerPayload, parameters),
    &common__key_value_pair__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "sequence",
    9,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT64,
    0,   /* quantifier_offset */
    offsetof(Common__ChainmakerPayload, sequence),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "limit",
    10,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Common__ChainmakerPayload, limit),
    &common__limit__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned common__chainmaker_payload__field_indices_by_name[] = {
  0,   /* field[0] = chain_id */
  5,   /* field[5] = contract_name */
  4,   /* field[4] = expiration_time */
  9,   /* field[9] = limit */
  6,   /* field[6] = method */
  7,   /* field[7] = parameters */
  8,   /* field[8] = sequence */
  3,   /* field[3] = timestamp */
  2,   /* field[2] = tx_id */
  1,   /* field[1] = tx_type */
};
static const ProtobufCIntRange common__chainmaker_payload__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 10 }
};
const ProtobufCMessageDescriptor common__chainmaker_payload__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "common.chainmaker_payload",
  "ChainmakerPayload",
  "Common__ChainmakerPayload",
  "common",
  sizeof(Common__ChainmakerPayload),
  10,
  common__chainmaker_payload__field_descriptors,
  common__chainmaker_payload__field_indices_by_name,
  1,  common__chainmaker_payload__number_ranges,
  (ProtobufCMessageInit) common__chainmaker_payload__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor common__endorsement_entry__field_descriptors[2] =
{
  {
    "signer",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_MESSAGE,
    0,   /* quantifier_offset */
    offsetof(Common__EndorsementEntry, signer),
    &accesscontrol__member__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "signature",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    offsetof(Common__EndorsementEntry, signature),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned common__endorsement_entry__field_indices_by_name[] = {
  1,   /* field[1] = signature */
  0,   /* field[0] = signer */
};
static const ProtobufCIntRange common__endorsement_entry__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor common__endorsement_entry__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "common.EndorsementEntry",
  "EndorsementEntry",
  "Common__EndorsementEntry",
  "common",
  sizeof(Common__EndorsementEntry),
  2,
  common__endorsement_entry__field_descriptors,
  common__endorsement_entry__field_indices_by_name,
  1,  common__endorsement_entry__number_ranges,
  (ProtobufCMessageInit) common__endorsement_entry__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor common__key_value_pair__field_descriptors[2] =
{
  {
    "key",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Common__KeyValuePair, key),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "value",
    2,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_BYTES,
    0,   /* quantifier_offset */
    offsetof(Common__KeyValuePair, value),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned common__key_value_pair__field_indices_by_name[] = {
  0,   /* field[0] = key */
  1,   /* field[1] = value */
};
static const ProtobufCIntRange common__key_value_pair__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 2 }
};
const ProtobufCMessageDescriptor common__key_value_pair__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "common.KeyValuePair",
  "KeyValuePair",
  "Common__KeyValuePair",
  "common",
  sizeof(Common__KeyValuePair),
  2,
  common__key_value_pair__field_descriptors,
  common__key_value_pair__field_indices_by_name,
  1,  common__key_value_pair__number_ranges,
  (ProtobufCMessageInit) common__key_value_pair__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor common__limit__field_descriptors[1] =
{
  {
    "gas_limit",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT64,
    0,   /* quantifier_offset */
    offsetof(Common__Limit, gas_limit),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned common__limit__field_indices_by_name[] = {
  0,   /* field[0] = gas_limit */
};
static const ProtobufCIntRange common__limit__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor common__limit__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "common.Limit",
  "Limit",
  "Common__Limit",
  "common",
  sizeof(Common__Limit),
  1,
  common__limit__field_descriptors,
  common__limit__field_indices_by_name,
  1,  common__limit__number_ranges,
  (ProtobufCMessageInit) common__limit__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCEnumValue common__tx_type__enum_values_by_number[4] =
{
  { "INVOKE_CONTRACT", "COMMON__TX_TYPE__INVOKE_CONTRACT", 0 },
  { "QUERY_CONTRACT", "COMMON__TX_TYPE__QUERY_CONTRACT", 1 },
  { "SUBSCRIBE", "COMMON__TX_TYPE__SUBSCRIBE", 2 },
  { "ARCHIVE", "COMMON__TX_TYPE__ARCHIVE", 3 },
};
static const ProtobufCIntRange common__tx_type__value_ranges[] = {
{0, 0},{0, 4}
};
static const ProtobufCEnumValueIndex common__tx_type__enum_values_by_name[4] =
{
  { "ARCHIVE", 3 },
  { "INVOKE_CONTRACT", 0 },
  { "QUERY_CONTRACT", 1 },
  { "SUBSCRIBE", 2 },
};
const ProtobufCEnumDescriptor common__tx_type__descriptor =
{
  PROTOBUF_C__ENUM_DESCRIPTOR_MAGIC,
  "common.TxType",
  "TxType",
  "Common__TxType",
  "common",
  4,
  common__tx_type__enum_values_by_number,
  4,
  common__tx_type__enum_values_by_name,
  1,
  common__tx_type__value_ranges,
  NULL,NULL,NULL,NULL   /* reserved[1234] */
};
