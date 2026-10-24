#include "som_c.h"

/* C256DB initialize_boss_parent_and_attempt_three_linked_child_allocations   [class B, 154 bytes, 59 instructions]
 * Source: src/rom/initialize_boss_parent_and_attempt_three_linked_child_allocations.s
 * Documented in docs/boss-native-linked-parent.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_boss_parent_and_attempt_three_linked_child_allocations(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    JSR(c, 0x56DD, 0xC20CE0); /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(0x00B8 + x, 0x20);
    uint16_t value = RAM16(0x0042 + x);
    uint8_t a_hi1;
    if (value != 0) {
        uint16_t value2 = RAM16(0x0098 + x);
        RAM16_SET(0x0098 + x, (value2 & 0xFFFC) | 2);
        a_hi1 = ((value2 & 0xFFFC) | 2) >> 8;
    } else {
        a_hi1 = value >> 8;
    }
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x56F9, 0xC25920); /* derive_boss_threshold_from_hardware_division_and_clamp */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x56FC, 0xC23372); /* derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction */
    RAM16_SET(0x0066 + x, 0);
    RAM16_SET(0x00A5 + x, 0);
    RAM16_SET(0x00A7 + x, 4);
    RAM16_SET(0x001E + x, 4);
    RAM16_SET(0x0000 + x, 1);
    r->a = 1;
    r->x = 0x311D;
    r->y = 0x3801;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x571A, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret = r->x;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    RAM16_SET(0x00B0 + x_ret, RAM16(0x0287));
    RAM16_SET(0x00A7 + x_ret, 4);
    RAM16_SET(0x0202, 1);
    uint8_t a_hi2 = 0;
    uint16_t y1 = 0x3801;
    bool carry1 = carry_ret3;
    bool overflow1 = overflow_ret3;
    do {
        r->a = (a_hi2 << 8) | (uint8_t)a;
        r->x = 0x59F7;
        r->y = 0x3821;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = 0x0200;
        JSR(c, 0x5733, 0xC20D53); /* allocate_boss_object_pool_slot */
        uint16_t x_ret2 = r->x;
        RAM16_SET(0x007A + x_ret2, RAM16(0x0202));
        RAM16_SET(0x0022 + x_ret2, 0x07FF);
        RAM16_SET(0x000B + x_ret2, 1);
        RAM16_SET(0x00B0 + x_ret2, RAM16(0x0287));
        uint16_t value6 = RAM16(0x0202);
        uint16_t value7 = RAM16(0x0287);
        RAM16_SET(0x00B0 + (uint16_t)((uint16_t)(value6 << 1) + value7), x_ret2);
        RAM16_SET(0x0202, (uint16_t)(RAM16(0x0202) - 1));
        a_hi2 = x_ret2 >> 8;
        y1 = (uint16_t)((uint16_t)(value6 << 1) + value7);
        carry1 = (uint16_t)(value6 << 1) + value7 > 0xFFFF;
        overflow1 = (((uint16_t)(value6 << 1) ^ (uint16_t)((uint16_t)(value6 << 1) + value7)) & (value7 ^ (uint16_t)((uint16_t)(value6 << 1) + value7)) & 0x8000) != 0;
    } while (!(RAM16(0x0202) & 0x8000));
    uint16_t value8 = RAM16(0x0287);
    r->a = 0x18;
    r->x = value8;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    JSR(c, 0x5760, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    uint16_t value9 = RAM16(0x0287);
    RAM16_SET(0x008E + value9, 0x5775);
    RAM16_SET(OBJECT_PHASE + value9, (uint16_t)(RAM16(OBJECT_PHASE + value9) + 1));
    r->a = 0x60;
    r->x = value9;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    JSL(c, 0x5772, 0xC0006C); /* boss_attack_row_public_jump */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC256DB, SOM_RTS, "gen", initialize_boss_parent_and_attempt_three_linked_child_allocations, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 154, 59)
