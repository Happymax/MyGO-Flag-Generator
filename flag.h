#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>
#include <string.h>

#ifndef FLAG_H
#define FLAG_H

#endif //FLAG_H

#define FLAGS_COUNT 160
#define VERSION "v1.0.20231117"

typedef void (*PRINT_FLAG)(const char*);

void options(int, char**);
void flag(const char*);
void byte_flag(const char*);

struct option OPTS[] = {
        {"byte", optional_argument, 0, 'b'},
        {"lang", required_argument, 0, 'l'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
};

static const char* HELP_MSG =
        "It's MyGO!!!!! Flag Generator\n"
        VERSION "\n"
        "Usage: %s [options] <argument>\n"
        "\t[No Option]\t\t\tGenerate and print random flag in Japanese.\n"
        "\n"
        "\t-b, --byte\t<(Length)>\tPrint flag as bytes.\n"
        "\t\t\t\t\tOptionally, set <Length> to set the flag length.\n"
        "\t\t\t\t\tBy default or <Length> set to 0 it's unlimited.\n"
        "\n"
        "\t-l, --lang\t<Language>\tPrint in the selected language.\n"
        "\t\t\t\t\tAvailable languages:\n"
        "\t\t\t\t\t(J)apanese / (C)hinese\n"
        "\t\t\t\t\tOnly checks the first letter of the language argument.\n"
        "\n"
        "\t-h, --help\t\t\tPrint this manual.\n"
        "\n";

static const char* INVALID_MSG =
        "%s: invalid argument: %s %s\n";

// Lines are selected from Anime BangDream It's MyGO!!!!!
// Chinese translations found on 萌娘百科/BanG Dream! It's MyGO!!!!!/轶事/精选台词集
// https://zh.moegirl.org.cn/zh-hans/BanG_Dream!_It%27s_MyGO!!!!!/轶事

static const char* FLAGS_JP[FLAGS_COUNT] = {
        "CRYCHICを やめさせていただきます",
        "私は バンド 楽しいっておもったこと 一度もない",
        "睦ちゃんのせいじゃないよ",
        "じゃ……一生 バンドしてくれる？",
        "お友達なの",
        "そよさん Love",
        "睦 伝書鳩になってはいけませんわ",
        "燈の歌詞は心の叫びですから",
        "人間に なりたいですわ！",
        "「ボーカル必死過ぎ。」？こいつ何もわかってない ブロックしてやる",
        "ブロックよりミュートね",
        "あの…私は？",
        "おもしれえ女",
        "じゃあ ドラムの隣来る？",
        "取ってきてあげる こっそり2個ずつ",
        "燈の歌聞いたとき 自分のことだって思った",
        "迷子のままで 私たち",
        "私は祥子みたいにはできないんだよ！",
        "燈はかわいいだよ",
        "私には？私には？",
        "うるさい",
        "私は 必死にやるしかできない",
        "だって 私の歌は 心の叫びだから",
        "何でよ 何で「春日影」やったの！",
        "お願い 初華 全部 忘れさせて",
        "せめて会って謝らせてくれないかな？",
        "私もびっくりしたの、あんな事になるなんて知らなくて…",
        "だからちゃんと説明させてほしいの",
        "知ってたら止めたし、セトリはもう終わってたのに急に演奏しだして",
        "みんなを止められなくてごめんね…",
        "祥ちゃん、怒ってるよね…",
        "怒るのも当然だと思う",
        "でも信じてほしいの。春日影、本当に演奏する予定じゃなかったの",
        "本当にごめんね",
        "もう勝手に演奏したりしないって約束するよ",
        "ほかの子たちにも絶対に二度としないって約束させるから",
        "少しだけ話せない？",
        "私、CRYCHICのこと本当に大切に思ってる",
        "だから、勝手に春日影演奏されたの祥ちゃんと同じくらい辛くて",
        "私の気持ちわかってほしいの",
        "お願い。どこでも行くから",
        "バンドやらなきゃいけなかった理由もちゃんと話すから",
        "合って話せたら、きっとわかってもらえると思う",
        "私は祥ちゃんの味方だから",
        "会いたいの",
        "それは違う",
        "睦ちゃん 本当に思ったことそのまま言うよね",
        "やってほしくないことばっかり お願いしたことはやってくれないのに",
        "睦ちゃんのせいだよ あのときも 今も",
        "つまんねー女の子",
        "祥ちゃん 今日は 会ってくれてありがとう",
        "睦ちゃんを怒らないでね",
        "祥ちゃんの家にいきたいって 私が無理にお願いしたの",
        "ごめんね どうしても合って謝りたくて",
        "「春日影」 本当はやるはずじゃなかったの",
        "あの日は1曲だけお予定で",
        "私もやりたくなかった",
        "でも 演奏が始まっちゃって どうしようもなくて",
        "ごめんね 祥ちゃんのこと 傷つけたよね",
        "許してくれないのも当然だと思う",
        "私達の大事な曲を勝手に演奏することになったんだもの",
        "本当にごめんなさい",
        "おためごかしですわね",
        "演奏でしたらご自由にどうぞ お好きになさって",
        "でも 「春日影」はCRYCHICの大切な…",
        "いつまでもしがみついて みっともないですわね",
        "いい加減 あなたも忘れては",
        "どうして なんで忘れるなんて言うの",
        "私達 あんなに仲が良かったじゃない",
        "毎日楽しくて みんな一緒で",
        "離れ離れになるなんておかしいよ",
        "バンドは運命共同体だって そう言ったのは祥ちゃんじゃない",
        "運命… では あのバンドは何ですの",
        "何が違うんですの",
        "言葉と行動が矛盾していますわよ",
        "CRYCHICは壊れてしまいましたわ",
        "復活は絶対にありえません",
        "どうして",
        "お願い もう一度CRYCHICをやり直したいの",
        "楽しかったあの頃の私達に戻りたい",
        "燈ちゃんも立希ちゃんも それを望んでる",
        "睦ちゃんも呼んで 祥ちゃんにも戻ってきてもらうつもりだったんだよ",
        "そうなんですの",
        "私は…",
        "どうして 私だけなの",
        "でも CRYCHICを始めたのは 祥ちゃんだよ",
        "だから 私の手で終わらせましたわ",
        "終わってない！",
        "私は CRYCHICのために ずっと頑張ってきた",
        "誰もそんなこと頼んでませんわ",
        "これが最後通告ですわ",
        "今度こそ 私にはもう関わらないで",
        "持って 行かないで",
        "違いうの",
        "私 ほんとにみんなのことが大事で 大好きで",
        "嫌",
        "お願い 祥ちゃんたちがいないと 私…",
        "離して",
        "どうしたら戻れるの",
        "私にできることなら 何でもするから",
        "どのくらいの覚悟で言ってるんですの",
        "ただの学生でしかないあなたに 他人の人生を抱えきれますの",
        "「何でもする」とは それほど重い言葉ですのよ",
        "できもしないことを口になさないで",
        "でも 私ほんとに…",
        "あなた ご自分のことばかりですのね",
        "え……？",
        "知らない 伝書鳩にはならない",
        "誓いって あんなの嘘だよ",
        "CRYCHICには要らないよね 二人とも",
        "そうだよ",
        "最悪",
        "立希ちゃんは…燈ちゃんがいればいいんでしょ？",
        "あ…",
        "私 いらないんでしょ",
        "もうヤダ バンドなんて やりたくなかった",
        "そよ どうするの",
        "そよは 分からなくなってる",
        "あ～あ 燈ちゃんのせいだよ",
        "あんたが私を要らないって言おうが 私やるけど",
        "そうだよ 私達が始めたバンドじゃん",
        "だったら 私が終わらせてあげる",
        "ちょ…ちょっと 離して",
        "ちょ…ちょっと 勘違いしないで 終わらせに来たの",
        "「春日影」はやらないから",
        "私やめないから そよりんもやめんなよ",
        "「そよりん」はちょっと嫌かな",
        "嫌だって言ってるよね",
        "ねっ ともりん",
        "ともりん？",
        "あのちゃん",
        "あのちゃん？",
        "いつの間に…",
        "へんへん",
        "え…私は？",
        "立希ちゃん",
        "え？",
        "りっきーだよりっきー",
        "私の衣装 切れてる！？",
        "離さないでくれて ありがとう",
        "ライブどうだった",
        "良かったね",
        "睦ちゃんにだけは言われたくない",
        "これ 要らないから",
        "残りの人生 私にくださいませんか",
        "後戻りはできませんわよ",
        "祥が壊れそうだから",
        "いいご身分ですわね",
        "心配は結構",
        "弱い私は もう死にました",
        "そういう一瞬一瞬をたくさん重ねたら 一生になるんだと思う",
        "だって一生だよ 本当に死ぬまでバンドするつもり？",
        "じゃみんな 健康に気をつけないと",
        "立希ちゃん 今日は燈ちゃん 私が送ってくから",
        "ちょっと…は？",
        "多分 私の叫びでもあったの",
        "私多分 一生CRYCHICのこと忘れられないよ",
        "お幸せに",
        "心にも 絆創膏貼れたらいいのに",
        "ただいま クソ親父"
};

static const char* FLAGS_CN[FLAGS_COUNT] = {
        "我要退出CRYCHIC",
        "我一次都没有觉得乐队开心",
        "不是睦酱的错",
        "那……能陪我组一辈子的乐队吗？",
        "我们是朋友",
        "爽世桑，Love！",
        "睦，你可不能当个传信鸽哦",
        "灯的歌词是来自内心的呐喊",
        "好想成为真正的人啊！",
        "“主唱太拼命了。”？这家伙根本什么也不懂，我要拉黑他",
        "屏蔽就好了，不用拉黑哦",
        "那个……那我呢？",
        "有趣的女人",
        "那，来鼓的旁边吗？",
        "偷偷帮你去拿吧，一人两个",
        "当初听到灯的歌声时，觉得唱的就是自己",
        "就这样迷失下去吧，我们",
        "反正我就是做不到像祥子那样好啊！",
        "灯当然可爱啊",
        "那我呢？那我呢？",
        "吵死了",
        "我能做到的，只有拼命去唱",
        "因为我的歌声，就是内心的呐喊！",
        "为什么……为什么要演奏《春日影》！",
        "拜托了，初华，让我……忘记一切吧",
        "至少让我当面向你道歉好吗？",
        "我也吓了一跳，不知道事情会变成那样……",
        "所以我想好好解释一下",
        "知道的话就会阻止了，预定的曲目本来已经完了突然又开始演奏",
        "没能阻止大家很抱歉……",
        "祥酱，你生气了吧……",
        "我想生气也是自然的",
        "但请你相信。《春日影》真的并不在预定的演奏里",
        "真的很抱歉",
        "约定好了以后再也不擅自演奏了",
        "我也会约定其他人绝对不会再次这样",
        "可以跟你说些话吗？一点也行",
        "我真的觉得CRYCHIC很重要",
        "所以，擅自演奏《春日影》时我也和祥酱一样难过",
        "希望你能明白我的心情",
        "拜托了。哪里我都会去的",
        "不得不继续乐队的理由，我会好好跟你说的",
        "见面聊一聊后，我想你一定会明白的",
        "我跟祥酱是一边的",
        "想见你",
        "不是这样的",
        "睦酱，你真是想到什么说什么呢",
        "总是做些不想你做的事，明明拜托的事不愿帮忙",
        "是睦酱的错哦，那个时候是，这次也是",
        "无聊的女孩子",
        "祥酱，谢谢你今天愿意来见我",
        "请不要生睦酱的气",
        "是我硬是拜托她想来祥酱的家的",
        "抱歉，无论怎样都想当面道歉",
        "真的没打算演奏《春日影》的",
        "那天预定的只有1首曲子",
        "我也没想演奏的",
        "但是，演奏都已经开始了，实在没有办法",
        "抱歉，一定伤害到祥酱你了吧",
        "我想你不原谅也是当然的",
        "擅自演奏了我们重要的曲子",
        "真的很抱歉",
        "装作一副为了别人的样子啊",
        "想演奏是你们的自由，随你们喜欢",
        "但是，《春日影》是CRYCHIC重要的……",
        "直到现在还执迷于过去，真让人看不下去",
        "差不多，你也该忘记了吧",
        "为什么？为什么要说忘记这种话呢？",
        "我们，以前感情明明那么好",
        "每天都开心，大家在一起",
        "现在却各奔东西也太奇怪了吧",
        "“乐队是命运共同体”，这么说的人不正是祥酱吗？",
        "命运……？那么，那个乐队算什么？",
        "哪里不是？",
        "言语和行动相互矛盾",
        "CRYCHIC已经分崩离析了",
        "绝对不可能复活",
        "为什么",
        "拜托了，我想让CRYCHIC重新开始",
        "想回去我们那时候的快乐时光",
        "灯酱和立希酱也是这么期望的",
        "我也打算找睦酱和祥酱回来的",
        "是这样一回事吗？",
        "我……",
        "为什么，只有我这么想吗？",
        "但是，发起CRYCHIC的是祥酱啊",
        "正因如此，我已经亲手将她结束了",
        "没有结束！",
        "我一直为了CRYCHIC努力着",
        "谁也没有求你那样做",
        "这是最后通牒",
        "从现在开始，不要再和我扯上关系了",
        "等等，不要走",
        "不是的",
        "我，真的对大家很重视，最喜欢了",
        "不要",
        "拜托了，要是没有祥酱你们的话，我……",
        "放开",
        "要怎么做才能回来？",
        "只要是我能做的，我什么都愿意做",
        "你是抱着多大的觉悟说出这种话的？",
        "区区一介学生，有办法背负他人的人生吗？",
        "“什么都愿意做”就是这么沉重的话",
        "做不到的事情就不要说出口",
        "但是，我真的……",
        "你这个人，满脑子都只想着自己呢",
        "诶……？",
        "不知道，我不会当传信鸽的",
        "誓言什么的，那当然是骗人的啊",
        "CRYCHIC不需要吧，那两个人",
        "是啊",
        "真是差劲",
        "立希酱你……只要有灯在就够了吧？",
        "啊……",
        "我是不被需要的吧",
        "我受够了……乐队什么的，我根本不想组",
        "爽世的事，怎么办？",
        "爽世她，不知道如何是好了",
        "啊~啊~都是灯的错哦",
        "就算你说不需要我，我也会继续下去",
        "这不是由我俩开始的乐队吗？",
        "既然如此，就由我来结束掉",
        "等……等等，放开我",
        "等……等等，别误会了，我是来结束一切的",
        "《春日影》是不会再弹了",
        "我不会放弃的，Soyorin也别放弃哦",
        "“Soyorin”听起来有点讨厌耶",
        "我都说讨厌了吧",
        "对吧，Tomorin？",
        "Tomorin？",
        "Ano酱",
        "Ano酱？",
        "什么时候……？",
        "哼哼~",
        "呃……那我呢？",
        "立希酱",
        "是Rikki啦Rikki！",
        "我的衣服被剪开了！？",
        "谢谢你，没有放开我的手",
        "演出怎么样？",
        "太好了",
        "我唯独不想听到睦酱这么说",
        "这个，我不需要",
        "哈……",
        "你愿意将余下的人生交给我吗？",
        "没有回头路哦",
        "毕竟祥看起来快撑不住了",
        "还真是高高在上啊",
        "担心就免了",
        "软弱的我已经死了",
        "如果将每个一瞬累计起来，我认为就能变成一辈子",
        "因为是一辈子耶？真的到死为止都要组乐队吗？",
        "那大家，要多注意健康才行呢",
        "立希酱，今天的灯酱，就由我来送吧",
        "等等……哈？",
        "大概，那也是我的呐喊",
        "我大概一辈子都忘不了CRYCHIC吧",
        "祝你幸福",
        "要是心灵也可以贴创可贴就好了",
        "我回来了，混蛋老爸"
};
