package com.example.mbti

open class Mbti(
    open var name: String,
    open var myMbti: String,
    open var myMbtiType : String
) {
    open fun introduce() {
        println("내 이름은 ${name}, 내 mbti는 ${myMbti}. ${myMbtiType} 이라고도 함")
    }

    open fun introducePersonality(personality: String) {
        println("나는 ${personality}")
    }
}

class Analysts(name: String = "Unknown") : Mbti(name, myMbti = "INTJ", myMbtiType = "분석가")
class Diplomats(name: String = "Unknown") : Mbti(name, myMbti = "INFP", myMbtiType = "외교관")
class Sentinels(name: String = "Unknown") : Mbti(name, myMbti = "ESTJ", myMbtiType = "경영자")
class Explorers(name: String = "Unknown") : Mbti(name, myMbti = "ISTP", myMbtiType = "모험가")

fun main() {
    val person1 = Analysts("Alice")
    val person2 = Diplomats("Bob")
    val person3 = Sentinels("Charlie")
    val person4 = Explorers("David")

    person1.introduce()
    person1.introducePersonality("행동에 있어 자신감 있고 분석적이며 야심찬 경향이 있음")

    person2.introduce()
    person2.introducePersonality("언뜻 보기에 조용하고 자신을 내세우지 않는 것처럼 보이지만, 사실은 에너지와 열정이 넘치는 마음을 지닌 성격임")

    person3.introduce()
    person3.introducePersonality("통과 질서를 중시하는 성격임")

    person4.introduce()
    person4.introducePersonality("호기심이 많고 실용적이며 행동에 자신감이 있는 경향")
}
