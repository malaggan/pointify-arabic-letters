#include <algorithm>
#include <codecvt>
#include <iostream>
#include <locale>
#include <map>
#include <random>
#include <vector>

static std::map<wchar_t, wchar_t> depointify_map;
static std::map<wchar_t, std::vector<wchar_t>> variants;

void init() {
    depointify_map = {{u'ذ', u'د'}, {u'ز', u'ر'}, {u'ض', u'ص'}, {u'ظ', u'ط'}, {u'غ', u'ع'}, {u'ة', u'ه'},
                      {u'ب', u'ٮ'}, {u'ت', u'ٮ'}, {u'ث', u'ٮ'}, {u'ف', u'ڡ'}, {u'ق', u'ٯ'}, {u'ن', u'ں'},
                      {u'ي', u'ى'}, {u'ش', u'س'}, {u'ج', u'ح'}, {u'خ', u'ح'}};
    variants = {
            {u'\u0643' /* (ك) */,
             {u'\u06AE' /* (ڮ) */, u'\u06AD' /* (ڭ) */, u'\u06AC' /* (ڬ) */, u'\u077F' /* (ݿ) */,
              u'\u08B4' /* (ࢴ) */}},
            {u'\u062F' /* (د) */,
             {u'\u0630' /* (ذ) */, u'\u068F' /* (ڏ) */, u'\u068E' /* (ڎ) */, u'\u068D' /* (ڍ) */, u'\u068C' /* (ڌ) */,
              u'\u068A' /* (ڊ) */, u'\u0690' /* (ڐ) */, u'\u08AE' /* (ࢮ) */}},
            {u'\u0631' /* (ر) */,
             {u'\u0616' /* (ز) */, u'\u0699' /* (ڙ) */, u'\u0698' /* (ژ) */, u'\u0697' /* (ڗ) */, u'\u0696' /* (ږ) */,
              u'\u0694' /* (ڔ) */, u'\u076B' /* (ݫ) */}},
            {u'\u0635' /* (ص) */,
             {u'\u0636' /* (ض) */, u'\u069E' /* (ڞ) */, u'\u069D' /* (ڝ) */, u'\u06FB' /* (ۻ) */,
              u'\u08AF' /* (ࢯ) */}},
            {u'\u0637' /* (ط) */, {u'\u0638' /* (ظ) */, u'\u069F' /* (ڟ) */, u'\u08A3' /* (ࢣ) */}},
            {u'\u0639' /* (ع) */,
             {u'\u063A' /* (غ) */, u'\u06A0' /* (ڠ) */, u'\u06FC' /* (ۼ) */, u'\u075F' /* (ݟ) */, u'\u075E' /* (ݞ) */,
              u'\u075D' /* (ݝ) */, u'\u08B3' /* (ࢳ) */}},
            {u'\u0647' /* (ه) */, {u'\u0629' /* (ة) */}},
            {u'\u066E' /* (ٮ) */,
             {u'\u062B' /* (ث) */, u'\u062A' /* (ت) */, u'\u0628' /* (ب) */, u'\u067F' /* (ٿ) */, u'\u067E' /* (پ) */,
              u'\u067D' /* (ٽ) */, u'\u067B' /* (ٻ) */, u'\u067A' /* (ٺ) */, u'\u0680' /* (ڀ) */, u'\u0754' /* (ݔ) */,
              u'\u0753' /* (ݓ) */, u'\u0752' /* (ݒ) */, u'\u0751' /* (ݑ) */, u'\u0750' /* (ݐ) */}},
            {u'\u06A1' /* (ڡ) */,
             {u'\u0641' /* (ف) */, u'\u06A6' /* (ڦ) */, u'\u06A5' /* (ڥ) */, u'\u06A4' /* (ڤ) */, u'\u06A3' /* (ڣ) */,
              u'\u06A2' /* (ڢ) */, u'\u0761' /* (ݡ) */, u'\u0760' /* (ݠ) */, u'\u08A4' /* (ࢤ) */}},
            {u'\u066F' /* (ٯ) */, {u'\u0642' /* (ق) */, u'\u06A8' /* (ڨ) */, u'\u06A7' /* (ڧ) */, u'\u08A5' /* (ࢥ) */}},
            {u'\u06BA' /* (ں) */, {u'\u0646' /* (ن) */, u'\u06BD' /* (ڽ) */, u'\u06B9' /* (ڹ) */, u'\u0767' /* (ݧ) */}},
            {u'\u0645' /* (م) */, {u'\u0766' /* (ݦ) */, u'\u0765' /* (ݥ) */, u'\u08A7' /* (ࢧ) */}},
            {u'\u0649' /* (ى) */,
             {u'\u064A' /* (ي) */, u'\u06D1' /* (ۑ) */, u'\u06D0' /* (ې) */, u'\u063F' /* (ؿ) */, u'\u063E' /* (ؾ) */,
              u'\u08A9' /* (ࢩ) */}},
            {u'\u0633' /* (س) */,
             {u'\u0634' /* (ش) */, u'\u069C' /* (ڜ) */, u'\u069B' /* (ڛ) */, u'\u069A' /* (ښ) */, u'\u06FA' /* (ۺ) */,
              u'\u075C' /* (ݜ) */, u'\u076D' /* (ݭ) */}},
            {u'\u062D' /* (ح) */,
             {u'\u062E' /* (خ) */, u'\u062C' /* (ج) */, u'\u0687' /* (ڇ) */, u'\u0686' /* (چ) */, u'\u0685' /* (څ) */,
              u'\u0684' /* (ڄ) */, u'\u0683' /* (ڃ) */, u'\u0682' /* (ڂ) */, u'\u06BF' /* (ڿ) */, u'\u0758' /* (ݘ) */,
              u'\u0757' /* (ݗ) */, u'\u08A2' /* (ࢢ) */}},
            {u'\u0644' /* (ل) */, {u'\u06B8' /* (ڸ) */, u'\u06B6' /* (ڶ) */}},
            {u'\u0648' /* (و) */,
             {u'\u06CF' /* (ۏ) */, u'\u06CB' /* (ۋ) */, u'\u06CA' /* (ۊ) */, u'\u08AB' /* (ࢫ) */}}};
}

wchar_t pointify_u16char(std::mt19937 &gen, wchar_t input_char) {
    if (variants.count(input_char)) {
        const std::vector<wchar_t> &input_char_variants = variants.at(input_char);
        int index = std::uniform_int_distribution<>(0, input_char_variants.size())(gen);
        if (index < input_char_variants.size()) { return input_char_variants.at(index); }
    }
    return input_char;
}

wchar_t depointify_u16char(wchar_t input_char) {
    if (depointify_map.count(input_char)) { return depointify_map.at(input_char); }
    return input_char;
}

std::wstring pointify_wstring(std::mt19937 &gen, const std::wstring &u16input) {
    std::wstring u16output;
    for (wchar_t input_char : u16input) { u16output += pointify_u16char(gen, depointify_u16char(input_char)); }
    return u16output;
}

int main() {
    init();

    std::random_device rd;
    std::mt19937 gen(rd());
    setlocale(LC_ALL, "en_US.UTF-8");
    std::wcout << pointify_wstring(gen, {std::istreambuf_iterator{std::wcin.rdbuf()}, {}});
    return 0;
}
