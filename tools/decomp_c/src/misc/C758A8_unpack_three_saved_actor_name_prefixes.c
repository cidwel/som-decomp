#include "som_c.h"

/* C758A8 unpack_three_saved_actor_name_prefixes   [class B, 41 bytes, 22 instructions]
 * Source: src/rom/unpack_three_saved_actor_name_prefixes.s
 * Documented in docs/ui-native-loaded-game-save-load.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void unpack_three_saved_actor_name_prefixes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0xA175) = 3;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = 0xE000;
    bool carry1 = carry;
    bool overflow1 = overflow;
    do {
        RAM8(0x0000 + sp0) = y1 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)y1;
        uint8_t a1 = 6;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        uint16_t y2 = y1;
        for (;;) {
            uint8_t value = BUS8(c, 0x306000 + x2);
            RAM8(0x0000 + y2) = value;
            a1 = (uint8_t)(a1 - 1);
            a_hi2 = value;
            x2 = (uint16_t)(x2 + 1);
            y2 = (uint16_t)(y2 + 1);
            if (!(a1 != 0)) break;
        }
        uint8_t value2 = RAM8(0x0000 + sp0 - 1);
        uint8_t value3 = RAM8(0x0000 + sp0);
        RAM8(0xA175)--;
        a_hi1 = (uint16_t)(((value3 << 8) | value2) + 0x0200) >> 8;
        x1 = x2;
        y1 = (uint16_t)(((value3 << 8) | value2) + 0x0200);
        carry1 = ((value3 << 8) | value2) + 0x0200 > 0xFFFF;
        overflow1 = ((((value3 << 8) | value2) ^ (uint16_t)(((value3 << 8) | value2) + 0x0200)) & ((uint16_t)(((value3 << 8) | value2) + 0x0200) ^ 0x0200) & 0x8000) != 0;
    } while (RAM8(0xA175) != 0);
    r->a = (a_hi1 << 8) | a;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC758A8, SOM_RTS, "gen", unpack_three_saved_actor_name_prefixes, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 41, 22)
