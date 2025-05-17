#include <crypto/randomx.h>
#include <randomx.h>
#include <util/system.h>

static randomx_cache* cache = nullptr;
static randomx_vm* vm = nullptr;

void randomx_init() {
    if (cache == nullptr) {
        cache = randomx_alloc_cache(RANDOMX_FLAG_DEFAULT);
        if (cache == nullptr) {
            throw std::runtime_error("Failed to allocate RandomX cache");
        }
        
        // Initialize cache with a fixed key (you may want to make this configurable)
        const char key[] = "LitecoinRandomX";
        randomx_init_cache(cache, key, sizeof(key) - 1);
        
        // Create VM
        vm = randomx_create_vm(RANDOMX_FLAG_DEFAULT, cache, nullptr);
        if (vm == nullptr) {
            randomx_release_cache(cache);
            throw std::runtime_error("Failed to create RandomX VM");
        }
    }
}

void randomx_cleanup() {
    if (vm != nullptr) {
        randomx_destroy_vm(vm);
        vm = nullptr;
    }
    if (cache != nullptr) {
        randomx_release_cache(cache);
        cache = nullptr;
    }
}

void randomx_hash(const char* input, char* output) {
    if (vm == nullptr) {
        randomx_init();
    }
    
    randomx_calculate_hash(vm, input, 80, output);
} 