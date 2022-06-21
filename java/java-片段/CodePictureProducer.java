package com.felixwc.java.utils.gvc;

import javax.imageio.ImageIO;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Random;

/**
 * in order to learn java!
 * created at 2021/6/12 18:55
 *
 * @author wangchao
 */
public class CodePictureProducer {

    /**
     * @param targetString
     * @param width
     * @param height
     * @param lineCount
     * @return
     */
    public static BufferedImage getValidateCodeImage(String targetString, int width, int height, int lineCount) {
        if (width <= 10 || height <= 10 || targetString == null) {
            return null;
        }

        int charNum = targetString.length();
        BufferedImage bufferedImage = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);

        //定义图片上的图形和干扰线
        Graphics2D gd = bufferedImage.createGraphics();
        gd.setColor(Color.white);//将图像填充为白色
        gd.fillRect(0, 0, width, height);
//        gd.setColor(Color.BLACK);
//        gd.drawRect(0, 0, width - 1, height - 1);
        //产生干扰线
        gd.setColor(Color.gray);
        Random random = new Random();
        for (int i = 0; i < lineCount; i++) {
            int x = random.nextInt(width);
            int y = random.nextInt(height);
            int x1 = random.nextInt(width);
            int y1 = random.nextInt(height);
            gd.drawLine(x, y, x1, y1);
        }

        //设置字体
        int fontHeight = height - 10;
        Font font = new Font("Fixedsys", Font.PLAIN, fontHeight);
        gd.setFont(font);

        //设置字体位置
        int codeCount = charNum;
        int codeX;
        int codeY;
        codeX = (width - 4) / (codeCount + 1);
        codeY = height - 7;

        for (int i = 0; i < codeCount; i++) {
            int red = random.nextInt(255);
            int green = random.nextInt(255);
            int blue = random.nextInt(255);
            gd.setColor(new Color(red, green, blue));
            String strTemp = targetString.substring(i, i + 1);
            gd.drawString(strTemp, (i + 1) * codeX, codeY);
        }

        return bufferedImage;
    }

    public static BufferedImage getDefaultCodePicture(String targetString) {
        return getValidateCodeImage(targetString, 200, 20, 6);
    }

    //写成输出流
    public void write(BufferedImage bufferedImage, OutputStream outputStream) throws IOException {
        ImageIO.write(bufferedImage, "jpg", outputStream);
    }

    //
    public void saveImage(BufferedImage bufferedImage, String savePath) throws IOException {
        ImageIO.write(bufferedImage, "jpg", new File(savePath));
    }

}
