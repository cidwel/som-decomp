#include "som_c.h"

/* C25EC3 shift_linked_child_signed_word_right_once   [class A, 6 bytes, 6 instructions]
 * Source: src/rom/shift_linked_child_signed_word_right_once.s
 * Documented in docs/boss-native-linked-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCV.
 */
static void shift_linked_child_signed_word_right_once(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool carry = r->c;
    r->a = ((((uint16_t)((a << 1) | carry) >> 1) | (a >> 0x0F << 0x0F)) >> 1) | (a >> 0x0F << 0x0F);
    r->c = (((uint16_t)((a << 1) | carry) >> 1) | (a >> 0x0F << 0x0F)) & 0x01;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25EC3, SOM_RTS, "gen", shift_linked_child_signed_word_right_once, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 6, 6)
