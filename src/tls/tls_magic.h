/*
* SSL/TLS Protocol Constants
* (C) 2004-2010 Jack Lloyd
*
* Released under the terms of the Botan license
*/

#ifndef BOTAN_TLS_PROTOCOL_MAGIC_H__
#define BOTAN_TLS_PROTOCOL_MAGIC_H__

namespace Botan {

/**
* Protocol Constants for SSL/TLS
*/
enum Size_Limits {
   TLS_HEADER_SIZE    = 5,
   MAX_PLAINTEXT_SIZE = 16*1024,
   MAX_COMPRESSED_SIZE = MAX_PLAINTEXT_SIZE + 1024,
   MAX_CIPHERTEXT_SIZE = MAX_COMPRESSED_SIZE + 1024
};

enum Version_Code {
   NO_VERSION_SET     = 0x0000,
   SSL_V3             = 0x0300,
   TLS_V10            = 0x0301,
   TLS_V11            = 0x0302
};

enum Connection_Side { CLIENT = 1, SERVER = 2 };

enum Record_Type {
   CONNECTION_CLOSED  = 0,

   CHANGE_CIPHER_SPEC = 20,
   ALERT              = 21,
   HANDSHAKE          = 22,
   APPLICATION_DATA   = 23
};

enum Handshake_Type {
   HELLO_REQUEST       = 0,
   CLIENT_HELLO        = 1,
   CLIENT_HELLO_SSLV2  = 200, // Not a wire value
   SERVER_HELLO        = 2,
   NEW_SESSION_TICKET  = 4, // RFC 5077
   CERTIFICATE         = 11,
   SERVER_KEX          = 12,
   CERTIFICATE_REQUEST = 13,
   SERVER_HELLO_DONE   = 14,
   CERTIFICATE_VERIFY  = 15,
   CLIENT_KEX          = 16,
   FINISHED            = 20,

   NEXT_PROTOCOL       = 67,

   HANDSHAKE_CCS       = 100, // Not a wire value
   HANDSHAKE_NONE      = 255  // Null value
};

enum Alert_Level {
   WARNING                 = 1,
   FATAL                   = 2
};

enum Alert_Type {
   CLOSE_NOTIFY            = 0,
   UNEXPECTED_MESSAGE      = 10,
   BAD_RECORD_MAC          = 20,
   DECRYPTION_FAILED       = 21,
   RECORD_OVERFLOW         = 22,
   DECOMPRESSION_FAILURE   = 30,
   HANDSHAKE_FAILURE       = 40,
   NO_CERTIFICATE          = 41, // SSLv3 only
   BAD_CERTIFICATE         = 42,
   UNSUPPORTED_CERTIFICATE = 43,
   CERTIFICATE_REVOKED     = 44,
   CERTIFICATE_EXPIRED     = 45,
   CERTIFICATE_UNKNOWN     = 46,
   ILLEGAL_PARAMETER       = 47,
   UNKNOWN_CA              = 48,
   ACCESS_DENIED           = 49,
   DECODE_ERROR            = 50,
   DECRYPT_ERROR           = 51,
   EXPORT_RESTRICTION      = 60,
   PROTOCOL_VERSION        = 70,
   INSUFFICIENT_SECURITY   = 71,
   INTERNAL_ERROR          = 80,
   USER_CANCELED           = 90,
   NO_RENEGOTIATION        = 100,

   UNSUPPORTED_EXTENSION   = 110,
   UNRECOGNIZED_NAME       = 112,

   UNKNOWN_PSK_IDENTITY    = 115,

   NULL_ALERT              = 255
};

enum Certificate_Type {
   RSA_CERT    = 1,
   DSS_CERT    = 2,
   DH_RSA_CERT = 3,
   DH_DSS_CERT = 4
};

enum Ciphersuite_Code {
   TLS_RSA_WITH_RC4_128_MD5                 = 0x0004,
   TLS_RSA_WITH_RC4_128_SHA                 = 0x0005,

   TLS_RSA_WITH_3DES_EDE_CBC_SHA            = 0x000A,
   TLS_RSA_WITH_AES_128_CBC_SHA             = 0x002F,
   TLS_RSA_WITH_AES_256_CBC_SHA             = 0x0035,
   TLS_RSA_WITH_AES_128_CBC_SHA256          = 0x003C,
   TLS_RSA_WITH_AES_256_CBC_SHA256          = 0x003D,
   TLS_RSA_WITH_SEED_CBC_SHA                = 0x0096,

   TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA        = 0x0013,
   TLS_DHE_DSS_WITH_AES_128_CBC_SHA         = 0x0032,
   TLS_DHE_DSS_WITH_AES_256_CBC_SHA         = 0x0038,
   TLS_DHE_DSS_WITH_AES_128_CBC_SHA256      = 0x0040,
   TLS_DHE_DSS_WITH_AES_256_CBC_SHA256      = 0x006A,
   TLS_DHE_DSS_WITH_SEED_CBC_SHA            = 0x0099,
   TLS_DHE_DSS_WITH_RC4_128_SHA             = 0x0066,

   TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA        = 0x0016,
   TLS_DHE_RSA_WITH_AES_128_CBC_SHA         = 0x0033,
   TLS_DHE_RSA_WITH_AES_256_CBC_SHA         = 0x0039,
   TLS_DHE_RSA_WITH_AES_128_CBC_SHA256      = 0x0067,
   TLS_DHE_RSA_WITH_AES_256_CBC_SHA256      = 0x006B,
   TLS_DHE_RSA_WITH_SEED_CBC_SHA            = 0x009A,

   TLS_SRP_SHA_RSA_WITH_3DES_EDE_SHA        = 0xC01B,
   TLS_SRP_SHA_DSS_WITH_3DES_EDE_SHA        = 0xC01C,
   TLS_SRP_SHA_RSA_WITH_AES_128_SHA         = 0xC01E,
   TLS_SRP_SHA_DSS_WITH_AES_128_SHA         = 0xC01F,
   TLS_SRP_SHA_RSA_WITH_AES_256_SHA         = 0xC021,
   TLS_SRP_SHA_DSS_WITH_AES_256_SHA         = 0xC022,

   TLS_ECDHE_ECDSA_WITH_RC4_128_SHA         = 0xC007,
   TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA    = 0xC008,
   TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA     = 0xC009,
   TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA     = 0xC00A,
   TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256  = 0xC023,
   TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384  = 0xC024,

   TLS_ECDHE_RSA_WITH_RC4_128_SHA           = 0xC011,
   TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA      = 0xC012,
   TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA       = 0xC013,
   TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA       = 0xC014,
   TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256    = 0xC027,
   TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384    = 0xC028,

   /* signalling values that cannot be negotiated */
   TLS_EMPTY_RENEGOTIATION_INFO_SCSV        = 0x00FF
};

/*
* Form of the ciphersuites broken down by field instead of
* being randomly assigned codepoints.
*/
enum TLS_Ciphersuite_Algos {
   TLS_ALGO_SIGNER_MASK       = 0xFF000000,
   TLS_ALGO_SIGNER_ANON       = 0x01000000,
   TLS_ALGO_SIGNER_RSA        = 0x02000000,
   TLS_ALGO_SIGNER_DSA        = 0x03000000,
   TLS_ALGO_SIGNER_ECDSA      = 0x04000000,

   TLS_ALGO_KEYEXCH_MASK      = 0x00FF0000,
   TLS_ALGO_KEYEXCH_NOKEX     = 0x00010000, // exchange via key in server cert
   TLS_ALGO_KEYEXCH_DH        = 0x00020000,
   TLS_ALGO_KEYEXCH_ECDH      = 0x00030000,
   TLS_ALGO_KEYEXCH_SRP       = 0x00040000,

   TLS_ALGO_MAC_MASK          = 0x0000FF00,
   TLS_ALGO_MAC_MD5           = 0x00000100,
   TLS_ALGO_MAC_SHA1          = 0x00000200,
   TLS_ALGO_MAC_SHA256        = 0x00000300,
   TLS_ALGO_MAC_SHA384        = 0x00000400,

   TLS_ALGO_CIPHER_MASK       = 0x000000FF,
   TLS_ALGO_CIPHER_RC4_128    = 0x00000001,
   TLS_ALGO_CIPHER_3DES_CBC   = 0x00000002,
   TLS_ALGO_CIPHER_AES128_CBC = 0x00000003,
   TLS_ALGO_CIPHER_AES256_CBC = 0x00000004,
   TLS_ALGO_CIPHER_SEED_CBC   = 0x00000005
};

enum Compression_Method {
   NO_COMPRESSION       = 0x00,
   DEFLATE_COMPRESSION  = 0x01
};

enum TLS_Handshake_Extension_Type {
   TLSEXT_SERVER_NAME_INDICATION = 0,
   TLSEXT_MAX_FRAGMENT_LENGTH    = 1,
   TLSEXT_CLIENT_CERT_URL        = 2,
   TLSEXT_TRUSTED_CA_KEYS        = 3,
   TLSEXT_TRUNCATED_HMAC         = 4,

   TLSEXT_USABLE_ELLIPTIC_CURVES = 10,
   TLSEXT_EC_POINT_FORMATS       = 11,

   TLSEXT_SRP_IDENTIFIER         = 12,

   TLSEXT_CERTIFICATE_TYPES      = 9,
   TLSEXT_SESSION_TICKET         = 35,

   TLSEXT_NEXT_PROTOCOL          = 13172,

   TLSEXT_SAFE_RENEGOTIATION     = 65281,
};

}

#endif
