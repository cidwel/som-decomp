#include "som_c.h"

/* C25C80 accelerate_linked_child_toward_variant_origin   [class B, 72 bytes, 30 instructions]
 * Source: src/rom/accelerate_linked_child_toward_variant_origin.s
 * Documented in docs/boss-native-linked-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void accelerate_linked_child_toward_variant_origin(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x5C82, 0xC25E44); /* advance_linked_child_strip_ring_and_parent_coordinates */
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x007A + value);
    uint16_t value3 = BUS16(c, 0xC25A39 + (uint16_t)(value2 << 2));
    RAM16_SET(0x0202, value3);
    uint16_t value4 = BUS16(c, 0xC25A3B + (uint16_t)(value2 << 2));
    RAM16_SET(0x0200, value4);
    uint16_t value5 = RAM16(0x0202);
    uint16_t value6 = RAM16(0x00B8 + value);
    r->a = (uint16_t)(value5 - value6);
    r->x = value;
    r->c = value5 >= value6;
    r->v = ((value5 ^ value6) & (value5 ^ (uint16_t)(value5 - value6)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5CA1, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5CA4, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5CA7, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5CAA, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
    uint16_t a_all5 = r->a;
    RAM16_SET(0x00BC + value, a_all5);
    uint16_t value7 = RAM16(0x0200);
    uint16_t value8 = RAM16(0x00BA + value);
    r->a = (uint16_t)(value7 - value8);
    r->c = value7 >= value8;
    r->v = ((value7 ^ value8) & (value7 ^ (uint16_t)(value7 - value8)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5CB6, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5CB9, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5CBC, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5CBF, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
    uint16_t a_all9 = r->a;
    RAM16_SET(0x00BE + value, a_all9);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5CC5, 0xC25CF1); /* integrate_linked_child_tip_velocity_with_parent_status_gate */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25C80, SOM_RTS, "gen", accelerate_linked_child_toward_variant_origin, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 72, 30)
