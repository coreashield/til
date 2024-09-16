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
    fun solution(players: Array<String>, callings: Array<String>): Array<String> {
        // MutableList로 플레이어 목록을 유지
        val playerList = players.toMutableList()
        
        // 선수 이름과 인덱스를 매핑하는 해시맵 생성
        val playerIndexMap = mutableMapOf<String, Int>()
        for (i in players.indices) {
            playerIndexMap[players[i]] = i
        }

        // callings 배열을 순회
        for (i in callings) {
            // 현재 선수의 인덱스를 맵에서 가져옴
            val index = playerIndexMap[i] ?: continue
            
            // 만약 인덱스가 첫 번째가 아니면 위치를 교환
            if (index > 0) {
                // 앞의 선수와 현재 선수의 위치를 교환
                val previousPlayer = playerList[index - 1]
                playerList[index - 1] = i
                playerList[index] = previousPlayer
                
                // 맵에서 인덱스 업데이트
                playerIndexMap[i] = index - 1
                playerIndexMap[previousPlayer] = index
            }
        }

        // 최종 배열 반환
        return playerList.toTypedArray()
    }
}

