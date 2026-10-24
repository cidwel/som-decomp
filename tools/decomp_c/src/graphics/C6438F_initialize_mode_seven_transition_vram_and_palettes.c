#include "som_c.h"

/* C6438F initialize_mode_seven_transition_vram_and_palettes   [class D, 332 bytes, 133 instructions]
 * Source: src/rom/initialize_mode_seven_transition_vram_and_palettes.s
 * Documented in docs/ui-native-mode7-transition.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void initialize_mode_seven_transition_vram_and_palettes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    BUS8_SET(c, 0x002115, 0);
    BUS8_SET(c, 0x002116, 0);
    BUS8_SET(c, 0x002117, 0);
    RAM8(0x0020) = 1;
    RAM8(0x0021) = 0;
    BUS8_SET(c, 0x004300, 8);
    BUS8_SET(c, 0x004301, 0x18);
    BUS16_SET(c, 0x004302, 0x21);
    BUS8_SET(c, 0x004304, 0);
    uint8_t a_hi1 = a_hi;
    uint16_t y1 = 4;
    for (;;) {
        uint8_t a_hi2 = a_hi1;
        uint16_t x1 = 4;
        for (;;) {
            BUS8_SET(c, 0x002118, RAM8(0x0020));
            RAM8(0x0020)++;
            x1 = (uint16_t)(x1 - 1);
            if (!(x1 != 0)) break;
        }
        BUS16_SET(c, 0x004305, 0x7C);
        BUS8_SET(c, 0x00420B, 1);
        a_hi1 = a_hi2;
        y1 = (uint16_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    BUS16_SET(c, 0x004305, 0x3E00);
    BUS8_SET(c, 0x00420B, 1);
    BUS8_SET(c, 0x002115, 0x80);
    BUS8_SET(c, 0x002116, 0);
    BUS8_SET(c, 0x002117, 0);
    uint16_t x2 = 0x20;
    for (;;) {
        BUS8_SET(c, 0x002119, 0);
        BUS8_SET(c, 0x002119, 0);
        x2 = (uint16_t)(x2 - 1);
        if (!(x2 != 0)) break;
    }
    uint8_t a_hi3 = a_hi1;
    uint16_t x3 = 0x6A00;
    uint16_t y2 = 0x0200;
    bool carry1 = carry;
    for (;;) {
        uint8_t value2 = BUS8(c, 0xC60000 + x3);
        BUS8_SET(c, 0x002119, value2 & 0x0F);
        BUS8_SET(c, 0x002119, value2 >> 4);
        x3 = (uint16_t)(x3 + 1);
        y2 = (uint16_t)(y2 - 1);
        carry1 = value2 >> 3 & 0x01;
        if (!(y2 != 0)) break;
    }
    r->a = (a_hi3 << 8) | a;
    r->c = carry1;
    r->v = overflow;
    r->db = 0xC6;
    r->sp -= 1;
    JSR(c, 0x4415, 0xC645A9); /* await_next_scene_vblank_through_long_port_read */
    r->sp += 1;
    uint16_t a_all = r->a;
    BUS8_SET(c, 0x002121, 0);
    uint8_t value3 = BUS8(c, 0xC60000 + 0x75D0);
    RAM8(0x0048) = value3;
    uint8_t value4 = BUS8(c, 0xC60001 + 0x75D0);
    RAM8(0x0049) = value4;
    uint8_t a_hi4 = a_all >> 8;
    uint16_t x4 = 0x75D0;
    uint16_t y3 = 0x10;
    for (;;) {
        uint8_t value5 = BUS8(c, 0xC60000 + x4);
        BUS8_SET(c, 0x002122, value5);
        uint8_t value6 = BUS8(c, 0xC60001 + x4);
        BUS8_SET(c, 0x002122, value6);
        x4 = (uint16_t)(x4 + 2);
        y3 = (uint16_t)(y3 - 1);
        if (!(y3 != 0)) break;
    }
    BUS8_SET(c, 0x002121, 0x80);
    uint8_t a_hi5 = a_hi4;
    uint16_t x5 = 0x75F0;
    uint16_t y4 = 8;
    for (;;) {
        uint8_t value7 = BUS8(c, 0xC60000 + x5);
        BUS8_SET(c, 0x002122, value7);
        uint8_t value8 = BUS8(c, 0xC60001 + x5);
        BUS8_SET(c, 0x002122, value8);
        x5 = (uint16_t)(x5 + 2);
        y4 = (uint16_t)(y4 - 1);
        if (!(y4 != 0)) break;
    }
    BUS16_SET(c, 0x002116, 0x4000);
    BUS8_SET(c, 0x004300, 1);
    BUS8_SET(c, 0x004301, 0x18);
    BUS16_SET(c, 0x004302, 0x6700);
    BUS8_SET(c, 0x004304, 0xC6);
    BUS16_SET(c, 0x004305, 0x80);
    BUS8_SET(c, 0x00420B, 1);
    BUS16_SET(c, 0x002116, 0x4100);
    BUS16_SET(c, 0x004305, 0x80);
    BUS8_SET(c, 0x00420B, 1);
    BUS16_SET(c, 0x002116, 0x4200);
    BUS16_SET(c, 0x004305, 0x80);
    BUS8_SET(c, 0x00420B, 1);
    BUS16_SET(c, 0x002116, 0x4300);
    BUS16_SET(c, 0x004305, 0x80);
    BUS8_SET(c, 0x00420B, 1);
    BUS16_SET(c, 0x002116, 0x4040);
    BUS16_SET(c, 0x004305, 0xC0);
    BUS8_SET(c, 0x00420B, 1);
    BUS16_SET(c, 0x002116, 0x4180);
    BUS16_SET(c, 0x004305, 0x40);
    BUS8_SET(c, 0x00420B, 1);
    r->a = (a_hi5 << 8) | 1;
    r->y = y4;
    r->c = carry1;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    r->db = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC6438F, SOM_RTS, "gen", initialize_mode_seven_transition_vram_and_palettes, 0, L_B | L_Y | L_C | L_V, 2, 1, 0, 332, 133)
