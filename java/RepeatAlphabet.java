class Repeat {
    public static void main(String[] args) {
        String a = "Happy";
        int n = 3;
        System.out.println(repeatCharacters(a, n));
    }

    public static String repeatCharacters(String str, int count) {
        String returnValue = "";
        for (int i = 0; i < str.length(); i++) {
            for (int j = 0; j < count; j++) {
                returnValue = returnValue + str.charAt(i);
            }
        }
        return returnValue;
    }
}
