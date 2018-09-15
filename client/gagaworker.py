from __future__ import print_function
import time
import random
from random import randint
import zmq
import json

class GAGAWorker:
    def __init__(self,serverAddress, evaluationFunc, batchSize = 1, identity = u""):
        self.context = zmq.Context.instance()
        self.socket = self.context.socket(zmq.REQ)
        self.identity = identity + u"-%04x-%04x" % (randint(0, 0x10000), randint(0, 0x10000))
        self.socket.setsockopt_string(zmq.IDENTITY, self.identity)
        self.socket.connect(serverAddress)
        self.batchSize = batchSize
        self.evaluationFunc = evaluationFunc

    def start(self):
        while True:
            req = {'req':'READY', 'qtty':self.batchSize}
            self.socket.send(bytes(json.dumps(req)))
            strRep = self.socket.recv()
            rep = json.loads(strRep)
            if rep['req'] == 'EVAL':
                dnaList = [i['dna'] for i in rep['individuals']]
                results = self.evaluationFunc(dnaList)
                assert len(results) == len(dnaList)
                individuals = []
                for i, r in enumerate(results):
                    ind = {'id':rep['individuals'][i]['id']}
                    ind.update(r)
                    individuals.append(ind)
                reply = {'req':'RESULT', 'individuals':individuals}
                self.socket.send(bytes(json.dumps(reply)))
                self.socket.recv() #ACK


