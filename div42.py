t = int(input())
for _ in range(t):
    n,m,k = map(int,input().split())
    robot=list(map(int,input().split()))
    spike=list(map(int,input().split()))
    ins=(input())

    l=[]

    for i in robot:
        id=0
        while True:
            id+=1
            if i not in spike:

                for j in ins:
                    if j=="L":
                        i-=1
                        
                    else:
                        i+=1
            
            else:
                l.append(id)
                break

              



    for i in range(k):
        


    print(*l)
         

    
    

    