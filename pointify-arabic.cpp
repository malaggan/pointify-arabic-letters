#include <map>
#include <vector>
#include <locale>
#include <codecvt>
#include <iostream>
#include <random>

std::map<char32_t, std::vector<char32_t>> variants = {
    {U'\U00000643' /* (ك) */,
     {U'\U000006AE' /* (ڮ) */, U'\U000006AD' /* (ڭ) */, U'\U000006AC' /* (ڬ) */,
      U'\U0000077F' /* (ݿ) */, U'\U000008B4' /* (ࢴ) */}},
    {U'\U0000062F' /* (د) */,
     {U'\U00000630' /* (ذ) */, U'\U0000068F' /* (ڏ) */, U'\U0000068E' /* (ڎ) */,
      U'\U0000068D' /* (ڍ) */, U'\U0000068C' /* (ڌ) */, U'\U0000068A' /* (ڊ) */,
      U'\U00000690' /* (ڐ) */, U'\U000008AE' /* (ࢮ) */}},
    {U'\U00000631' /* (ر) */,
     {U'\U00000632' /* (ز) */, U'\U00000699' /* (ڙ) */, U'\U00000698' /* (ژ) */,
      U'\U00000697' /* (ڗ) */, U'\U00000696' /* (ږ) */, U'\U00000694' /* (ڔ) */,
      U'\U0000076B' /* (ݫ) */}},
    {U'\U00000635' /* (ص) */,
     {U'\U00000636' /* (ض) */, U'\U0000069E' /* (ڞ) */, U'\U0000069D' /* (ڝ) */,
      U'\U000006FB' /* (ۻ) */, U'\U000008AF' /* (ࢯ) */}},
    {U'\U00000637' /* (ط) */,
     {U'\U00000638' /* (ظ) */, U'\U0000069F' /* (ڟ) */,
      U'\U000008A3' /* (ࢣ) */}},
    {U'\U00000639' /* (ع) */,
     {U'\U0000063A' /* (غ) */, U'\U000006A0' /* (ڠ) */, U'\U000006FC' /* (ۼ) */,
      U'\U0000075F' /* (ݟ) */, U'\U0000075E' /* (ݞ) */, U'\U0000075D' /* (ݝ) */,
      U'\U000008B3' /* (ࢳ) */}},
    {U'\U00000647' /* (ه) */, {U'\U00000629' /* (ة) */}},
    {U'\U0000066E' /* (ٮ) */,
     {U'\U0000062B' /* (ث) */, U'\U0000062A' /* (ت) */, U'\U00000628' /* (ب) */,
      U'\U0000067F' /* (ٿ) */, U'\U0000067E' /* (پ) */, U'\U0000067D' /* (ٽ) */,
      U'\U0000067B' /* (ٻ) */, U'\U0000067A' /* (ٺ) */, U'\U00000680' /* (ڀ) */,
      U'\U00000754' /* (ݔ) */, U'\U00000753' /* (ݓ) */, U'\U00000752' /* (ݒ) */,
      U'\U00000751' /* (ݑ) */, U'\U00000750' /* (ݐ) */}},
    {U'\U000006A1' /* (ڡ) */,
     {U'\U00000641' /* (ف) */, U'\U000006A6' /* (ڦ) */, U'\U000006A5' /* (ڥ) */,
      U'\U000006A4' /* (ڤ) */, U'\U000006A3' /* (ڣ) */, U'\U000006A2' /* (ڢ) */,
      U'\U00000761' /* (ݡ) */, U'\U00000760' /* (ݠ) */,
      U'\U000008A4' /* (ࢤ) */}},
    {U'\U0000066F' /* (ٯ) */,
     {U'\U00000642' /* (ق) */, U'\U000006A8' /* (ڨ) */, U'\U000006A7' /* (ڧ) */,
      U'\U000008A5' /* (ࢥ) */}},
    {U'\U000006BA' /* (ں) */,
     {U'\U00000646' /* (ن) */, U'\U000006BD' /* (ڽ) */, U'\U000006B9' /* (ڹ) */,
      U'\U00000767' /* (ݧ) */}},
    {U'\U00000645' /* (م) */,
     {U'\U00000766' /* (ݦ) */, U'\U00000765' /* (ݥ) */,
      U'\U000008A7' /* (ࢧ) */}},
    {U'\U00000649' /* (ى) */,
     {U'\U0000064A' /* (ي) */, U'\U000006D1' /* (ۑ) */, U'\U000006D0' /* (ې) */,
      U'\U0000063F' /* (ؿ) */, U'\U0000063E' /* (ؾ) */,
      U'\U000008A9' /* (ࢩ) */}},
    {U'\U00000633' /* (س) */,
     {U'\U00000634' /* (ش) */, U'\U0000069C' /* (ڜ) */, U'\U0000069B' /* (ڛ) */,
      U'\U0000069A' /* (ښ) */, U'\U000006FA' /* (ۺ) */, U'\U0000075C' /* (ݜ) */,
      U'\U0000076D' /* (ݭ) */}},
    {U'\U0000062D' /* (ح) */,
     {U'\U0000062E' /* (خ) */, U'\U0000062C' /* (ج) */, U'\U00000687' /* (ڇ) */,
      U'\U00000686' /* (چ) */, U'\U00000685' /* (څ) */, U'\U00000684' /* (ڄ) */,
      U'\U00000683' /* (ڃ) */, U'\U00000682' /* (ڂ) */, U'\U000006BF' /* (ڿ) */,
      U'\U00000758' /* (ݘ) */, U'\U00000757' /* (ݗ) */,
      U'\U000008A2' /* (ࢢ) */}},
    {U'\U00000644' /* (ل) */,
     {U'\U000006B8' /* (ڸ) */, U'\U000006B6' /* (ڶ) */}},
    {U'\U00000648' /* (و) */,
     {U'\U000006CF' /* (ۏ) */, U'\U000006CB' /* (ۋ) */, U'\U000006CA' /* (ۊ) */,
      U'\U000008AB' /* (ࢫ) */}}};


std::map<char32_t, char32_t> depointify_map = {{U'ذ', U'د'},
                                               {U'ز', U'ر'},
                                               {U'ض', U'ص'},
                                               {U'ظ', U'ط'},
                                               {U'غ', U'ع'},
                                               {U'ة', U'ه'},
                                               {U'ب', U'ٮ'},
                                               {U'ت', U'ٮ'},
                                               {U'ث', U'ٮ'},
                                               {U'ف', U'ڡ'},
                                               {U'ق', U'ٯ'},
                                               {U'ن', U'ں'},
                                               {U'ي', U'ى'},
                                               {U'ش', U'س'},
                                               {U'ج', U'ح'},
                                               {U'خ', U'ح'}};

int main() {
    using namespace std;

    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

    string u8input;
    getline(cin, u8input);
    wstring_convert<codecvt_utf8<char32_t>, char32_t> utf32conv;
    u32string u32input = utf32conv.from_bytes(u8input);

    u32string u32output;
    
    for (char32_t input_char : u32input) {
        if (depointify_map.count(input_char)) {
            input_char = depointify_map.at(input_char);
        }        
        
        char32_t output_char = input_char;
        if (variants.count(input_char)) {
            const vector<char32_t> &variants = ::variants.at(input_char);
            std::uniform_int_distribution<> rand_index_distribution(0, variants.size());
            int index = rand_index_distribution(gen);
            if (index < variants.size()) {
                output_char = variants.at(index);
            }
        }
        u32output += output_char;
    }

    string u8output = utf32conv.to_bytes(u32output);
    cout << u8output;
    
    return 0;
}
