#include "som_c.h"

/* C25B10 advance_linked_child_periodic_target_motion_and_select_attack   [class B, 100 bytes, 39 instructions]
 * Source: src/rom/advance_linked_child_periodic_target_motion_and_select_attack.s
 * Documented in docs/boss-native-linked-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_linked_child_periodic_target_motion_and_select_attack(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const bool overflow = r->v;
    uint16_t value = RAM16(OBJECT_AGE + x);
    uint8_t a_hi4;
    uint16_t y1;
    bool carry2;
    if (value == 0x40) {
        uint16_t value2 = RAM16(0x00B0 + x);
        uint16_t value3 = RAM16(0x002D + value2);
        uint16_t value4 = RAM16(0x00AD + value2);
        uint8_t a_hi1;
        if (value3 >> 1 >= value4) {
            RAM16_SET(0x008E + x, 0x5CC8);
            a_hi1 = 0x5C;
        } else {
            RAM16_SET(0x008E + x, 0x5B86);
            a_hi1 = 0x5B;
        }
        a_hi4 = a_hi1;
        y1 = value2;
        carry2 = value3 >> 1 >= value4;
    } else {
        uint16_t value5 = RAM16(0x00B0 + x);
        uint16_t value6 = RAM16(0x0190 + value5);
        uint8_t a_hi3;
        bool carry1;
        if ((value6 & 3) != 0) {
            a_hi3 = value6 >> 8;
            carry1 = value >= 0x40;
        } else {
            uint16_t value7 = RAM16(0x002D + value5);
            uint16_t value8 = RAM16(0x00AD + value5);
            uint8_t a_hi2;
            if (value7 >> 1 >= value8) {
                RAM16_SET(0x008E + x, 0x5CC8);
                a_hi2 = 0x5C;
            } else {
                RAM16_SET(0x008E + x, 0x5B86);
                a_hi2 = 0x5B;
            }
            a_hi3 = a_hi2;
            carry1 = value7 >> 1 >= value8;
        }
        a_hi4 = a_hi3;
        y1 = value5;
        carry2 = carry1;
    }
    uint16_t value9 = RAM16(0x0049 + x);
    uint8_t a_hi5;
    uint16_t x1;
    uint16_t y2;
    bool overflow1;
    if ((value9 & 0x1F) != 0) {
        a_hi5 = value9 >> 8;
        x1 = x;
        y2 = y1;
        overflow1 = overflow;
    } else {
        r->y = y1;
        r->c = carry2;
        JSR(c, 0x5B47, 0xC25DEF); /* derive_linked_child_random_wave_velocity_toward_variant_origin */
        uint16_t x_ret = r->x;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        RAM16_SET(0x00BC + x_ret, RAM16(0x0076 + x_ret));
        uint16_t value11 = RAM16(0x0078 + x_ret);
        RAM16_SET(0x00BE + x_ret, value11);
        a_hi5 = value11 >> 8;
        x1 = x_ret;
        y2 = y_ret;
        overflow1 = overflow_ret;
    }
    uint16_t value12 = RAM16(0x0049 + x1);
    RAM16_SET(0x0049 + x1, (uint16_t)(value12 + 1));
    uint16_t value13 = BUS16(c, 0xC25DDF + (((uint16_t)(value12 + 1) >> 1) & 0x0E));
    RAM16_SET(0x00B4 + RAM16(0x0287), value13);
    r->a = value13;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5B6B, 0xC25CF1); /* integrate_linked_child_tip_velocity_with_parent_status_gate */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5B6E, 0xC25E44); /* advance_linked_child_strip_ring_and_parent_coordinates */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x5B71, 0xC25E7B); /* set_linked_child_tip_piece_attribute_bit_40 */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25B10, SOM_RTS, "gen", advance_linked_child_periodic_target_motion_and_select_attack, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 100, 39)
