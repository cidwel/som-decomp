#include "som_c.h"

/* C09D78 select_scene_color_targets_from_cursor_and_fade_flags   [class B, 77 bytes, 39 instructions]
 * Source: src/rom/select_scene_color_targets_from_cursor_and_fade_flags.s
 * Documented in docs/ui-native-scene-setup.md
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void select_scene_color_targets_from_cursor_and_fade_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x007B);
    uint8_t x5;
    bool carry1;
    if (value == 0) {
        uint8_t value2 = RAM8(0x00F2);
        uint8_t x1;
        if (!(value2 & 0x80)) {
            x1 = 5;
        } else {
            x1 = 0x17;
        }
        x5 = x1;
        carry1 = value >= 0;
    } else {
        uint8_t value3 = RAM8(0x005F);
        bool negative1;
        if ((value3 & 4) < 4) {
            negative1 = value & 0x80;
        } else {
            negative1 = (value ^ 0xFE) & 0x80;
        }
        uint8_t x4;
        if (negative1) {
            uint8_t value4 = RAM8(0x00F2);
            uint8_t x2;
            if (!(value4 & 0x80)) {
                x2 = 0x11;
            } else {
                x2 = 0x23;
            }
            x4 = x2;
        } else {
            uint8_t value5 = RAM8(0x00F2);
            uint8_t x3;
            if (!(value5 & 0x80)) {
                x3 = 0x0B;
            } else {
                x3 = 0x1D;
            }
            x4 = x3;
        }
        x5 = x4;
        carry1 = (value3 & 4) >= 4;
    }
    uint8_t a_hi1 = a_hi;
    uint8_t x6 = x5;
    uint8_t y1 = 5;
    bool overflow1 = overflow;
    for (;;) {
        uint8_t value6 = BUS8(c, 0x009DC5 + x6);
        RAM8(0x0A4C + y1) = value6;
        uint8_t value7 = RAM8(0x00F2);
        if (value7 & 0x80) {
            RAM8(0x0A46 + y1) = value6;
        }
        x6 = (uint8_t)(x6 - 1);
        y1 = (uint8_t)(y1 - 1);
        overflow1 = value7 & 0x40;
        if (!(!(y1 & 0x80))) break;
    }
    r->a = (a_hi1 << 8) | a;
    r->x = x6;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC09D78, SOM_RTS, "gen", select_scene_color_targets_from_cursor_and_fade_flags, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, -1, 77, 39)
