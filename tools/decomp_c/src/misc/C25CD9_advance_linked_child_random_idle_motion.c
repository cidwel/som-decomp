#include "som_c.h"

/* C25CD9 advance_linked_child_random_idle_motion   [class B, 24 bytes, 9 instructions]
 * Source: src/rom/advance_linked_child_random_idle_motion.s
 * Documented in docs/boss-native-linked-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_linked_child_random_idle_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x0015 + x, (uint16_t)(RAM16(0x0015 + x) - 1));
    uint16_t value = RAM16(0x0015 + x);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if ((value & 0x1F) != 0) {
        a1 = (uint8_t)value;
        a_hi1 = value >> 8;
        x1 = x;
        y1 = y;
        carry1 = carry;
        zero1 = (value & 0x1F) == 0;
        negative1 = value & 0x8000;
        overflow1 = overflow;
    } else {
        JSR(c, 0x5CE6, 0xC25DEF); /* derive_linked_child_random_wave_velocity_toward_variant_origin */
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool zero_ret = r->z;
        bool negative_ret = r->n;
        bool overflow_ret = r->v;
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = x_ret;
        y1 = y_ret;
        carry1 = carry_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5CE9, 0xC25D87); /* select_target_and_heading_from_linked_child_fractional_tip */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5CEC, 0xC25E44); /* advance_linked_child_strip_ring_and_parent_coordinates */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5CEF, 0xC25D2D); /* relax_linked_child_velocity_by_signed_one_thirty_second */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25CD9, SOM_RTS, "gen", advance_linked_child_random_idle_motion, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 24, 9)
