/**
 * 주어진 문자열 t와 p를 이용하여, 문자열 t에서 p와 같은 길이의 모든 부분 문자열을 추출하고,
 * 이 부분 문자열들이 정수로 변환했을 때 p를 정수로 변환한 값보다 작거나 같은 경우의 개수를 반환합니다.
 * 
 * @param t 비교할 문자열
 * @param p 기준 문자열
 * @return p보다 작거나 같은 부분 문자열의 개수
 */

fun solution(t: String, p: String): Int {
    var answer: Int = 0
    val lengthCnt: Int = p.length
    val intValue: Int = p.toInt()
    
    // 문자열 t의 모든 길이 lengthCnt 부분 문자열을 비교
    for (startNo in 0..(t.length - lengthCnt)) {
        val comparedNo: String = t.substring(startNo, startNo + lengthCnt)
        if (comparedNo.toInt() <= intValue) {
            answer += 1
        }
    }
    
    return answer
}

// 예제 테스트
fun main() {
    val t = "3141592"
    val p = "271"
    println("Result: ${solution(t, p)}")  // Expected output: 2
}
