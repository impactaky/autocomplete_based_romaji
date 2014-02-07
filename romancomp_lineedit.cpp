#include "romancomp_lineedit.h"
#include <QListView>

const std::map<const std::string, const QString> roman_table = {
	{"va" , "ヴァ"}, {"vi" , "ヴィ"}, {"vu" , "ヴ"  }, {"ve" , "ヴェ"}, {"vo" , "ヴォ"},
	{"vya", "ヴャ"}, {"vyi", "ヴィ"}, {"vyu", "ヴュ"}, {"vye", "ヴェ"}, {"vyo", "ヴョ"},
	{"kya", "キャ"}, {"kyi", "キィ"}, {"kyu", "キュ"}, {"kye", "キェ"}, {"kyo", "キョ"},
	{"gya", "ギャ"}, {"gyi", "ギィ"}, {"gyu", "ギュ"}, {"gye", "ギェ"}, {"gyo", "ギョ"},
	{"sya", "シャ"}, {"syi", "シィ"}, {"syu", "シュ"}, {"sye", "シェ"}, {"syo", "ショ"},
	{"sha", "シャ"}, {"shi", "シ"  }, {"shu", "シュ"}, {"she", "シェ"}, {"sho", "ショ"},
	{"zya", "ジャ"}, {"zyi", "ジィ"}, {"zyu", "ジュ"}, {"zye", "ジェ"}, {"zyo", "ジョ"},
	{"tya", "チャ"}, {"tyi", "チィ"}, {"tyu", "チュ"}, {"tye", "チェ"}, {"tyo", "チョ"},
	{"cha", "チャ"}, {"chi", "チ"  }, {"chu", "チュ"}, {"che", "チェ"}, {"cho", "チョ"},
	{"cya", "チャ"}, {"cyi", "チィ"}, {"cyu", "チュ"}, {"cye", "チェ"}, {"cyo", "チョ"},
	{"dya", "ヂャ"}, {"dyi", "ヂィ"}, {"dyu", "ヂュ"}, {"dye", "ヂェ"}, {"dyo", "ヂョ"},
	{"tsa", "ツァ"}, {"tsi", "ツィ"},                  {"tse", "ツェ"}, {"tso", "ツォ"},
	{"tha", "テャ"}, {"thi", "ティ"}, {"thu", "テュ"}, {"the", "テェ"}, {"tho", "テョ"},
									 {"t'i", "ティ"}, {"t'yu","テュ"},
	{"dha", "デャ"}, {"dhi", "ディ"}, {"dhu", "デュ"}, {"dhe", "デェ"}, {"dho", "デョ"},
									 {"d'i", "ディ"}, {"d'yu","デュ"},
	{"twa", "トァ"}, {"twi", "トィ"}, {"twu", "トゥ"}, {"twe", "トェ"}, {"two", "トォ"},
																		{"t'u", "トゥ"},
	{"dwa", "ドァ"}, {"dwi", "ドィ"}, {"dwu", "ドゥ"}, {"dwe", "ドェ"}, {"dwo", "ドォ"},
																		{"d'u", "ドゥ"},
	{"nya", "ニャ"}, {"nyi", "ニィ"}, {"nyu", "ニュ"}, {"nye", "ニェ"}, {"nyo", "ニョ"},
	{"hya", "ヒャ"}, {"hyi", "ヒィ"}, {"hyu", "ヒュ"}, {"hye", "ヒェ"}, {"hyo", "ヒョ"},
	{"bya", "ビャ"}, {"byi", "ビィ"}, {"byu", "ビュ"}, {"bye", "ビェ"}, {"byo", "ビョ"},
	{"pya", "ピャ"}, {"pyi", "ピィ"}, {"pyu", "ピュ"}, {"pye", "ピェ"}, {"pyo", "ピョ"},
	{"fa" , "ファ"}, {"fi" , "フィ"}, {"fu" , "フ"  }, {"fe" , "フェ"}, {"fo" , "フォ"},
	{"fya", "フャ"},                  {"fyu", "フュ"},                  {"fyo", "フョ"},
	{"hwa", "ファ"}, {"hwi", "フィ"}, {"hwyu","フュ"}, {"hwe", "フェ"}, {"hwo", "フォ"},
	{"mya", "ミャ"}, {"myi", "ミィ"}, {"myu", "ミュ"}, {"mye", "ミェ"}, {"myo", "ミョ"},
	{"rya", "リャ"}, {"ryi", "リィ"}, {"ryu", "リュ"}, {"rye", "リェ"}, {"ryo", "リョ"},
	{"a"  , "ア"  }, {"i"  , "イ"  }, {"u"  , "ウ"  }, {"e"  , "エ"  }, {"o"  , "オ"  },
	{"wa" , "ワ"  }, {"wi" , "ウィ"}, {"wu" , "ウ"  }, {"we" , "ウェ"}, {"wo" , "ヲ"  },
	{"xa" , "ァ"  }, {"xi" , "ィ"  }, {"xu" , "ゥ"  }, {"xe" , "ェ"  }, {"xo" , "ォ"  },
	{"la" , "ァ"  }, {"li" , "ィ"  }, {"lu" , "ゥ"  }, {"le" , "ェ"  }, {"lo" , "ォ"  },
	{"lya", "ャ"  }, {"lyi", "ィ"  }, {"lyu", "ュ"  }, {"lye", "ェ"  }, {"lyo", "ョ"  },
	{"xya", "ャ"  }, {"xyi", "ィ"  }, {"xyu", "ュ"  }, {"xye", "ェ"  }, {"xyo", "ョ"  },
	{"ka" , "カ"  }, {"ki" , "キ"  }, {"ku" , "ク"  }, {"ke" , "ケ"  }, {"ko" , "コ"  },
	{"lka", "ヵ"  },                                   {"lke", "ヶ"  },
	{"xka", "ヵ"  },                                   {"xke", "ヶ"  },
	{"ga" , "ガ"  }, {"gi" , "ギ"  }, {"gu" , "グ"  }, {"ge" , "ゲ"  }, {"go" , "ゴ"  },
	{"sa" , "サ"  }, {"si" , "シ"  }, {"su" , "ス"  }, {"se" , "セ"  }, {"so" , "ソ"  },
	{"ca" , "カ"  }, {"ci" , "シ"  }, {"cu" , "ク"  }, {"ce" , "セ"  }, {"co" , "コ"  },
	{"qa" , "クァ"}, {"qi" , "クィ"}, {"qu" , "ク"  }, {"qe" , "クェ"}, {"qo" , "クォ"},
	{"kwa", "クァ"}, {"kwi", "クィ"},                  {"kwe", "クェ"}, {"kwo", "クォ"},
	{"za" , "ザ"  }, {"zi" , "ジ"  }, {"zu" , "ズ"  }, {"ze" , "ゼ"  }, {"zo" , "ゾ"  },
	{"ja" , "ジァ"}, {"ji" , "ジ"  }, {"ju" , "ジュ"}, {"je" , "ジェ"}, {"jo" , "ジョ"},
	{"jya", "ジァ"}, {"jyi", "ジィ"}, {"jyu", "ジュ"}, {"jye", "ジェ"}, {"jyo", "ジョ"},
	{"ta" , "タ"  }, {"ti" , "チ"  }, {"tu" , "ツ"  }, {"te" , "テ"  }, {"to" , "ト"  }, {"tsu", "ツ"  },
	{"da" , "ダ"  }, {"di" , "ヂ"  }, {"du" , "ヅ"  }, {"de" , "デ"  }, {"do" , "ド"  },
	{"na" , "ナ"  }, {"ni" , "ニ"  }, {"nu" , "ヌ"  }, {"ne" , "ネ"  }, {"no" , "ノ"  },
	{"ha" , "ハ"  }, {"hi" , "ヒ"  }, {"hu" , "フ"  }, {"he" , "ヘ"  }, {"ho" , "ホ"  },
	{"ba" , "バ"  }, {"bi" , "ビ"  }, {"bu" , "ブ"  }, {"be" , "ベ"  }, {"bo" , "ボ"  },
	{"pa" , "パ"  }, {"pi" , "ピ"  }, {"pu" , "プ"  }, {"pe" , "ペ"  }, {"po" , "ポ"  },
	{"ma" , "マ"  }, {"mi" , "ミ"  }, {"mu" , "ム"  }, {"me" , "メ"  }, {"mo" , "モ"  },
	{"ya" , "ヤ"  },                  {"yu" , "ユ"  }, {"ye" , "イェ"}, {"yo" , "ヨ"  },
	{"ra" , "ラ"  }, {"ri" , "リ"  }, {"ru" , "ル"  }, {"re" , "レ"  }, {"ro" , "ロ"  },
	{"wha", "ウァ"}, {"whi", "ウィ"}, {"whu", "ウ"  }, {"whe", "ウェ"}, {"who", "ウォ"},

	{"xwa", "ヮ"  }, {"lwa", "ヮ"  },
	{"xtu", "ッ"  }, {"ltu", "ッ"  },
	{"xtsu","ッ"  }, {"ltsu","ッ"  },
	{"gwa", "グァ"},
	{"nn" , "ン"  }, {"xn" , "ン"  },
	{"-"  , "ー"  },
};

QString RomanCompLineEdit::romanToKatakana (const QString &roman) const {
	std::string tmp_str;
	QString katakana;
	std::string hoge = roman.toUtf8().constData();
	for (auto c : hoge) {
		tmp_str += c;
		switch (c) {
			case 'a': case 'i': case 'u': case 'e': case 'o': case 'n': case'-':
				if (roman_table.count(tmp_str)) {
					katakana += roman_table.at(tmp_str);
					tmp_str.clear();
				}
				break;
			default:
				if (tmp_str[tmp_str.size()-2] == 'n') {
					katakana += "ン";
					tmp_str = c;
				}
				else if (tmp_str[tmp_str.size()-2] == c) {
					katakana += "ッ";
					tmp_str.erase(tmp_str.size()-1);
				}
				break;
		}
	}
	return katakana;
}

void RomanCompLineEdit::prefixToKatakana (const QString &completionPrefix) {
	std::cout << completionPrefix.toUtf8().constData() << std::endl;
	if (completionPrefix.length()<3) {
		c.popup()->hide();
		return;
	}
	if (completionPrefix[0] > 128) {
		c.setCompletionPrefix(completionPrefix);
	}
	else {
		c.setCompletionPrefix(romanToKatakana(completionPrefix));
	}
	c.complete();
}

RomanCompLineEdit::RomanCompLineEdit(QWidget *parent) :
	QLineEdit(parent)
{
	c.setWidget(this);
	connect(this,SIGNAL(textEdited(QString)),
					this,SLOT(prefixToKatakana(QString)));
	connect(&c, SIGNAL(activated(QString)),
					this, SLOT(setText(QString)));
}
