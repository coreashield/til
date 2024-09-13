public class FindMissingNumber {

    public static int findMissingNumber(int[] nums, int n) {
        // 전체 합 구하기
        int totalSum = n * (n + 1) / 2;
        // 배열의 합 구하기
        int arraySum = 0;
        for (int num : nums) {
            arraySum += num;
        }
        // 전체 합에서 배열의 합을 빼면 빠진 숫자가 나옵니다.
        return totalSum - arraySum;
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 4, 5, 6}; // 예시 배열
        int n = 6; // 배열의 최대 숫자
        int missingNumber = findMissingNumber(nums, n);
        System.out.println("빠진 숫자: " + missingNumber);
    }
}
