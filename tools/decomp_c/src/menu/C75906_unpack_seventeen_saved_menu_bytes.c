#include "som_c.h"

/* C75906 unpack_seventeen_saved_menu_bytes   [class A, 20 bytes, 11 instructions]
 * Source: src/rom/unpack_seventeen_saved_menu_bytes.s
 * Documented in docs/ui-native-loaded-game-save-load.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void unpack_seventeen_saved_menu_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a1 = 0x11;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = 0;
    for (;;) {
        uint8_t value = BUS8(c, 0x306000 + x1);
        RAM8(0xA23E + y1) = value;
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = value;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 + 1);
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75906, SOM_RTS, "gen", unpack_seventeen_saved_menu_bytes, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 20, 11)
