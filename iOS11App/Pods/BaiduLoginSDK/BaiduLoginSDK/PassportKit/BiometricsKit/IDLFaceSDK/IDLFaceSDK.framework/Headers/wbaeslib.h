#ifndef __WBAES_LIB_H__
#define __WBAES_LIB_H__

#pragma once
#ifdef __cplusplus
extern "C" {
#endif

extern void *gsecf[];
/**
 * \brief         WBAES initialize function
 *
 * \note         Before using encryption/decryption function, call this
 *                 function to initialize encryption/decryption key file.
 *                 If you use encryption function, you can only set 
 *                 encryptTable to the right value and set NULL for
 *                 decryptTable.
 *
 * \param encryptTable      encryption key file path
 * \param decryptTable      decryption key file path
 *
 * \return         return context if successful
 */

typedef void *(*FN1)(const char *, const char *);
#define WBAES_INIT(encryptTable,decryptTable) \
        ((FN1)gsecf[1])(encryptTable,decryptTable)

/**
 * \brief         WBAES initialize function
 *
 * \note         Before using encryption/decryption function, call this
 *                 function to initialize encryption/decryption key data from memory.
 *                 If you use encryption function, you can only set 
 *                 encryptTable to the right value and set NULL for
 *                 decryptTable.
 *
 * \param encryptTable      encryption key data in memory
 * \param decryptTable      decryption key data in memory
 *
 * \return         return context  if successful
 */
typedef void * (*FN2)(const char *, const char *);
#define WBAES_INIT_MEMORY(encryptTable,decryptTable) \
        ((FN2)gsecf[2])(encryptTable,decryptTable)

/**
 * \brief         WBAES destory function
 *
 * \note         Free context memory.
 *
 * \param context      context for encryption and decryption.
 *
 * \return         0 if successful
 */
typedef int (*FN3)(void *);
#define WBAES_DESTORY(context) \
        ((FN3)gsecf[3])(context)


/**
 * \brief         WBAES  memory encryption function
 *
 * \note         If the buffer length is not divisable by 16, the output buffer length
 *                 will be larger than input buffer length. The output buffer length as below:
 *                 ((length + 15)/16)*16
 *
 * \param context   encrypt/decrypt context
 * \param input      input buffer pointer
 * \param output    output buffer pointer
 * \param length    input buffer length
 *
 * \return         0 if successful
 */
typedef int (*FN4)(void *, const char *, char *, const long);
#define WBAES_ENCRYPT(context, input, output, length) \
        ((FN4)gsecf[4])(context, input, output, length)

/**
 * \brief         WBAES  memory decryption function
 *
 * \note         The  memory decryption function should be used with memory encryption in pair.
 *                 The output length is equal to input length.
 *
 * \param context   encrypt/decrypt context
 * \param input      input buffer pointer
 * \param output    output buffer pointer
 * \param length    input buffer length
 *
 * \return         0 if successful
 */
typedef int (*FN5)(void *, const char *, char *, const long);
#define WBAES_DECRYPT(context, input, output, length) \
        ((FN5)gsecf[5])(context, input, output, length)

/**
 * \brief         WBAES  file encryption function
 *
 * \note         blockSize is a very important factor for file encryption/decryption.
 *                 The file is devided into many blocks and each block is encrypted alone.
 *                 The bigger size of block, the faster of the encryption/decryption time.
 *                 The encryption/decryption block size should be equal for a file.
 *
 * \param context     encrypt/decrypt context
 * \param inPath      input file name
 * \param outPath    output file name
 * \param blockSize  block size for each encrytion/decryption(for example:4096)
 *
 * \return         0 if successful
 */
typedef int (*FN6)(void *, const char *, const char *, const int);
#define WBAES_ENCRYPT_FILE(context, inPath, outPath, blockSize) \
        ((FN6)gsecf[6])(context, inPath, outPath, blockSize)

/**
 * \brief         WBAES  file decryption function
 *
 * \note         blockSize is a very important factor for file encryption/decryption.
 *                 The file is devided into many blocks and each block is encrypted alone.
 *                 The bigger size of block, the faster of the encryption/decryption time.
 *                 The encryption/decryption block size should be equal for a file.
 *
 * \param context    encrypt/decrypt context
 * \param inPath      input file name
 * \param outPath    output file name
 * \param blockSize  block size for each encrytion/decryption(for example:4096)
 *
 * \return         0 if successful
 */
typedef int (*FN7)(void *, const char *, const char *, const int);
#define WBAES_DECRYPT_FILE(context, inPath, outPath, blockSize) \
        ((FN7)gsecf[7])(context, inPath, outPath, blockSize)

/**
 * \brief         WBAES  file encryption function
 *
 * \note         blockSize is a very important factor for file encryption/decryption.
 *                 The file is devided into many blocks and each block is encrypted alone.
 *                 The bigger size of block, the faster of the encryption/decryption time.
 *                 The encryption/decryption block size should be equal for a file.
 *
 * \param context         encrypt/decrypt context
 * \param inPath           input file name
 * \param blockSize       block size for each encrytion/decryption(for example:4096)
 * \param outBuf           encrypted buffer address
 * \param outBufSize      encrypted buffer length
 *
 * \return         0 if successful
 */
typedef int (*FN8)(void *, const char *, const int, char **, int *);
#define WBAES_ENCRYPT_FILE_TO_MEMORY(context, inPath,blockSize,outBuf,outBufSize) \
        ((FN8)gsecf[8])(context, inPath, blockSize, outBuf, outBufSize)

/**
 * \brief         WBAES  file decryption function
 *
 * \note         blockSize is a very important factor for file encryption/decryption.
 *                 The file is devided into many blocks and each block is encrypted alone.
 *                 The bigger size of block, the faster of the encryption/decryption time.
 *                 The encryption/decryption block size should be equal for a file.
 *
 * \param context         encrypt/decrypt context
 * \param inPath           input file name
 * \param blockSize       block size for each encrytion/decryption(for example:4096)
 * \param outBuf           decrypted buffer address
 * \param outBufSize      decrypted buffer length
 *
 * \return         0 if successful
 */
typedef int (*FN9)(void *, const char *, const int, char **, int *);
#define WBAES_DECRYPT_FILE_TO_MEMORY(context, inPath, blockSize, outBuf, outBufSize) \
        ((FN9)gsecf[9])(context, inPath, blockSize, outBuf, outBufSize)

#ifdef __cplusplus
}
#endif
#endif /*__WBAES_LIB_H__*/

