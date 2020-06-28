#include <algorithm>
#include <iostream>
#include <map>
#include <random>
#include <vector>

static std::map<wchar_t, wchar_t> depointify_map;
static std::map<wchar_t, std::vector<wchar_t>> variants;

void init() {
    depointify_map = {{L'ذ', L'د'}, {L'ز', L'ر'}, {L'ض', L'ص'}, {L'ظ', L'ط'}, {L'غ', L'ع'}, {L'ة', L'ه'},
                      {L'ب', L'ٮ'}, {L'ت', L'ٮ'}, {L'ث', L'ٮ'}, {L'ف', L'ڡ'}, {L'ق', L'ٯ'}, {L'ن', L'ں'},
                      {L'ي', L'ى'}, {L'ش', L'س'}, {L'ج', L'ح'}, {L'خ', L'ح'}};
    variants = {{L'ك', {L'ڮ', L'ڭ', L'ڬ', L'ݿ', L'ࢴ'}},
                {L'د', {L'ذ', L'ڏ', L'ڎ', L'ڍ', L'ڌ', L'ڊ', L'ڐ', L'ࢮ'}},
                {L'ر', {L'ز', L'ڙ', L'ژ', L'ڗ', L'ږ', L'ڔ', L'ݫ'}},
                {L'ص', {L'ض', L'ڞ', L'ڝ', L'ۻ', L'ࢯ'}},
                {L'ط', {L'ظ', L'ڟ', L'ࢣ'}},
                {L'ع', {L'غ', L'ڠ', L'ۼ', L'ݟ', L'ݞ', L'ݝ', L'ࢳ'}},
                {L'ه', {L'ة'}},
                {L'ٮ', {L'ث', L'ت', L'ب', L'ٿ', L'پ', L'ٽ', L'ٻ', L'ٺ', L'ڀ', L'ݔ', L'ݓ', L'ݒ', L'ݑ', L'ݐ'}},
                {L'ڡ', {L'ف', L'ڦ', L'ڥ', L'ڤ', L'ڣ', L'ڢ', L'ݡ', L'ݠ', L'ࢤ'}},
                {L'ٯ', {L'ق', L'ڨ', L'ڧ', L'ࢥ'}},
                {L'ں', {L'ن', L'ڽ', L'ڹ', L'ݧ'}},
                {L'م', {L'ݦ', L'ݥ', L'ࢧ'}},
                {L'ى', {L'ي', L'ۑ', L'ې', L'ؿ', L'ؾ', L'ࢩ'}},
                {L'س', {L'ش', L'ڜ', L'ڛ', L'ښ', L'ۺ', L'ݜ', L'ݭ'}},
                {L'ح', {L'خ', L'ج', L'ڇ', L'چ', L'څ', L'ڄ', L'ڃ', L'ڂ', L'ڿ', L'ݘ', L'ݗ', L'ࢢ'}},
                {L'ل', {L'ڸ', L'ڶ'}},
                {L'و', {L'ۏ', L'ۋ', L'ۊ', L'ࢫ'}}};
}

wchar_t add_random_dots(std::mt19937 &gen, wchar_t c) {
    if (variants.count(c)) {
        const std::vector<wchar_t> &input_char_variants = variants.at(c);
        int i = std::uniform_int_distribution<>(0, input_char_variants.size())(gen);
        if (i < input_char_variants.size()) { return input_char_variants.at(i); }
    }
    return c;
}

wchar_t remove_dots(wchar_t c) {
    if (depointify_map.count(c)) { return depointify_map.at(c); }
    return c;
}

int main() {
    init();

    std::random_device rd;
    std::mt19937 gen(rd());
    setlocale(LC_ALL, "");

    std::transform(std::istreambuf_iterator<wchar_t>{std::wcin}, {}, std::ostreambuf_iterator<wchar_t>{std::wcout},
                   [&gen](wchar_t c) { return add_random_dots(gen, remove_dots(c)); });
    return 0;
}
