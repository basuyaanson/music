#include"musicplayer.h"
#include "res.h"

//初始化
musicplayer::musicplayer()
{
    Res::getres();
    curidex = 1;
    cmd.push_back("open ");
    cmd.push_back("play ");
    cmd.push_back("pause ");
    cmd.push_back("resume ");
    cmd.push_back("close ");
}



//介面
void musicplayer::menu()
{
    asciiart();
    cout << "\n------------------------------------------" << endl;
    cout << "------------陳政鴻的音樂播放器------------" << endl;
    cout << "\t\t0.退出" << endl;
    cout << "\t\t1.播放音樂" << endl;
    cout << "\t\t2.暫停" << endl;
    cout << "\t\t3.繼續" << endl;
    cout << "\t\t4.下一首" << endl;
    cout << "\t\t5.上一首" << endl;
    cout << "\t\t6.隨機播放" << endl;
    cout << "------------------------------------------" << endl;
    cout << "------------------------------------------" << endl;
}

//按鍵指令
void musicplayer::keydown()
{
    int usekey = 0;
    showmusic();
    cout << "------------------------------------------" << endl;
    cout << "\n請輸入您的選擇:";
    cin >> usekey;
    switch (usekey)
    {
    case 0:
        cout << "\n歡迎下次使用!!!";
        exit(0);
        break;
    case 1:
        playmusic();
        break;
    case 2:
        pausemusic();
        break;
    case 3:
        resumemusic();
        break;
    case 4:
        next();
        break;
    case 5:
        pre();
        break;
    case 6:
        random();
        break;
    }
}

//顯示歌單
void musicplayer::showmusic()
{

    cout << "\t\t歌單:" << endl;
    for (auto v : Res::music)
    {
        if (v.first == curidex)
        {
            cout << v.first << "\t" << v.second << "\t\t<<----------" << endl;
        }
        else
        {
            cout << v.first << "\t" << v.second << endl;
        }
    }
}

//播放
void musicplayer::playmusic()
{
    string openCmd = cmd[CMD::open] + Res::music[curidex];
    mciSendString(openCmd.c_str(), 0, 0, 0);
    string playCmd = cmd[CMD::play] + Res::music[curidex];
    mciSendString(playCmd.c_str(), 0, 0, 0);
}

//暫停
void musicplayer::pausemusic()
{
    string pauseCmd = cmd[CMD::pause] + Res::music[curidex];
    mciSendString(pauseCmd.c_str(), 0, 0, 0);
}

//繼續
void musicplayer::resumemusic()
{
    string resumeCmd = cmd[CMD::resume] + Res::music[curidex];
    mciSendString(resumeCmd.c_str(), 0, 0, 0);
}

//下一首
void musicplayer::next()
{
    string closeCmd = cmd[CMD::close] + Res::music[curidex];
    mciSendString(closeCmd.c_str(), 0, 0, 0);
    curidex == Res::music.size() ? curidex = 1 : curidex++;//防止音樂選擇超出文件夾邊界
    string openCmd = cmd[CMD::open] + Res::music[curidex];
    mciSendString(openCmd.c_str(), 0, 0, 0);
    string playCmd = cmd[CMD::play] + Res::music[curidex];
    mciSendString(playCmd.c_str(), 0, 0, 0);
}

//上一首
void musicplayer::pre()
{

    string closeCmd = cmd[CMD::close] + Res::music[curidex];
    mciSendString(closeCmd.c_str(), 0, 0, 0);
    curidex == 1 ? curidex = Res::music.size() : curidex--;//防止音樂選擇超出文件夾邊界 
    string openCmd = cmd[CMD::open] + Res::music[curidex];
    mciSendString(openCmd.c_str(), 0, 0, 0);
    string playCmd = cmd[CMD::play] + Res::music[curidex];
    mciSendString(playCmd.c_str(), 0, 0, 0);
}

//隨機播放
void musicplayer::random()
{
    string closeCmd = cmd[CMD::close] + Res::music[curidex];
    mciSendString(closeCmd.c_str(), 0, 0, 0);
    curidex = rand() % Res::music.size() + 1;
    string openCmd = cmd[CMD::open] + Res::music[curidex];
    mciSendString(openCmd.c_str(), 0, 0, 0);
    string playCmd = cmd[CMD::play] + Res::music[curidex];
    mciSendString(playCmd.c_str(), 0, 0, 0);

}

// ASCII藝術圖形(美編用)
void musicplayer::asciiart()
{
    cout << " .......%,`iW:..;:.::,..$>i>>>W:.:..:.'............ \n";
    cout << " ......:l`%W....:...;.':%>i>>/WWW%W;.:.,....:...... \n";
    cout << " ......%,W$...:...:.:`.:W>>>iW>,```WWW1.`....',;;.. \n";
    cout << " .......W....:]WWWi>>i>>`W::`.`::`:`/WW*WW.:..;:,,. \n";
    cout << " .......:...WW%ii>i>i>iiW`,;;;,,,,;,'::W.`WR...,'`: \n";
    cout << " .....:;..:WWiii>i>i>:WWW`,;,`;,;,;:::;:%:`WW...... \n";
    cout << " .....`..WW'WWRWi>;W%:```:;`;;,/,;,,,,;:::W`#W..... \n";
    cout << " .......WW%$``:`W:W``:WWW`/++1+/+/+///;;:::W.XK..., \n";
    cout << " ......$,W:,.:,,:,``WW`,:://>>i>>>>'|/+i`W:`W:`W.., \n";
    cout << " .....W:W`;:`:;/``W$,``,:W`>>'i'i>>>'>+:W:Wl:%``W., \n";
    cout << " .:.:!%`,;;,1++i`I`,,`,:,`.W`'>>>>>>!`W]`,```W:```W \n";
    cout << " ...W$:;',!1/+i>`W`,,```````%W`````'WW:````,`:```,W \n";
    cout << " ::WW`,;;//++i>>`W,,`,,````::.W%$WW.,`}``,```:,``,` \n";
    cout << " >'W%`;,//+i>>ii:%:,,`,`}.:.:````WW,``W`,`,``,:```` \n";
    cout << " ',WW`,'/1>>>ii`WK,``:::l:..:`,``W,`W`W`````,`````` \n";
    cout << " 'WW%`'//>i>i>i`W`:::::.,`::``,`~W,```W,`````,````` \n";
    cout << " ;%E``+/>>>>ii`$W;`:`:`::l``,,:`%W```,W+`,,``,:`,`` \n";
    cout << " ,WW```/ii>i>:WWi',:``,``I,`,::%'W,,`$:'```,``,`W`, \n";
    cout << " ',```````""W%,W:W`,`,,`,'`,:`;W%W``%E.%````,```>`` \n";
    cout << " ;Y`:%W$%WWW:`$W:W,,`,,,,`I:`R%WWW%WWWW$```,```%:`, \n";
    cout << " ,:`W,,`,,``,`%..W````,```1WWW$%WWWW%$%W%`,````$`,' \n";
    cout << " ;WWW;,,`,,`,W`':'W``:``,``W:.::II/YIIW%W`:,``W1'>i \n";
    cout << " ;W%%!,,`l,WW$%$%WXW%W``,```W.::~,:..~,:$,`,`,W%W}W \n";
    cout << " ;WWi~,,;]WWW%}1}:1}::WWWWW$:.:.~~,~~~..W``,``,,`>W \n";
    cout << " ;K+i>,;,%:W,W1}1`}1$..::::.:..:~''''':W,```,```,!W \n";
    cout << " ,Wii';,,;&#,111/::`W:.:.:.`.:::.:.iIW$!`,`,,`,,`>W \n";
    cout << " 'W>+>``,`W::`,,:`.,:::.::.:F..::.%,W%,`,``,,```'WW \n";
    cout << " ,W>>i,,`,W:::W`,``&~.::::F:I}.:..W>,``,,`,``,`,>W> \n";
    cout << " ;W>ii/,,,WW:.:`:&.:::.:F'''''l::`,F>,$R'>W!``,>>W> \n";
    cout << " ;W>iiW`,,,%:.l!,,,::::~>';''']::`*%>W>>>>>W``>>Wi> \n";
    cout << " ;Wi>iW,,,,`%',,,,,,:::.'';''~]..'>lW'!>>>>$`>'>W>> \n";
    cout << " W$i+>+W`,`WW$%WW$WWW:.`:'''''.,:'WW'';;~>K%>>>Wi>i \n";
    cout << " %%%Wi>iW$%R}}}}}}11W$WW.:F]X::..1W~'';;>>$K>'WE>i> \n";
    cout << " ;;WiiW%11}1]}1}1}11}*I#W%::::..:%!';;~WW!>%WWWii>R \n";
    cout << " ;;WE%]1}1}11}}}11}}1*l]*WW:.:WW%!';WW''''!!%W$>i1E \n";
    cout << " ;'&W1}}11}1}}}1}1}}}l****IWI''WW%W>!'>'''!'!%W>iWl \n";
    cout << " ;}W}}11}}1}}1}11}1}1****l**%}WWW!'!>!'!'!''''%W>WK \n";
    cout << " :W'}}}}}1}1}11}}1K}}*Il****FWW''''';'''!''}'''WW%W \n";
    cout << " %""1}}}}}1}}}}1}IKK&K&*lI*%W'~'';''~;;'''i+'!>!WWY \n";
    cout << " '''}1}}&K}11}}1}}}&KKKR**%'';';''';'''i!!W!>>'''WW \n";
    cout << " ''>}1*KKK11}1}1}}}*ll*&W%'';'';';'~'''!>'W!''>'>!% \n";
    cout << " ""}1K&&K}}]11}}&1}I**W+:$''';~'''';'''W""W""!>!""$ \n";
    cout << " ']}KKK}11}1RK}}}}*llWW'''W'~'';;';;~';$'Wl'!''!'!> \n";
    cout << " 11]&K}1}}}}}}}1}*l*%:.W;''$'~';''''''!!>W'''""'''! \n";
    cout << " }}1}}}}}}1}1}}}****W;,,W;'$';''''''''!>$';;''>!'!' \n";
    cout << " }}}}1}}}1}1}}*l**l*W;,;W''*''';;'''';WW''''''!""'' \n";
    cout << " }1}}1}}}}}}}l******WY',:%""W'''';'';>W'''''''!"""" \n";

}
