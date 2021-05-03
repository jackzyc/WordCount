package wordtest;

import java.io.*;
import java.util.*;


public class countest {
    public static void main(String[] args) {
        Scanner Input = new Scanner(System.in);
        String str = Input.nextLine();
        String array[] = str.split(" ");
        String parameter = array[0]; //控制参数
        String Name = array[1];//文件名称

        File cata = new File("wordcount/src/wordtest");//cata为执行程序所在目录
        File listFile[] = cata.listFiles();
        File flo = null;     //创建空文本以存储需要统计的文本内容

        for(File temfile :listFile)  //根据文件名称检索到对应文件并读取全部内容
        {
            if(temfile.isFile() && Name.equals(temfile.getName())){
                flo=temfile.getAbsoluteFile();
                break;
            }
        }

        try
        {
            char Ascii;
            char code=' ';
            int charcount = 0;//字符数
            int wordcount = 0; //单词数

            FileReader Filer = new FileReader(flo);
            BufferedReader Buffer = new BufferedReader(Filer);

            while((Ascii = (char) Buffer.read()) != (char)-1)//按字符读取文本内容
            {
                charcount++;//字符数，回车占2个字符
                if((Ascii>=33&&Ascii<=43)||(Ascii>=45&&Ascii<=126)&&((code==' ')||(code==',')))
                {
                    wordcount++;//单词数
                }
                code=Ascii;
            }

            if(parameter.equals("-c"))
                System.out.println("字符数："+charcount);
            else  if(parameter.equals("-w"))
                System.out.println("单词数："+wordcount);

            Buffer.close();
            Filer.close();
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
}