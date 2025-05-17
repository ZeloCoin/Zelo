#ifndef BITCOIN_CRYPTO_RANDOMX_H
#define BITCOIN_CRYPTO_RANDOMX_H

#include <stdint.h>
#include <stdlib.h>
#include <randomx.h>

// Initialize RandomX context
void randomx_init();

// Clean up RandomX context
void randomx_cleanup();

// Calculate RandomX hash
void randomx_hash(const char* input, char* output);

#endif // BITCOIN_CRYPTO_RANDOMX_H 