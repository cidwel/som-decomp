#include "som_c.h"

/* C09434 apply_native_button_mappings_to_three_controller_words   [class B, 66 bytes, 32 instructions]
 * Source: src/rom/apply_native_button_mappings_to_three_controller_words.s
 * Documented in docs/game-controller-mapping.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: XYV.
 */
static void apply_native_button_mappings_to_three_controller_words(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint8_t y = r->y;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x00EE);
    uint8_t a_hi2;
    uint8_t y2;
    bool overflow2;
    if (value == 0) {
        a_hi2 = a >> 8;
        y2 = y;
        overflow2 = overflow;
    } else {
        uint8_t value2 = RAM8(0x0043);
        uint8_t value3 = RAM8(0x0042);
        uint8_t a_hi1;
        uint8_t y1;
        bool overflow1;
        if ((value2 | value3) == 0) {
            a_hi1 = a >> 8;
            y1 = y;
            overflow1 = overflow;
        } else {
            r->a = (a >> 8 << 8) | value2;
            r->x = value;
            r->y = value3;
            r->mf = 1;
            JSR(c, 0x9446, 0xC09476); /* permute_native_controller_button_bits */
            uint16_t a_all = r->a;
            uint8_t y_ret = r->y;
            bool overflow_ret = r->v;
            RAM8(0x0043) = (uint8_t)a_all;
            RAM8(0x0042) = y_ret;
            a_hi1 = a_all >> 8;
            y1 = y_ret;
            overflow1 = overflow_ret;
        }
        a_hi2 = a_hi1;
        y2 = y1;
        overflow2 = overflow1;
    }
    uint8_t value4 = RAM8(0x00EF);
    uint8_t a_hi4;
    uint8_t y4;
    bool overflow4;
    if (value4 == 0) {
        a_hi4 = a_hi2;
        y4 = y2;
        overflow4 = overflow2;
    } else {
        uint8_t value5 = RAM8(0x0045);
        uint8_t value6 = RAM8(0x0044);
        uint8_t a_hi3;
        uint8_t y3;
        bool overflow3;
        if ((value5 | value6) == 0) {
            a_hi3 = a_hi2;
            y3 = y2;
            overflow3 = overflow2;
        } else {
            r->a = (a_hi2 << 8) | value5;
            r->x = value4;
            r->y = value6;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 1;
            JSR(c, 0x945B, 0xC09476); /* permute_native_controller_button_bits */
            uint16_t a_all2 = r->a;
            uint8_t y_ret2 = r->y;
            bool overflow_ret2 = r->v;
            RAM8(0x0045) = (uint8_t)a_all2;
            RAM8(0x0044) = y_ret2;
            a_hi3 = a_all2 >> 8;
            y3 = y_ret2;
            overflow3 = overflow_ret2;
        }
        a_hi4 = a_hi3;
        y4 = y3;
        overflow4 = overflow3;
    }
    uint8_t value7 = RAM8(0x00F0);
    uint8_t y6;
    bool overflow6;
    if (value7 == 0) {
        y6 = y4;
        overflow6 = overflow4;
    } else {
        uint8_t value8 = RAM8(0x0047);
        uint8_t value9 = RAM8(0x0046);
        uint8_t y5;
        bool overflow5;
        if ((value8 | value9) == 0) {
            y5 = y4;
            overflow5 = overflow4;
        } else {
            r->a = (a_hi4 << 8) | value8;
            r->x = value7;
            r->y = value9;
            r->v = overflow4;
            r->mf = 1;
            r->xf = 1;
            JSR(c, 0x9470, 0xC09476); /* permute_native_controller_button_bits */
            uint16_t a_all3 = r->a;
            uint8_t y_ret3 = r->y;
            bool overflow_ret3 = r->v;
            RAM8(0x0047) = (uint8_t)a_all3;
            RAM8(0x0046) = y_ret3;
            y5 = y_ret3;
            overflow5 = overflow_ret3;
        }
        y6 = y5;
        overflow6 = overflow5;
    }
    r->x = value7;
    r->y = y6;
    r->v = overflow6;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC09434, SOM_RTS, "gen", apply_native_button_mappings_to_three_controller_words, 0, L_X | L_Y | L_V, 1, 0, 1, 66, 32)
