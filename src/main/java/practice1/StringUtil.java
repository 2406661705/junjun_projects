package practice;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

public class StringUtil {
    public static String reverseString(String input) {
        char[] chars = input.toCharArray();
        for (int i = 0; i < chars.length / 2; i++) {
            char temp = chars[i];
            chars[i] = chars[chars.length - i - 1];
            chars[chars.length - i - 1] = temp;
        }
        return new String(chars);
    }

    public static Map<Character, Integer> countLetters(String input) {
        Map<Character, Integer> result = new HashMap<>();
        char[] letters = input.toCharArray();
        for (char letter : letters) {
            if (Character.isLetter(letter)) {
                letter = Character.toLowerCase(letter);
                result.put(letter, result.getOrDefault(letter, 0) + 1);
            }
        }
        return result;
    }

    public static void printMostFrequentLetter(String input) {
        String filtered = input.replaceAll("[^a-zA-Z]", "");
        if (filtered.isEmpty()) {
            System.out.print("no alpha\n");
            return;
        }
        Map<Character, Integer> freq = new HashMap<>();
        for (char c : filtered.toCharArray()) {
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }
        char maxChar = '\0';
        int maxFreq = 0;
        for (Map.Entry<Character, Integer> entry : freq.entrySet()) {
            char c = entry.getKey();
            int f = entry.getValue();
            if (f > maxFreq || (f == maxFreq && c < maxChar)) {
                maxChar = c;
                maxFreq = f;
            }
        }
        System.out.printf("%c %d\n", maxChar, maxFreq);
    }

    public static int longestSubstring(String input) {
        int start = 0, end = 0;
        int maxLength = 0;
        HashSet<Character> set = new HashSet<>();
        while (end < input.length()) {
            if (!set.contains(input.charAt(end))) {
                set.add(input.charAt(end++));
                maxLength = Math.max(maxLength, end - start);
            } else {
                set.remove(input.charAt(start++));
            }
        }
        return maxLength;
    }

}


