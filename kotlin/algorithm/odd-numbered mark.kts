    var n = 11
    var star = "*"

    for (i in 1..n){
        if(i % 2 == 1){
            for(j in 1..i){
                if( j == i){
                    print(star + "\n")
                }
                else{
                    print(star)
                }
            }
        }
    }
