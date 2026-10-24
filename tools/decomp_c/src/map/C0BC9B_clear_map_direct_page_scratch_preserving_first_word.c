#include "som_c.h"

/* C0BC9B clear_map_direct_page_scratch_preserving_first_word   [class A, 16 bytes, 9 instructions]
 * Source: src/rom/clear_map_direct_page_scratch_preserving_first_word.s
 * Documented in docs/ui-native-map-entry-requests.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void clear_map_direct_page_scratch_preserving_first_word(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t x1 = 0xCE;
    for (;;) {
        RAM16_SET(0x0000 + x1, 0);
        x1 = (uint8_t)(x1 - 2);
        if (!(x1 != 0)) break;
    }
    r->a = 0;
    r->x = x1;
    r->y = y;
    r->c = carry;
    r->v = overflow;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0BC9B, SOM_RTS, "gen", clear_map_direct_page_scratch_preserving_first_word, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 16, 9)
