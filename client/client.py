from gagaworker import GAGAWorker
import time



# example of eval function; receives a list of dnas (already parsed y json)
def maxSum(dnaList):
    return [{'fitnesses':{'sum':sum(i['values'])}} for i in dnaList]

# worker creation
worker = GAGAWorker("tcp://localhost:4321", maxSum, batchSize = 20)

worker.start()
