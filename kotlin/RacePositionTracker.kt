// 문제
// players 배열에는 선수들이 현재 순서대로 나열되어 있습니다.
// callings 배열에서 이름이 불릴 때마다 해당 선수가 바로 앞 선수를 추월합니다.
// 모든 호출이 끝난 후 최종 선수 순위를 반환합니다.

// 제한 조건
// players 배열의 길이: 5 ≤ players.length ≤ 50,000
// 각 선수 이름의 길이: 3 ≤ players[i].length ≤ 10 (알파벳 소문자만 포함)
// callings 배열의 길이: 2 ≤ callings.length ≤ 1,000,000
// players 배열에 중복된 이름은 없으며, 1등인 선수의 이름은 callings 배열에 포함되지 않음.

class Solution {
    fun solution(players: Array<String>, callings: Array<String>): Array<String>{
        // MutableList로 변경하여 값을 수정 가능하게 함
        val playerList = players.toMutableList()
        
        // callings 배열을 순회
        for (i in callings) {
            // 해당 플레이어의 인덱스를 찾음
            val index = playerList.indexOf(i)
            
            // 만약 인덱스가 첫 번째가 아니면 위치를 교환
            if (index > 0) {
                val temp = playerList[index - 1]
                playerList[index - 1] = playerList[index]
                playerList[index] = temp
            }
        }
        
        // 최종 배열 반환
        return playerList.toTypedArray()
    }
}
