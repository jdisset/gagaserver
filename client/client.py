from gagaworker import GAGAWorker
import json
import time



# example of eval function; receives a list of dnas (already parsed y json)
def maxSum(dnaList):
    parsedList = [json.loads(i) for i in dnaList]
    r= [{'fitnesses':{'sum':sum(i['values'])}} for i in parsedList]
    print(json.dumps(r))
    return r

# worker creation
worker = GAGAWorker("tcp://localhost:4321", maxSum, batchSize = 20)

worker.start()
