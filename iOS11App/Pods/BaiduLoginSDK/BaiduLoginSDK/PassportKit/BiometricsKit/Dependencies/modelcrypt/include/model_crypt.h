/*
 *  model_crypt.h
 *  model crypt common header
 *
 *  Created by fangyanghua on 9/25/17.
 *
 */

#ifndef BAIDU_ML_MOBILE_MODEL_ENCRYPT_INC_MODEL_CRYPT_H
#define BAIDU_ML_MOBILE_MODEL_ENCRYPT_INC_MODEL_CRYPT_H

#include <stdint.h>

#define MODEL_CRYPT_HIDE_API __attribute__((visibility("hidden")))

#define IN
#define OUT

#ifdef __cplusplus
extern "C" {
#endif

/*
 * init context for encryption/decryption
 * input parameters:
 *   key: password string or binary buffer defined by user
 *   key_size: number of bytes of the key
 * output parameters:
 *   context: handle of the encryption/decryption context
 *   sign: signature of the key
 * return value:
 *   0: succeed
 *   other: failed
 */
MODEL_CRYPT_HIDE_API
int init_crypt_context(IN const unsigned char *key, IN unsigned int key_size,
                       OUT void **context, OUT unsigned int *sign);

/*
 * release context for encryption/decryption
 * input parameters:
 *   context: handle of the encryption/decryption context
 * return value:
 */
MODEL_CRYPT_HIDE_API
void uninit_crypt_context(IN const void *context);

/*
 * utility: create file mapping for a file
 * input parameters:
 *   file_path: path of the file to be mapped
 * output parameters:
 *   file_map: point to the file mapping
 *   file_size: size of the file
 * return value:
 *   0: succeed
 *   other: failed
 */
MODEL_CRYPT_HIDE_API
int open_file_map(IN const char *file_path, OUT void **file_map, OUT unsigned int *file_size);

/*
 * utility: release the file mapping
 * input parameters:
 *   file_map: point to the file mapping
 *   file_size: size of the file
 * return value:
 */
MODEL_CRYPT_HIDE_API
void close_file_map(IN const void *file_map, IN unsigned int file_size);

#ifdef __cplusplus
}
#endif

#endif /* BAIDU_ML_MOBILE_MODEL_ENCRYPT_INC_MODEL_CRYPT_H */
