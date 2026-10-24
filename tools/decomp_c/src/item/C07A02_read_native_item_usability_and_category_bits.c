#include "som_c.h"

/* C07A02 read_native_item_usability_and_category_bits   [class A, 38 bytes, 24 instructions]
 * Source: src/rom/read_native_item_usability_and_category_bits.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void read_native_item_usability_and_category_bits(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = BUS8(c, 0xD03ED0 + ((((a_hi << 8) | a) & 0x3F) << 1 << 1 << 1) + ((((a_hi << 8) | a) & 0x3F) << 1));
    uint8_t value2 = BUS8(c, 0xD03ED5 + ((((a_hi << 8) | a) & 0x3F) << 1 << 1 << 1) + ((((a_hi << 8) | a) & 0x3F) << 1));
    r->a = (value2 & 0xE0) >> 1 | (value & 0x80);
    r->x = (value2 & 0xE0) >> 1 | (value & 0x80);
    RETURN_RTL(c);
}
SOM_REGISTER(0xC07A02, SOM_RTL, "gen", read_native_item_usability_and_category_bits, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 3, 1, 1, 38, 24)
