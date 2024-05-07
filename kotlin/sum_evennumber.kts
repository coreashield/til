
//use "if"
fun main() {
    var sum_value = 0
    for (i in 1..100) {
        if(i % 2 == 0){
            //println(i) //짝수 출력
            sum_value += i //짝수 합계
        }
    }
    println(sum_value)
}

//use "when"
fun main() {
    var sum_value = 0
    for (i in 1..100){
        when {
            i % 2 == 0 -> sum_value += i
            else -> continue
        }
    }
    println(sum_value)
}
