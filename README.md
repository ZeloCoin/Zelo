Zxlo Core – Powering the Future of Digital Finance
==================================================

[![Build Status](https://travis-ci.org/zxlo-project/zxlo.svg?branch=main)](https://travis-ci.org/zxlo-project/zxlo)

🌐 https://zxlo.org

What is Zxlo?
-------------

**Zxlo** is a next-generation, decentralized digital currency engineered for speed, scalability, and intelligence. Built on proven cryptographic foundations, Zxlo enables anyone, anywhere to send and receive value instantly — without banks, borders, or bottlenecks.

Zxlo operates on a peer-to-peer blockchain network, with no central authority. Transactions and coin issuance are governed transparently by the community through distributed consensus. Zxlo Core is the official reference implementation of the protocol.

💡 Zxlo goes beyond traditional cryptocurrencies by integrating intelligent automation and adaptive consensus tuning, making it one of the world's first **AI-assisted blockchain protocols**.

Ready to dive in? Download the latest binaries at [zxlo.org](https://zxlo.org).

License
-------

Zxlo Core is released under the open-source MIT License.  
See [COPYING](COPYING) or [opensource.org/licenses/MIT](https://opensource.org/licenses/MIT) for more details.

Development Workflow
--------------------

The `main` branch is under active development and regularly updated. It's suitable for developers and testers but may not always be fully stable. Stable releases are published and tagged from release branches.

Zxlo's graphical user interface (GUI) is developed in a separate repo:
🔗 [https://github.com/zxlo-project/zxlo-gui](https://github.com/zxlo-project/zxlo-gui)

Please refer to [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines on submitting patches or proposing changes.  
Developer insights and notes are located in [doc/developer-notes.md](doc/developer-notes.md).

🧠 For design discussions or complex proposals, please post to the [Zxlo developer mailing list](https://groups.google.com/forum/#!forum/zxlo-dev).  
.

Testing and Quality Assurance
-----------------------------

All code changes must go through a rigorous process of testing and peer review. We prioritize security, performance, and network stability — especially since Zxlo is a protocol trusted to handle real economic value.

Please help us by reviewing open pull requests, reporting bugs, or testing new releases.

### Automated Testing

Unit tests are encouraged for all new features. If enabled during configuration, you can run them with:

```bash
make check
```

# Zxlo with RandomX

This is a fork of Litecoin that uses RandomX instead of Scrypt for its proof-of-work algorithm.

## Requirements

- RandomX library (https://github.com/tevador/RandomX)
- Standard build dependencies

## Building

1. Install RandomX:
```bash
git clone https://github.com/tevador/RandomX.git
cd RandomX
mkdir build && cd build
cmake ..
make
sudo make install
```

2. Build Zxlo:
```bash
./autogen.sh
./configure
make
```

## Changes

- Replaced Scrypt with RandomX for proof-of-work
- Adjusted difficulty parameters for RandomX
- Added RandomX initialization and cleanup
- Updated build system to include RandomX

## Notes

- This is a hard fork and requires all nodes to upgrade
- Mining software needs to be updated to support RandomX
- Network difficulty will need to be recalibrated after the fork

## License

MIT License
