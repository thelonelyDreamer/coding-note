package com.felixwc.java.utils.gvc;

import java.util.Random;

/**
 * in order to learn java!
 * created at 2021/6/12 18:36
 *
 * @author wangchao
 */
public class CodeStringProducer {
    private static StringBuffer template = new StringBuffer("ABCDEFGHIJKLMNPQRSTUVWXYZabcdefghijkmnpqrstuvwxyz123456789");

    public static String getCodeString(int codeCount){
        StringBuffer temp = new StringBuffer();
        Random random = new Random();
        for (int i = 0; i < codeCount; i++) {
            temp.append(template.charAt(random.nextInt(template.length())));
        }
        return temp.toString();
    }

}
