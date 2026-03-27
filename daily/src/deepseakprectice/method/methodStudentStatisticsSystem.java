package deepseakprectice.method;

import java.util.Arrays;
import java.util.Scanner;

public class methodStudentStatisticsSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        System.out.println("请输入学生个数");
        int num = sc.nextInt();
        int[] score = new int[num];
        inputScores(score, num, sc);
        for (int i = 0; i < num; i++) {
            System.out.print(score[i] + " ");
        }
        System.out.println(Arrays.toString(score));

    }

    static void inputScores(int[] score , int num , Scanner sc) {
        System.out.println("请输入学生成绩");
        for (int i = 0; i < num; i++) {
            score[i] = sc.nextInt();
        }
    }
}
