#include "som_c.h"

/* 7EA07B release_colour_tree   [class A, 21 bytes, 14 instructions]
 * Source: src/boot/release_colour_tree.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$0500.  Callers read: BYCZNV.
 */
static void release_colour_tree(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x0500) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x1008A);
    r->a = (a_hi << 8) | 0x7F;
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->sp -= 4;
    JSR(c, 0xA08B, 0x7EB0D6); /* release_native_heap_suffix_through_bank_7f_api */
    r->sp += 4;
    r->c = carry;
    r->z = 0;
    r->n = 0;
    r->v = overflow;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA07B, SOM_RTS, "gen", release_colour_tree, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 21, 14)
