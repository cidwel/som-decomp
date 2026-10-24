#include "som_c.h"

/* C25C0B advance_linked_child_attack_strip_and_switch_at_tip_limit   [class B, 86 bytes, 35 instructions]
 * Source: src/rom/advance_linked_child_attack_strip_and_switch_at_tip_limit.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void advance_linked_child_attack_strip_and_switch_at_tip_limit(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B6 + x);
    RAM16_SET(0x00B6 + x, (uint16_t)(value + 1) & 0x0F);
    r->a = (uint16_t)(value + 1) & 0x0F;
    r->z = ((uint16_t)(value + 1) & 0x0F) == 0;
    r->n = (uint16_t)(value + 1) & 0x0F & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5C17, 0xC25D5C); GUARD_JSR(c, sp_call, 0x5C17); } /* follow_linked_child_parent_variant_position */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5C1A, 0xC25EC9); GUARD_JSR(c, sp_call, 0x5C1A); } /* interpolate_linked_child_four_piece_strip_history */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5C1D, 0xC25F60); GUARD_JSR(c, sp_call, 0x5C1D); } /* construct_linked_child_six_piece_strip_records */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5C20, 0xC25E7B); GUARD_JSR(c, sp_call, 0x5C20); } /* set_linked_child_tip_piece_attribute_bit_40 */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5C23, 0xC25E5D); GUARD_JSR(c, sp_call, 0x5C23); } /* prepare_linked_child_tip_collision_and_scan_real_party */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5C26, 0xC25D2D); GUARD_JSR(c, sp_call, 0x5C26); } /* relax_linked_child_velocity_by_signed_one_thirty_second */
    uint16_t a_all6 = r->a;
    uint16_t x_ret5 = r->x;
    bool overflow_ret6 = r->v;
    uint8_t a_hi1 = a_all6 >> 8;
    uint16_t x1 = x_ret5;
    uint16_t y1 = 2;
    for (;;) {
        uint16_t value2 = RAM16(0x00B8 + x1);
        uint8_t a1;
        uint8_t a_hi2;
        if (!(value2 & 0x8000)) {
            a1 = (uint8_t)value2;
            a_hi2 = value2 >> 8;
        } else {
            a1 = (uint8_t)((value2 ^ 0xFFFF) + 1);
            a_hi2 = (uint16_t)((value2 ^ 0xFFFF) + 1) >> 8;
        }
        if (((a_hi2 << 8) | a1) >= 0x3800) {
            uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
            r->a = (a_hi2 << 8) | a1;
            r->x = value3;
            r->y = y1;
            r->c = ((a_hi2 << 8) | a1) >= 0x3800;
            r->z = value3 == 0;
            r->n = value3 & 0x8000;
            r->v = overflow_ret6;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x5C47, 0xC25E8C); GUARD_JSR(c, sp_call, 0x5C47); } /* clear_linked_child_strip_piece_attribute_bit_40 */
            RAM16_SET(0x0078 + value3, 0);
            RAM16_SET(0x0076 + value3, 0);
            RAM16_SET(0x00BC + value3, 0);
            RAM16_SET(0x00BE + value3, 0);
            RAM16_SET(0x008E + value3, 0x5C61);
            r->a = 0x5C61;
            r->z = 0;
            r->n = 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x5C5C, 0xC25E9D); GUARD_JSR(c, sp_call, 0x5C5C); } /* consume_linked_child_request_and_select_native_definition */
            uint16_t x_ret6 = r->x;
            RAM16_SET(0x00C2 + x_ret6, 0);
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        if ((uint16_t)(y1 - 1) != 0) {
            a_hi1 = a_hi2;
            x1 = (uint16_t)(x1 + 2);
            y1 = (uint16_t)(y1 - 1);
            continue;
        }
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
        r->a = (a_hi2 << 8) | a1;
        r->x = value4;
        r->y = (uint16_t)(y1 - 1);
        r->c = ((a_hi2 << 8) | a1) >= 0x3800;
        r->z = value4 == 0;
        r->n = value4 & 0x8000;
        r->v = overflow_ret6;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5C41, 0xC25E9D); GUARD_JSR(c, sp_call, 0x5C41); } /* consume_linked_child_request_and_select_native_definition */
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC25C0B, SOM_RTS, "gen", advance_linked_child_attack_strip_and_switch_at_tip_limit, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 86, 35)
