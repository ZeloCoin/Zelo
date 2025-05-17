This directory contains integration tests that test zxlod and its
utilities in their entirety. It does not contain unit tests, which
can be found in [/src/test](/src/test), [/src/wallet/test](/src/wallet/test),
etc.

This directory contains the following sets of tests:

- [functional](/test/functional) which tests the functionality of
zxlod and zxlo-qt by interacting with them through the RPC and P2P
interfaces.
- [util](/test/util) which tests the zxlo utilities, currently only
zxlo-tx.
- [lint](/test/lint) which perform various static analysis checks.

The util tests are run as part of `make check` target. The functional
tests and lint scripts can be run as explained in the sections below.

# Running tests locally

Before tests can be run locally, Zxlo Core must be built.  See the [building instructions](/doc#building) for help.

## Functional tests

### Dependencies

The ZMQ functional test requires a python ZMQ package. To install it:

- on Unix, run `sudo apt-get install python3-zmq`
- on mac OS, run `pip3 install pyzmq`
- on Windows, see `python-zmq.md`

### Running the tests

Individual tests can be run by directly calling the test script, e.g.:

```bash
test/functional/wallet_hd.py
```

or can be run through the test_runner harness, eg:

```bash
test/functional/test_runner.py wallet_hd.py
```

You can run any combination (incl. duplicates) of tests by calling:

```bash
test/functional/test_runner.py <testname1> <testname2> <testname3> ...
```

Run the regression test suite with:

```bash
test/functional/test_runner.py
```

Run all possible tests with:

```bash
test/functional/test_runner.py --extended
```

By default, up to 4 tests will be run in parallel by test_runner. To specify
how many jobs to run, append `--jobs=n`

The individual tests and the test_runner harness have many command-line
options. Run `test_runner.py -h` to see them all.

#### Troubleshooting and debugging test failures

##### Resource contention

The P2P and RPC ports used by the zxlod nodes-under-test are chosen to make
conflicts with other processes unlikely. However, if there is another zxlod
process running on the system (perhaps from a previous test which hasn't successfully
killed all its zxlod nodes), then there may be a port conflict which will
cause the test to fail. It is recommended that you run the tests on a system
where no other zxlod processes are running.

On linux, the test_framework will warn if there is another
zxlod process running when the tests are started.

If there are zombie zxlod processes after test failure, you can kill them
by running the following commands. **Note that these commands will kill all
zxlod processes running on the system, so should not be used if any non-test
zxlod processes are being run.**

```bash
killall zxlod
```

or

```bash
pkill -9 zxlod
```

##### Data directory cache

A pre-mined blockchain with 200 blocks is generated the first time a
functional test is run and is stored in test/cache. This speeds up
test startup times since new blockchains don't need to be generated for
every test. However, the cache may get into a bad state, in which case
tests will fail. If this happens, remove the cache directory (and make
sure zxlod processes are stopped as above):

```bash
rm -rf test/cache
killall zxlod
```

##### Test logging

The tests contain logging at different levels (debug, info, warning, etc). By
default:

- When run through the test_runner harness, *all* logs are written to
  `test_framework.log` and no logs are output to the console.
- When run directly, *all* logs are written to `test_framework.log` and INFO
  level and above are output to the console.
- When run by [our CI (Continuous Integration)](/ci/README.md), no logs are output to the console. However, if a test
  fails, the `test_framework.log` file will be made available in the test report.

The `test_framework.log` file can be located in the test directory if you are
running a test manually, or in the root of the build directory if you are
running the test via `make check`.

To change the level of logs output to the console, use the `-l` command line
argument.

```bash
test/functional/test_runner.py -l debug
```

To run the tests with logging output to the console, use:

```bash
test/functional/test_runner.py -l debug --tracerpc
```

To run a single test with logging output to the console, use:

```bash
test/functional/test_runner.py <testname> -l debug --tracerpc
```

To run a single test with logging output to the console and stop on the first
failure, use:

```bash
test/functional/test_runner.py <testname> -l debug --tracerpc --failfast
```

To run a single test with logging output to the console and stop on the first
failure, while also running the test in a debugger, use:

```bash
test/functional/test_runner.py <testname> -l debug --tracerpc --failfast --debug
```

##### Profiling

An easy way to profile node performance during functional tests is provided
for Linux platforms using `perf`.

Perf will sample the running node and will generate profile data in the `perf.data`
file. Then use `perf report` to generate a visualization of the data.

To pass the `--perf` flag to `test_runner.py` or `test/functional/wallet_hd.py`:

```bash
test/functional/test_runner.py --perf wallet_hd.py
```

When profiling the test_runner, the entire test suite will be run and perf will sample
any zxlod processes that appear by the test runner. The final perf profile will be
written to `perf.data` in the root of the build directory. This can be analyzed with
`perf report`:

```bash
perf report -i perf.data
```

See the [perf documentation](https://perf.wiki.kernel.org/index.php/Main_Page) for more details.

##### Valgrind

Valgrind is a tool which can help detect memory leaks and other memory problems. The test
framework accepts a `--valgrind` flag which runs all the zxlod processes under the tool. It
can be combined with the flags above to get a single test or test directory:

```bash
test/functional/test_runner.py --valgrind
test/functional/test_runner.py --valgrind wallet_hd.py
test/functional/test_runner.py --valgrind --extended
```

## Lint tests

### Dependencies

| Lint test | Dependency | Version [used by CI](../ci/lint/04_install.sh) | Installation
|-----------|:----------:|:-------------------------------------------:|--------------
| [`lint-python.sh`](lint/lint-python.sh) | [flake8](https://gitlab.com/pycqa/flake8) | [3.8.3](https://github.com/bitcoin/bitcoin/pull/19348) | `pip3 install flake8==3.8.3`
| [`lint-python.sh`](lint/lint-python.sh) | [mypy](https://github.com/python/mypy) | [0.781](https://github.com/bitcoin/bitcoin/pull/19348) | `pip3 install mypy==0.781`
| [`lint-shell.sh`](lint/lint-shell.sh) | [ShellCheck](https://github.com/koalaman/shellcheck) | [0.7.1](https://github.com/bitcoin/bitcoin/pull/19348) | [details...](https://github.com/koalaman/shellcheck#installing)
| [`lint-shell.sh`](lint/lint-shell.sh) | [yq](https://github.com/mikefarah/yq) version 3.10.0 | [3.10.0](https://github.com/bitcoin/bitcoin/pull/19348) | `pip3 install yq==3.10.0`
| [`lint-spelling.sh`](lint/lint-spelling.sh) | [codespell](https://github.com/codespell-project/codespell) | [2.0.0](https://github.com/bitcoin/bitcoin/pull/19348) | `pip3 install codespell==2.0.0`

Please be aware that on Linux distributions all dependencies are usually available as packages, but could be outdated.

### Running the tests

Individual tests can be run by directly calling the test script, e.g.:

```bash
test/lint/lint-python.sh
```

You can run all the shell-based lint tests by running:

```bash
test/lint/lint-all.sh
```

# Writing functional tests

You are encouraged to write functional tests for new or existing features.
Further information about the functional test framework and individual
tests is found in [test/functional](/test/functional).
