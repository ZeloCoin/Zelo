Zelo Core – Powering the Future of Digital Finance
==================================================

[![Build Status](https://travis-ci.org/zelo-project/zelo.svg?branch=main)](https://travis-ci.org/zelo-project/zelo)

🌐 https://zelo.org

What is Zelo?
-------------

**Zelo** is a next-generation, decentralized digital currency engineered for speed, scalability, and intelligence. Built on proven cryptographic foundations, Zelo enables anyone, anywhere to send and receive value instantly — without banks, borders, or bottlenecks.

Zelo operates on a peer-to-peer blockchain network, with no central authority. Transactions and coin issuance are governed transparently by the community through distributed consensus. Zelo Core is the official reference implementation of the protocol.

💡 Zelo goes beyond traditional cryptocurrencies by integrating intelligent automation and adaptive consensus tuning, making it one of the world’s first **AI-assisted blockchain protocols**.

Ready to dive in? Download the latest binaries at [zelo.org](https://zelo.org).

License
-------

Zelo Core is released under the open-source MIT License.  
See [COPYING](COPYING) or [opensource.org/licenses/MIT](https://opensource.org/licenses/MIT) for more details.

Development Workflow
--------------------

The `main` branch is under active development and regularly updated. It’s suitable for developers and testers but may not always be fully stable. Stable releases are published and tagged from release branches.

Zelo's graphical user interface (GUI) is developed in a separate repo:
🔗 [https://github.com/zelo-project/zelo-gui](https://github.com/zelo-project/zelo-gui)

Please refer to [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines on submitting patches or proposing changes.  
Developer insights and notes are located in [doc/developer-notes.md](doc/developer-notes.md).

🧠 For design discussions or complex proposals, please post to the [Zelo developer mailing list](https://groups.google.com/forum/#!forum/zelo-dev).  
.

Testing and Quality Assurance
-----------------------------

All code changes must go through a rigorous process of testing and peer review. We prioritize security, performance, and network stability — especially since Zelo is a protocol trusted to handle real economic value.

Please help us by reviewing open pull requests, reporting bugs, or testing new releases.

### Automated Testing

Unit tests are encouraged for all new features. If enabled during configuration, you can run them with:

```bash
make check
