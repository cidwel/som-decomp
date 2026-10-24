#include "som_c.h"

/* C09985 install_relocated_scene_row_rle_decoder   [class A, 17 bytes, 9 instructions]
 * Source: src/rom/install_relocated_scene_row_rle_decoder.s
 * Documented in docs/ui-native-scene-tile-rows.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: XYCV.
 */
static void install_relocated_scene_row_rle_decoder(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi1 = a >> 8;
    uint8_t x1 = 0x3E;
    for (;;) {
        uint16_t value = BUS16(c, 0x009A60 + x1);
        RAM16_SET(0x0B00 + x1, value);
        a_hi1 = value >> 8;
        x1 = (uint8_t)(x1 - 2);
        if (!(!(x1 & 0x80))) break;
    }
    r->x = x1;
    r->y = y;
    r->c = carry;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC09985, SOM_RTS, "gen", install_relocated_scene_row_rle_decoder, 0, L_X | L_Y | L_C | L_V, 1, 0, 1, 17, 9)
