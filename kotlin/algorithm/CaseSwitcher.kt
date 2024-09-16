fun main(args: Array<String>) {
    val s1 = readLine()!!
   
    for (i in 0..s1.length - 1)
        if (s1[i].isUpperCase()){
            print(s1[i].toLowerCase())
        }else{
             print(s1[i].toUpperCase())
        }
}
