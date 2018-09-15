#Install

Requires zeromq and boost to be installed.

- `git clone` this repo
- `mkdir build`
- `cd build`
- `cmake ..`
- `make`


#Usage

##gagaserver

All dynamic parameters of gagaserver can be passed through the CLI. See
src/config.hpp fo both static (the dna type) and dynamics parameters list.

Example:

``` gagaserver --popSize 300 --verbosity 3 --nbGenerations 500 ```

The evolutionnary results will be written in ../evos by default

If you want to use novelty, don't forget to `ga.enableNovelty()` in the
main.cpp. See GAGA's readme for an exhaustive list of options.

##client 

Client code is available for python (it should be easy to write other clients
in any language that has a port of zeromq) in the client directory
(gagaworker.py) A basic example is also available in client.py.

If you want to try the basic example, just start one or several clients
(`python client.py`) and (in another terminal session), start the gagaserver
(`./gagaserver`).  The whole thing should optimize for the dna with the biggest
sum. You can start clients and server in any order, it doesn't matter. Although
at the moment you still have to remember to manually kill the clients when the
GA is done.




