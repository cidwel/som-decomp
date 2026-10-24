#include "som_c.h"

/* C25D2D relax_linked_child_velocity_by_signed_one_thirty_second   [class B, 47 bytes, 21 instructions]
 * Source: src/rom/relax_linked_child_velocity_by_signed_one_thirty_second.s
 * Documented in docs/boss-native-linked-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XV.
 */
static void relax_linked_child_velocity_by_signed_one_thirty_second(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = value;
    uint16_t y1 = 2;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value2 = RAM16(0x0076 + x1);
        uint16_t value3 = RAM16(0x00BC + x1);
        r->a = (uint16_t)(value2 - value3);
        r->x = x1;
        r->y = y1;
        r->c = value2 >= value3;
        r->v = ((value2 ^ value3) & (value2 ^ (uint16_t)(value2 - value3)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0200;
        JSR(c, 0x5D3B, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x5D3E, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x5D41, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x5D44, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x5D47, 0xC25EC3); /* shift_linked_child_signed_word_right_once */
        uint16_t a_all5 = r->a;
        RAM16_SET(0x0200, a_all5);
        uint16_t value4 = RAM16(0x00BC + x1);
        uint16_t value5 = RAM16(0x0200);
        RAM16_SET(0x00BC + x1, (uint16_t)(value4 + value5));
        a_hi1 = (uint16_t)(value4 + value5) >> 8;
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 - 1);
        overflow1 = ((value4 ^ (uint16_t)(value4 + value5)) & (value5 ^ (uint16_t)(value4 + value5)) & 0x8000) != 0;
        if (!(y1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    JSR(c, 0x5D5A, 0xC25CF1); /* integrate_linked_child_tip_velocity_with_parent_status_gate */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25D2D, SOM_RTS, "gen", relax_linked_child_velocity_by_signed_one_thirty_second, 0, L_X | L_V, 1, 0, 0, 47, 21)
