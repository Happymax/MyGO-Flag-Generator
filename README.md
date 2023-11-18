# It's MyGO!!!!! 旗帜生成器 Flag Generator
基于MyGO!!!!!超重力台词的随机旗帜生成器，支持中日文台词及限定长度的byte模式。<br>
A simple random flag generator based on selected lines from anime BangDream It's MyGO!!!!! 
Supports both original Japanese lines and translated Chinese lines, as well as bytes of a target length. 

<details>
<summary><b>这里真的没有人破防</b></summary>
flag{何でよ 何で「春日影」やったの！}
</details>

## 示例 Usage
~~~
❯ ./flag
flag{睦ちゃんも呼んで 祥ちゃんにも戻ってきてもらうつもりだったんだよ}
❯ ./flag
flag{うるさい}
❯ ./flag -l j
flag{祥ちゃんの家にいきたいって 私が無理にお願いしたの}
❯ ./flag -l j
flag{あなた ご自分のことばかりですのね}
❯ ./flag -l c
flag{不是睦酱的错}
❯ ./flag -l c
flag{总是做些不想你做的事，明明拜托的事不愿帮忙}
❯ ./flag -l c
flag{有趣的女人}
❯ ./flag -l c
flag{你是抱着多大的觉悟说出这种话的？}
❯ ./flag -b
flag{e79fa5e381a3e381a6e3819fe38289e6ada2e38281e3819fe38197e38081e382bbe38388e383aae381afe38282e38186e7b582e3828fe381a3e381a6e3819fe381aee381abe680a5e381abe6bc94e5a58fe38197e381a0e38197e381a6}
❯ ./flag -b 18
flag{e3819de38186e381a0e382880f0f0f0f0f0f}
❯ ./flag -b 18 -l c
flag{e68b9ce68998e4ba86e38082e593aae9878c}
❯ ./flag -b 18 -l j
flag{e78788e381a1e38283e38293e38282e7ab8b}
~~~

## 兼容性 Compatibility
macOS & Linux<br>
Tested on macOS 14 (arm and x86) and Arch Linux (Linux 6.5.8)

<!--flag{e381ade381a320e381a8e38282e3828ae38293}-->
