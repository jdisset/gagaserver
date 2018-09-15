from gagaworker import GAGAWorker



# example of eval function
def maxSum(dnaList):
    return [{'fitnesses':{'sum':sum(i['values'])}} for i in dnaList]

worker = GAGAWorker("tcp://localhost:4321", maxSum, batchSize = 20, identity = "pythonWorker")
worker.start()
