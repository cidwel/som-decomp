#include "som_c.h"

/* C7595C upload_native_saved_slot_six_byte_palette   [class D, 29 bytes, 15 instructions]
 * Source: src/rom/upload_native_saved_slot_six_byte_palette.s
 * Documented in docs/ui-native-loaded-game-slot-graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void upload_native_saved_slot_six_byte_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    BUS8_SET(c, 0x002121, 0x19);
    uint8_t a1 = 6;
    uint8_t a_hi1 = 0;
    uint16_t x1 = 0x30;
    for (;;) {
        uint8_t value = BUS8(c, 0xD2DBC0 + x1);
        BUS8_SET(c, 0x002122, value);
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = value;
        x1 = (uint16_t)(x1 + 1);
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y;
    r->c = carry;
    r->v = overflow;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC7595C, SOM_RTL, "gen", upload_native_saved_slot_six_byte_palette, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 29, 15)
