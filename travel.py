n_airlines = int(input()) # number of airlines
airlines = []
for i in range(n_airlines):
    li = []
    l = input()
    # store the incoming and outgoing in small list (li)
    m = input()
    li.append(m)
    m = input()
    li.append(m)
    # add all data to biger list (airlines)
    airlines.append(li)
    
    
# count the output cases
count = 0

for case in airlines: # check each case

    count += 1
    print(f"Case #{count}:")
    
    for i in range(len(case[0])):
        
        out = ""
        # check  the previous airlines
        for k in reversed(range(i)):
            
            if (case[1][k+1]=="N"): 
                out = "N"*(k+1) + out
                break
            
            elif (case[1][k+1]=="Y" and case[0][k]=="Y"):
                out = "Y" + out
                
            else :
                out = "N"*(k+1) + out
                break
       
        # check the next airlines
        for j in range(i,len(case[0])):
            
            if ( i == j):
                out += "Y"
                continue
            
            if (case[1][j-1]=="N"):
                out += "N"*(len(case[0])-j)
                break
            
            elif (case[1][j-1]=="Y" and case[0][j]=="Y"):
                out += "Y"
                
            else :
                out += "N"*(len(case[0])-j)
                break
            
        print(out)
                
                
            
                
            


