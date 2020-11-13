#!/usr/bin/python

#import sys

# Baseline data
with open("driver_noprio.txt") as driverIn:
  with open("email_noprio.txt") as benchIn:
    driverText = driverIn.read()
    # Split into lines, and only retain those that have a comma (we want CSV format only)
    driverLines = list(filter(lambda x: x.find(',') != -1, driverText.split('\n')))
    driverConfigurations = list(filter(lambda x: 'CompChunk' in x, driverLines))

    benchText = benchIn.read()
    # Split into lines, and only retain those that have a comma (we want CSV format only)
    benchLines = list(filter(lambda x: ',' in x, benchText.split('\n')))
    benchConfigurations = list(filter(lambda x: 'CompChunk' in x, benchLines))

    assert benchConfigurations == driverConfigurations, "ERROR: configs between driver and bench don't match!"

    # shorten name and make less confusing; we are guaranteed
    # benchConfigurations is the same as driverConfigurations
    configs = list(map(lambda x: x.strip(), benchConfigurations))

    # Strip whitespace from each line
    driverLines = list(map(lambda x: x.strip(), driverLines))

    # Strip whitespace from each line
    benchLines = list(map(lambda x: x.strip(), benchLines))

    currData = dict()
    currData['main'] = 'main (cilk::Low)' # not in the input, we generate this

    for conf in configs:
      currData.clear()
      tickData = ""
      currData['Params:'] = 'Params:, ' + conf
      assert driverLines[0] == conf, "ERR: extra data? Line: " + driverLines[0]
      assert benchLines[0] == conf, "ERR: extra data? Line: " + benchLines[0]
      driverLines.pop(0)
      benchLines.pop(0)
      driverCount = 0
      benchCount = 0
      while driverLines and "CompChunk" not in driverLines[0]:
        driverCount += 1
        lineSplit = driverLines.pop(0).split(',')
        currData[lineSplit[0]] = ','.join(lineSplit)
      while benchLines and "CompChunk" not in benchLines[0]:
        lineSplit = benchLines.pop(0).split(',')
        if (lineSplit[0] != "Total Ticks:"):
          benchCount += 1
          currData[lineSplit[0]] = ','.join(lineSplit)
        else:
          tickData = ','.join(lineSplit)



      params = conf.split(',')
      clientCount = "Clients ??"
      for each in params:
        if "Clients" in each:
            clientCount = each
            break
      clientCount = clientCount.replace(' ', '-')
      fileName = clientCount + '.csv'
      fileName = "email-noprio.csv"

      with open(fileName, "a") as outFile:
        outFile.write(currData['Params:'] + '\n')

        currData['main'] = "main (cilk::Low)" + ','*10 + tickData

        if driverCount + benchCount < 9:
          currData = dict(map(lambda kv: (kv[0], "ERROR") if kv[0] != "Params:" else (kv[0], kv[1]), currData.items()))

        # 2 extra item for params and main
        if len(currData) < 11:
          # 2 extra new lines
          outFile.write('\n'*12)
          continue

        outFile.write(', Avg(us), Max(us), Min(us), Stdev(us), Stdev(%), 50%(us), 90%(us), 95%(us), 99%(us)\n')
        #outFile.write(currData['Requests/Sec:'] + '\n')
        outFile.write(currData['resp (us)'] + '\n')
        outFile.write(currData['send (raw us)'] + '\n')
        outFile.write(currData['send (us/byte)'] + '\n')
        outFile.write(currData['sort (raw us)'] + '\n')
        outFile.write(currData['sort (us/msg)'] + '\n')
        outFile.write(currData['print (raw us)'] + '\n')
        outFile.write(currData['print (us/byte)'] + '\n')
        outFile.write(currData['comp (raw)'] + '\n')
        outFile.write(currData['comp (us/byte)'] + '\n')
        outFile.write('\n')


with open("driver_prio.txt") as driverIn:
  with open("email_prio.txt") as benchIn:
    driverText = driverIn.read()
    # Split into lines, and only retain those that have a comma (we want CSV format only)
    driverLines = list(filter(lambda x: x.find(',') != -1, driverText.split('\n')))
    driverConfigurations = list(filter(lambda x: 'CompChunk' in x, driverLines))

    benchText = benchIn.read()
    # Split into lines, and only retain those that have a comma (we want CSV format only)
    benchLines = list(filter(lambda x: ',' in x, benchText.split('\n')))
    benchConfigurations = list(filter(lambda x: 'CompChunk' in x, benchLines))

    assert benchConfigurations == driverConfigurations, "ERROR: configs between driver and bench don't match!"

    # shorten name and make less confusing; we are guaranteed
    # benchConfigurations is the same as driverConfigurations
    configs = list(map(lambda x: x.strip(), benchConfigurations))

    # Strip whitespace from each line
    driverLines = list(map(lambda x: x.strip(), driverLines))

    # Strip whitespace from each line
    benchLines = list(map(lambda x: x.strip(), benchLines))

    currData = dict()
    currData['main'] = 'main (cilk::Low)' # not in the input, we generate this
    for conf in configs:
      #currData.clear()
      tickData = []
      currData['Params:'] = 'Params:, ' + conf
      assert driverLines[0] == conf, "ERR: extra data? Line: " + driverLines[0]
      assert benchLines[0] == conf, "ERR: extra data? Line: " + benchLines[0]
      driverLines.pop(0)
      benchLines.pop(0)
      driverCount = 0
      benchCount = 0
      while driverLines and "CompChunk" not in driverLines[0]:
        driverCount += 1
        lineSplit = driverLines.pop(0).split(',')
        currData[lineSplit[0]] = ','.join(lineSplit)
      while benchLines and "CompChunk" not in benchLines[0]:
        lineSplit = benchLines.pop(0).split(',')
        if (lineSplit[0] != "Total Ticks:"):
          benchCount += 1
          currData[lineSplit[0]] = ','.join(lineSplit)
        else:
          tickData.append(','.join(lineSplit))

      params = conf.split(',')
      clientCount = "Clients ??"
      for each in params:
        if "Clients" in each:
            clientCount = each.strip()
            break
      clientCount = clientCount.replace(' ', '-')
      fileName = clientCount + '.csv'
      fileName = "email-prio.csv"

      with open(fileName, "a") as outFile:
        outFile.write(currData['Params:'] + '\n')
        if driverCount + benchCount < 9:
          currData = dict(map(lambda kv: (kv[0], "ERROR"), currData.items()))

        # 1 extra item for params
        if len(currData) < 11:
          # 2 extra new lines
          outFile.write('\n'*12)
          continue

        if len(tickData) == 6:
          currData['resp (us)'] = currData['resp (us)'] + ',' + tickData[0]
          currData['send (raw us)'] = currData['send (raw us)'] + ',' + tickData[1]
          currData['sort (raw us)'] = currData['sort (raw us)'] + ',' + tickData[2]
          currData['print (raw us)'] = currData['print (raw us)'] + ',' + tickData[3]
          currData['comp (raw)'] = currData['comp (raw)'] + ',' + tickData[4]
          currData['main'] = 'main (cilk::Low)' + ","*10 + tickData[5]

        outFile.write(', Avg(us), Max(us), Min(us), Stdev(us), Stdev(%), 50%(us), 90%(us), 95%(us), 99%(us)\n')
        #outFile.write(currData['Requests/Sec:'] + '\n')
        outFile.write(currData['resp (us)'] + '\n')
        outFile.write(currData['send (raw us)'] + '\n')
        outFile.write(currData['send (us/byte)'] + '\n')
        outFile.write(currData['sort (raw us)'] + '\n')
        outFile.write(currData['sort (us/msg)'] + '\n')
        outFile.write(currData['print (raw us)'] + '\n')
        outFile.write(currData['print (us/byte)'] + '\n')
        outFile.write(currData['comp (raw)'] + '\n')
        outFile.write(currData['comp (us/byte)'] + '\n')
        #outFile.write(currData['Avg Util:'] + '\n\n\n')
        outFile.write('\n')
