import json

newData =[]

fileName ="txn_mapping.json"
with open(fileName) as file:
    data  = json.load(file)

    keys = sorted(data[0],reverse=True)
    for obj in data:
        newObj = dict()
        for j in keys:
            newObj[j] = obj[j]
        newData.append(newObj)

with open(fileName,'r+') as file:
    json.dump(newData, file, indent=2)
