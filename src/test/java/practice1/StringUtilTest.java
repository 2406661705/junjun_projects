package practice;

import org.junit.Test;

import java.io.ByteArrayOutputStream;
import java.io.PrintStream;
import java.util.Map;
import static org.junit.Assert.*;

public class StringUtilTest {

    @Test
    public void testReverseString(){
            StringUtil stringUtil = new StringUtil();
            String input = "hello world";
            String expected = "dlrow olleh";
            String actual = stringUtil.reverseString(input);
            assertEquals(expected, actual);
            System.out.println(actual);
    }

    @Test
    public void testCountLetters() {
        StringUtil stringUtil = new StringUtil();
        String input = "hello";
        Map<Character, Integer> result = stringUtil.countLetters(input);
        assertEquals(4, result.size());
        assertEquals(2, result.get('l').intValue());
        assertEquals(1, result.get('h').intValue());
        System.out.println(result.size());
        System.out.println(result);
    }

    @Test
    public void testPrintMostFrequentLetter() {
        /*
        StringUtil stringUtil = new StringUtil();
        String input = "bbgggh";

         */
        StringUtil.printMostFrequentLetter("aabbbc");
        assertEquals("b 3\n", captureOutput(() ->StringUtil.printMostFrequentLetter("aabbbc")));

        assertEquals("d 2\n", captureOutput(() -> StringUtil.printMostFrequentLetter("abcdd")));
        assertEquals("no alpha\n", captureOutput(() -> StringUtil.printMostFrequentLetter("1234")));
        assertEquals("no alpha\n", captureOutput(() -> StringUtil.printMostFrequentLetter("!@#$")));

    }
        private String captureOutput(Runnable action) {
            ByteArrayOutputStream out = new ByteArrayOutputStream();
            System.setOut(new PrintStream(out));
            action.run();
            System.setOut(System.out);
            return out.toString();
        }

    @Test
    public void testLongestSubstring() {
        assertEquals(3, StringUtil.longestSubstring("abcabcbb"));
        assertEquals(1, StringUtil.longestSubstring("bbbbb"));
        assertEquals(3, StringUtil.longestSubstring("pwwkew"));
        assertEquals(0, StringUtil.longestSubstring(""));
    }

}
