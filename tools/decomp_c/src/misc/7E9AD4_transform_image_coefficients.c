#include "som_c.h"

/* 7E9AD4 transform_image_coefficients   [class B, 570 bytes, 349 instructions]
 * Source: src/boot/transform_image_coefficients.s
 * Entry: M=8 bit X=16 bit DB=$00 D=any.  Callers read: YCV.
 */
static void transform_image_coefficients(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t direct_page = dp;
    for (;;) {
        uint16_t value = BUS16_RDP(c, direct_page);
        uint16_t value2 = BUS16_RDP(c, (uint16_t)(direct_page + 0x10));
        uint16_t value3 = BUS16_RDP(c, (uint16_t)(direct_page + 0x20));
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(direct_page + 0x30));
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(direct_page + 0x40));
        uint16_t value6 = BUS16_RDP(c, (uint16_t)(direct_page + 0x50));
        uint16_t value7 = BUS16_RDP(c, (uint16_t)(direct_page + 0x60));
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(direct_page + 0x70));
        BUS16_SET(c, (uint16_t)(direct_page + 0x80 + x1), (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value + value2) + value3) + value4) + value5) + value6) + value7) + value8));
        uint16_t value9 = BUS16_RDP(c, direct_page);
        uint16_t value10 = BUS16_RDP(c, (uint16_t)(direct_page + 0x10));
        uint16_t value11 = BUS16_RDP(c, (uint16_t)(direct_page + 0x20));
        uint16_t value12 = BUS16_RDP(c, (uint16_t)(direct_page + 0x30));
        uint16_t value13 = BUS16_RDP(c, (uint16_t)(direct_page + 0x40));
        uint16_t value14 = BUS16_RDP(c, (uint16_t)(direct_page + 0x50));
        uint16_t value15 = BUS16_RDP(c, (uint16_t)(direct_page + 0x60));
        uint16_t value16 = BUS16_RDP(c, (uint16_t)(direct_page + 0x70));
        BUS16_SET(c, (uint16_t)(direct_page + 0x82 + x1), (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value9 + value10) + value11) + value12) - value13) - value14) - value15) - value16));
        uint16_t value17 = BUS16_RDP(c, direct_page);
        uint16_t value18 = BUS16_RDP(c, (uint16_t)(direct_page + 0x10));
        uint16_t value19 = BUS16_RDP(c, (uint16_t)(direct_page + 0x20));
        uint16_t value20 = BUS16_RDP(c, (uint16_t)(direct_page + 0x30));
        uint16_t value21 = BUS16_RDP(c, (uint16_t)(direct_page + 0x40));
        uint16_t value22 = BUS16_RDP(c, (uint16_t)(direct_page + 0x50));
        uint16_t value23 = BUS16_RDP(c, (uint16_t)(direct_page + 0x60));
        uint16_t value24 = BUS16_RDP(c, (uint16_t)(direct_page + 0x70));
        BUS16_SET(c, (uint16_t)(direct_page + 0x84 + x1), (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value17 + value18) - value19) - value20) - value21) - value22) + value23) + value24));
        uint16_t value25 = BUS16_RDP(c, direct_page);
        uint16_t value26 = BUS16_RDP(c, (uint16_t)(direct_page + 0x10));
        uint16_t value27 = BUS16_RDP(c, (uint16_t)(direct_page + 0x20));
        uint16_t value28 = BUS16_RDP(c, (uint16_t)(direct_page + 0x30));
        uint16_t value29 = BUS16_RDP(c, (uint16_t)(direct_page + 0x40));
        uint16_t value30 = BUS16_RDP(c, (uint16_t)(direct_page + 0x50));
        uint16_t value31 = BUS16_RDP(c, (uint16_t)(direct_page + 0x60));
        uint16_t value32 = BUS16_RDP(c, (uint16_t)(direct_page + 0x70));
        BUS16_SET(c, (uint16_t)(direct_page + 0x86 + x1), (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value25 + value26) - value27) - value28) + value29) + value30) - value31) - value32));
        uint16_t value33 = BUS16_RDP(c, direct_page);
        uint16_t value34 = BUS16_RDP(c, (uint16_t)(direct_page + 0x10));
        uint16_t value35 = BUS16_RDP(c, (uint16_t)(direct_page + 0x20));
        uint16_t value36 = BUS16_RDP(c, (uint16_t)(direct_page + 0x30));
        uint16_t value37 = BUS16_RDP(c, (uint16_t)(direct_page + 0x40));
        uint16_t value38 = BUS16_RDP(c, (uint16_t)(direct_page + 0x50));
        uint16_t value39 = BUS16_RDP(c, (uint16_t)(direct_page + 0x60));
        uint16_t value40 = BUS16_RDP(c, (uint16_t)(direct_page + 0x70));
        BUS16_SET(c, (uint16_t)(direct_page + 0x88 + x1), (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value33 - value34) - value35) + value36) + value37) - value38) - value39) + value40));
        uint16_t value41 = BUS16_RDP(c, direct_page);
        uint16_t value42 = BUS16_RDP(c, (uint16_t)(direct_page + 0x10));
        uint16_t value43 = BUS16_RDP(c, (uint16_t)(direct_page + 0x20));
        uint16_t value44 = BUS16_RDP(c, (uint16_t)(direct_page + 0x30));
        uint16_t value45 = BUS16_RDP(c, (uint16_t)(direct_page + 0x40));
        uint16_t value46 = BUS16_RDP(c, (uint16_t)(direct_page + 0x50));
        uint16_t value47 = BUS16_RDP(c, (uint16_t)(direct_page + 0x60));
        uint16_t value48 = BUS16_RDP(c, (uint16_t)(direct_page + 0x70));
        BUS16_SET(c, (uint16_t)(direct_page + 0x8A + x1), (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value41 - value42) - value43) + value44) - value45) + value46) + value47) - value48));
        uint16_t value49 = BUS16_RDP(c, direct_page);
        uint16_t value50 = BUS16_RDP(c, (uint16_t)(direct_page + 0x10));
        uint16_t value51 = BUS16_RDP(c, (uint16_t)(direct_page + 0x20));
        uint16_t value52 = BUS16_RDP(c, (uint16_t)(direct_page + 0x30));
        uint16_t value53 = BUS16_RDP(c, (uint16_t)(direct_page + 0x40));
        uint16_t value54 = BUS16_RDP(c, (uint16_t)(direct_page + 0x50));
        uint16_t value55 = BUS16_RDP(c, (uint16_t)(direct_page + 0x60));
        uint16_t value56 = BUS16_RDP(c, (uint16_t)(direct_page + 0x70));
        BUS16_SET(c, (uint16_t)(direct_page + 0x8C + x1), (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value49 - value50) + value51) - value52) - value53) + value54) - value55) + value56));
        uint16_t value57 = BUS16_RDP(c, direct_page);
        uint16_t value58 = BUS16_RDP(c, (uint16_t)(direct_page + 0x10));
        uint16_t value59 = BUS16_RDP(c, (uint16_t)(direct_page + 0x20));
        uint16_t value60 = BUS16_RDP(c, (uint16_t)(direct_page + 0x30));
        uint16_t value61 = BUS16_RDP(c, (uint16_t)(direct_page + 0x40));
        uint16_t value62 = BUS16_RDP(c, (uint16_t)(direct_page + 0x50));
        uint16_t value63 = BUS16_RDP(c, (uint16_t)(direct_page + 0x60));
        uint16_t value64 = BUS16_RDP(c, (uint16_t)(direct_page + 0x70));
        BUS16_SET(c, (uint16_t)(direct_page + 0x8E + x1), (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value57 - value58) + value59) - value60) + value61) - value62) + value63) - value64));
        if (((uint16_t)(direct_page + 2) & 0x0F) != 0) {
            a_hi1 = 0;
            x1 = (uint16_t)(x1 + 0x0E);
            direct_page = (uint16_t)(direct_page + 2);
            continue;
        }
        a_hi1 = 0;
        x1 = (uint16_t)(x1 + 0x0E);
        direct_page = (uint16_t)(direct_page + 2);
        break;
    }
    uint8_t a_hi2 = (direct_page & 0xFF00) >> 8;
    uint16_t x2 = 0;
    bool carry1 = 0;
    bool overflow1 = 0;
    uint16_t direct_page2 = direct_page & 0xFF00;
    for (;;) {
        uint16_t value65 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0x80));
        uint16_t value66 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0x90));
        uint16_t value67 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xA0));
        uint16_t value68 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xB0));
        uint16_t value69 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xC0));
        uint16_t value70 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xD0));
        uint16_t value71 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xE0));
        uint16_t value72 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xF0));
        uint8_t a1;
        uint8_t a_hi3;
        if ((((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value65 + 4) + value66) + value67) + value68) + value69) + value70) + value71) + value72) >> 3) & 0x1000) == 0) {
            a1 = (uint8_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value65 + 4) + value66) + value67) + value68) + value69) + value70) + value71) + value72) >> 3);
            a_hi3 = (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value65 + 4) + value66) + value67) + value68) + value69) + value70) + value71) + value72) >> 3 >> 8;
        } else {
            a1 = (uint8_t)(((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value65 + 4) + value66) + value67) + value68) + value69) + value70) + value71) + value72) >> 3) | 0xF000);
            a_hi3 = (((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value65 + 4) + value66) + value67) + value68) + value69) + value70) + value71) + value72) >> 3) | 0xF000) >> 8;
        }
        BUS16_SET(c, (uint16_t)(direct_page2 + x2), (a_hi3 << 8) | a1);
        uint16_t value73 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0x80));
        uint16_t value74 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0x90));
        uint16_t value75 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xA0));
        uint16_t value76 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xB0));
        uint16_t value77 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xC0));
        uint16_t value78 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xD0));
        uint16_t value79 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xE0));
        uint16_t value80 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xF0));
        uint8_t a2;
        uint8_t a_hi4;
        if ((((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value73 + 4) + value74) + value75) + value76) - value77) - value78) - value79) - value80) >> 3) & 0x1000) == 0) {
            a2 = (uint8_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value73 + 4) + value74) + value75) + value76) - value77) - value78) - value79) - value80) >> 3);
            a_hi4 = (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value73 + 4) + value74) + value75) + value76) - value77) - value78) - value79) - value80) >> 3 >> 8;
        } else {
            a2 = (uint8_t)(((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value73 + 4) + value74) + value75) + value76) - value77) - value78) - value79) - value80) >> 3) | 0xF000);
            a_hi4 = (((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value73 + 4) + value74) + value75) + value76) - value77) - value78) - value79) - value80) >> 3) | 0xF000) >> 8;
        }
        BUS16_SET(c, (uint16_t)(direct_page2 + 2 + x2), (a_hi4 << 8) | a2);
        uint16_t value81 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0x80));
        uint16_t value82 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0x90));
        uint16_t value83 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xA0));
        uint16_t value84 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xB0));
        uint16_t value85 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xC0));
        uint16_t value86 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xD0));
        uint16_t value87 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xE0));
        uint16_t value88 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xF0));
        uint8_t a3;
        uint8_t a_hi5;
        if ((((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value81 + 4) + value82) - value83) - value84) - value85) - value86) + value87) + value88) >> 3) & 0x1000) == 0) {
            a3 = (uint8_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value81 + 4) + value82) - value83) - value84) - value85) - value86) + value87) + value88) >> 3);
            a_hi5 = (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value81 + 4) + value82) - value83) - value84) - value85) - value86) + value87) + value88) >> 3 >> 8;
        } else {
            a3 = (uint8_t)(((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value81 + 4) + value82) - value83) - value84) - value85) - value86) + value87) + value88) >> 3) | 0xF000);
            a_hi5 = (((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value81 + 4) + value82) - value83) - value84) - value85) - value86) + value87) + value88) >> 3) | 0xF000) >> 8;
        }
        BUS16_SET(c, (uint16_t)(direct_page2 + 4 + x2), (a_hi5 << 8) | a3);
        uint16_t value89 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0x80));
        uint16_t value90 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0x90));
        uint16_t value91 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xA0));
        uint16_t value92 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xB0));
        uint16_t value93 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xC0));
        uint16_t value94 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xD0));
        uint16_t value95 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xE0));
        uint16_t value96 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xF0));
        uint8_t a4;
        uint8_t a_hi6;
        if ((((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value89 + 4) + value90) - value91) - value92) + value93) + value94) - value95) - value96) >> 3) & 0x1000) == 0) {
            a4 = (uint8_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value89 + 4) + value90) - value91) - value92) + value93) + value94) - value95) - value96) >> 3);
            a_hi6 = (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value89 + 4) + value90) - value91) - value92) + value93) + value94) - value95) - value96) >> 3 >> 8;
        } else {
            a4 = (uint8_t)(((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value89 + 4) + value90) - value91) - value92) + value93) + value94) - value95) - value96) >> 3) | 0xF000);
            a_hi6 = (((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value89 + 4) + value90) - value91) - value92) + value93) + value94) - value95) - value96) >> 3) | 0xF000) >> 8;
        }
        BUS16_SET(c, (uint16_t)(direct_page2 + 6 + x2), (a_hi6 << 8) | a4);
        uint16_t value97 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0x80));
        uint16_t value98 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0x90));
        uint16_t value99 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xA0));
        uint16_t value100 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xB0));
        uint16_t value101 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xC0));
        uint16_t value102 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xD0));
        uint16_t value103 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xE0));
        uint16_t value104 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xF0));
        uint8_t a5;
        uint8_t a_hi7;
        if ((((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value97 + 4) - value98) - value99) + value100) + value101) - value102) - value103) + value104) >> 3) & 0x1000) == 0) {
            a5 = (uint8_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value97 + 4) - value98) - value99) + value100) + value101) - value102) - value103) + value104) >> 3);
            a_hi7 = (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value97 + 4) - value98) - value99) + value100) + value101) - value102) - value103) + value104) >> 3 >> 8;
        } else {
            a5 = (uint8_t)(((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value97 + 4) - value98) - value99) + value100) + value101) - value102) - value103) + value104) >> 3) | 0xF000);
            a_hi7 = (((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value97 + 4) - value98) - value99) + value100) + value101) - value102) - value103) + value104) >> 3) | 0xF000) >> 8;
        }
        BUS16_SET(c, (uint16_t)(direct_page2 + 8 + x2), (a_hi7 << 8) | a5);
        uint16_t value105 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0x80));
        uint16_t value106 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0x90));
        uint16_t value107 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xA0));
        uint16_t value108 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xB0));
        uint16_t value109 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xC0));
        uint16_t value110 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xD0));
        uint16_t value111 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xE0));
        uint16_t value112 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xF0));
        uint8_t a6;
        uint8_t a_hi8;
        if ((((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value105 + 4) - value106) - value107) + value108) - value109) + value110) + value111) - value112) >> 3) & 0x1000) == 0) {
            a6 = (uint8_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value105 + 4) - value106) - value107) + value108) - value109) + value110) + value111) - value112) >> 3);
            a_hi8 = (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value105 + 4) - value106) - value107) + value108) - value109) + value110) + value111) - value112) >> 3 >> 8;
        } else {
            a6 = (uint8_t)(((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value105 + 4) - value106) - value107) + value108) - value109) + value110) + value111) - value112) >> 3) | 0xF000);
            a_hi8 = (((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value105 + 4) - value106) - value107) + value108) - value109) + value110) + value111) - value112) >> 3) | 0xF000) >> 8;
        }
        BUS16_SET(c, (uint16_t)(direct_page2 + 0x0A + x2), (a_hi8 << 8) | a6);
        uint16_t value113 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0x80));
        uint16_t value114 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0x90));
        uint16_t value115 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xA0));
        uint16_t value116 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xB0));
        uint16_t value117 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xC0));
        uint16_t value118 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xD0));
        uint16_t value119 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xE0));
        uint16_t value120 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xF0));
        uint8_t a7;
        uint8_t a_hi9;
        if ((((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value113 + 4) - value114) + value115) - value116) - value117) + value118) - value119) + value120) >> 3) & 0x1000) == 0) {
            a7 = (uint8_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value113 + 4) - value114) + value115) - value116) - value117) + value118) - value119) + value120) >> 3);
            a_hi9 = (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value113 + 4) - value114) + value115) - value116) - value117) + value118) - value119) + value120) >> 3 >> 8;
        } else {
            a7 = (uint8_t)(((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value113 + 4) - value114) + value115) - value116) - value117) + value118) - value119) + value120) >> 3) | 0xF000);
            a_hi9 = (((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value113 + 4) - value114) + value115) - value116) - value117) + value118) - value119) + value120) >> 3) | 0xF000) >> 8;
        }
        BUS16_SET(c, (uint16_t)(direct_page2 + 0x0C + x2), (a_hi9 << 8) | a7);
        uint16_t value121 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0x80));
        uint16_t value122 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0x90));
        uint16_t value123 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xA0));
        uint16_t value124 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xB0));
        uint16_t value125 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xC0));
        uint16_t value126 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xD0));
        uint16_t value127 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xE0));
        uint16_t value128 = BUS16_RDP(c, (uint16_t)(direct_page2 + 0xF0));
        uint8_t a8;
        uint8_t a_hi10;
        if ((((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value121 + 4) - value122) + value123) - value124) + value125) - value126) + value127) - value128) >> 3) & 0x1000) == 0) {
            a8 = (uint8_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value121 + 4) - value122) + value123) - value124) + value125) - value126) + value127) - value128) >> 3);
            a_hi10 = (uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value121 + 4) - value122) + value123) - value124) + value125) - value126) + value127) - value128) >> 3 >> 8;
        } else {
            a8 = (uint8_t)(((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value121 + 4) - value122) + value123) - value124) + value125) - value126) + value127) - value128) >> 3) | 0xF000);
            a_hi10 = (((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)((uint16_t)(value121 + 4) - value122) + value123) - value124) + value125) - value126) + value127) - value128) >> 3) | 0xF000) >> 8;
        }
        BUS16_SET(c, (uint16_t)(direct_page2 + 0x0E + x2), (a_hi10 << 8) | a8);
        if (((uint16_t)(direct_page2 + 2) & 0x0F) != 0) {
            uint8_t a_hi2_next = 0;
            uint16_t x2_next = (uint16_t)(x2 + 0x0E);
            bool carry1_next = x2 + 0x0E > 0xFFFF;
            bool overflow1_next = ((x2 ^ (uint16_t)(x2 + 0x0E)) & ((uint16_t)(x2 + 0x0E) ^ 0x0E) & 0x8000) != 0;
            uint16_t direct_page2_next = (uint16_t)(direct_page2 + 2);
            a_hi2 = a_hi2_next;
            x2 = x2_next;
            carry1 = carry1_next;
            overflow1 = overflow1_next;
            direct_page2 = direct_page2_next;
            continue;
        }
        uint8_t a_hi2_next2 = 0;
        uint16_t x2_next2 = (uint16_t)(x2 + 0x0E);
        bool carry1_next2 = x2 + 0x0E > 0xFFFF;
        bool overflow1_next2 = ((x2 ^ (uint16_t)(x2 + 0x0E)) & ((uint16_t)(x2 + 0x0E) ^ 0x0E) & 0x8000) != 0;
        uint16_t direct_page2_next2 = (uint16_t)(direct_page2 + 2);
        a_hi2 = a_hi2_next2;
        x2 = x2_next2;
        carry1 = carry1_next2;
        overflow1 = overflow1_next2;
        direct_page2 = direct_page2_next2;
        break;
    }
    r->y = y;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->dp = direct_page2;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9AD4, SOM_RTS, "gen", transform_image_coefficients, 0, L_Y | L_C | L_V, 1, 1, 0, 570, 349)
