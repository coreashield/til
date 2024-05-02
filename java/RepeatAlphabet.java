class Repeat {
    public static void main(String[] args) {
        String a = "Happy";
        int n = 3;
			repeatCharacters(a, n);
        
    }

    public static void repeatCharacters(String str, int count) {
        for (int i = 0; i < str.length(); i++) {
            for (int j = 0; j < count; j++) {
                 System.out.print(str.charAt(i);) 
            }
        }
    }
}
