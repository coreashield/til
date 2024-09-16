// use "if"
fun main() {
    var sumValue = 0
    for (i in 1..100) {
        if (i % 2 == 0) {
            sumValue += i
        }
    }
    println(sumValue)
}

// use "when"
fun main() {
    var sumValue = 0
    for (i in 1..100) {
        when {
            i % 2 == 0 -> sumValue += i
        }
    }
    println(sumValue)
}
