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
    variants = {{u'ك', {u'ڮ', u'ڭ', u'ڬ', u'ݿ', u'ࢴ'}},
                {u'د', {u'ذ', u'ڏ', u'ڎ', u'ڍ', u'ڌ', u'ڊ', u'ڐ', u'ࢮ'}},
                {u'ر', {u'ز', u'ڙ', u'ژ', u'ڗ', u'ږ', u'ڔ', u'ݫ'}},
                {u'ص', {u'ض', u'ڞ', u'ڝ', u'ۻ', u'ࢯ'}},
                {u'ط', {u'ظ', u'ڟ', u'ࢣ'}},
                {u'ع', {u'غ', u'ڠ', u'ۼ', u'ݟ', u'ݞ', u'ݝ', u'ࢳ'}},
                {u'ه', {u'ة'}},
                {u'ٮ', {u'ث', u'ت', u'ب', u'ٿ', u'پ', u'ٽ', u'ٻ', u'ٺ', u'ڀ', u'ݔ', u'ݓ', u'ݒ', u'ݑ', u'ݐ'}},
                {u'ڡ', {u'ف', u'ڦ', u'ڥ', u'ڤ', u'ڣ', u'ڢ', u'ݡ', u'ݠ', u'ࢤ'}},
                {u'ٯ', {u'ق', u'ڨ', u'ڧ', u'ࢥ'}},
                {u'ں', {u'ن', u'ڽ', u'ڹ', u'ݧ'}},
                {u'م', {u'ݦ', u'ݥ', u'ࢧ'}},
                {u'ى', {u'ي', u'ۑ', u'ې', u'ؿ', u'ؾ', u'ࢩ'}},
                {u'س', {u'ش', u'ڜ', u'ڛ', u'ښ', u'ۺ', u'ݜ', u'ݭ'}},
                {u'ح', {u'خ', u'ج', u'ڇ', u'چ', u'څ', u'ڄ', u'ڃ', u'ڂ', u'ڿ', u'ݘ', u'ݗ', u'ࢢ'}},
                {u'ل', {u'ڸ', u'ڶ'}},
                {u'و', {u'ۏ', u'ۋ', u'ۊ', u'ࢫ'}}};
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
