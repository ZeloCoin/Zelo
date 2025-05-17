#include <crypto/randomx.h>
#include <primitives/block.h>
#include <test/util/setup_common.h>
#include <util/strencodings.h>

#include <boost/test/unit_test.hpp>

BOOST_FIXTURE_TEST_SUITE(randomx_tests, BasicTestingSetup)

BOOST_AUTO_TEST_CASE(randomx_basic_test)
{
    // Initialize RandomX
    randomx_init();

    // Test basic hash calculation
    CBlockHeader header;
    header.nVersion = 1;
    header.hashPrevBlock = uint256S("0000000000000000000000000000000000000000000000000000000000000000");
    header.hashMerkleRoot = uint256S("0000000000000000000000000000000000000000000000000000000000000000");
    header.nTime = 1231006505;
    header.nBits = 0x1d00ffff;
    header.nNonce = 2083236893;

    uint256 hash = header.GetPoWHash();
    BOOST_CHECK(!hash.IsNull());

    // Test hash consistency
    uint256 hash2 = header.GetPoWHash();
    BOOST_CHECK(hash == hash2);

    // Test different nonce produces different hash
    header.nNonce++;
    uint256 hash3 = header.GetPoWHash();
    BOOST_CHECK(hash != hash3);

    // Cleanup
    randomx_cleanup();
}

BOOST_AUTO_TEST_CASE(randomx_difficulty_test)
{
    // Initialize RandomX
    randomx_init();

    // Test difficulty adjustment
    CBlockHeader header;
    header.nVersion = 1;
    header.hashPrevBlock = uint256S("0000000000000000000000000000000000000000000000000000000000000000");
    header.hashMerkleRoot = uint256S("0000000000000000000000000000000000000000000000000000000000000000");
    header.nTime = 1231006505;
    header.nBits = 0x1d00ffff;
    header.nNonce = 0;

    // Test that hash meets difficulty target
    uint256 hash = header.GetPoWHash();
    BOOST_CHECK(CheckProofOfWork(hash, header.nBits, Params().GetConsensus()));

    // Cleanup
    randomx_cleanup();
}

BOOST_AUTO_TEST_CASE(randomx_performance_test)
{
    // Initialize RandomX
    randomx_init();

    // Test hash calculation performance
    CBlockHeader header;
    header.nVersion = 1;
    header.hashPrevBlock = uint256S("0000000000000000000000000000000000000000000000000000000000000000");
    header.hashMerkleRoot = uint256S("0000000000000000000000000000000000000000000000000000000000000000");
    header.nTime = 1231006505;
    header.nBits = 0x1d00ffff;

    // Measure time for 1000 hash calculations
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; i++) {
        header.nNonce = i;
        header.GetPoWHash();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    // Log performance
    BOOST_TEST_MESSAGE("Time for 1000 RandomX hashes: " << duration.count() << "ms");

    // Cleanup
    randomx_cleanup();
}

BOOST_AUTO_TEST_SUITE_END() 