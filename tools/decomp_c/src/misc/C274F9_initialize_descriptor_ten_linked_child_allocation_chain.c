#include "som_c.h"

/* C274F9 initialize_descriptor_ten_linked_child_allocation_chain   [class B, 268 bytes, 96 instructions]
 * Source: src/rom/initialize_descriptor_ten_linked_child_allocation_chain.s
 * Documented in docs/boss-descriptor-ten.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_descriptor_ten_linked_child_allocation_chain(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    JSR(c, 0x74FB, 0xC20CE0); /* set_boss_animation_bank_low_byte_c7 */
    RAM16_SET(0x0358, RAM16(0x002B + x));
    RAM16_SET(0x035C, RAM16(0x0032 + x));
    RAM16_SET(0x001E + x, 2);
    RAM16_SET(0x000B + x, 2);
    RAM16_SET(0x0066 + x, 0);
    r->a = 2;
    r->x = 0x77A7;
    r->y = 0x1801;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x751C, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret = r->x;
    RAM16_SET(0x00B0 + x_ret, RAM16(0x0287));
    RAM16_SET(0x00B2 + x_ret, 0);
    RAM16_SET(0x00B4 + x_ret, 1);
    RAM16_SET(0x0295, x_ret);
    r->a = 1;
    r->x = 0x77A7;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x7538, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret2 = r->x;
    RAM16_SET(0x00B0 + x_ret2, RAM16(0x0295));
    RAM16_SET(0x00B2 + x_ret2, 0xCC);
    RAM16_SET(0x00B4 + x_ret2, 2);
    RAM16_SET(0x0295, x_ret2);
    r->a = 2;
    r->x = 0x77A7;
    r->y = 0x3801;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x7554, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret3 = r->x;
    RAM16_SET(0x00B0 + x_ret3, RAM16(0x0295));
    RAM16_SET(0x00B2 + x_ret3, 0x0198);
    RAM16_SET(0x00B4 + x_ret3, 4);
    RAM16_SET(0x0295, x_ret3);
    r->a = 4;
    r->x = 0x77A7;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x7570, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret4 = r->x;
    RAM16_SET(0x00B0 + x_ret4, RAM16(0x0295));
    RAM16_SET(0x00B2 + x_ret4, 0x0264);
    RAM16_SET(0x00B4 + x_ret4, 8);
    RAM16_SET(0x0295, x_ret4);
    r->a = 8;
    r->x = 0x77A7;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x758C, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret5 = r->x;
    bool carry_ret5 = r->c;
    bool overflow_ret5 = r->v;
    RAM16_SET(0x00B0 + x_ret5, RAM16(0x0295));
    RAM16_SET(0x00B2 + x_ret5, 0x0330);
    RAM16_SET(0x00B4 + x_ret5, 8);
    RAM16_SET(0x0295, x_ret5);
    uint16_t value9 = RAM16(0x0042 + RAM16(0x0287));
    uint8_t a_hi1;
    bool carry1;
    bool overflow1;
    if (value9 != 0) {
        a_hi1 = value9 >> 8;
        carry1 = carry_ret5;
        overflow1 = overflow_ret5;
    } else {
        r->a = value9;
        r->x = 0x77A7;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x75AF, 0xC20D53); /* allocate_boss_object_pool_slot */
        uint16_t x_ret6 = r->x;
        bool carry_ret6 = r->c;
        bool overflow_ret6 = r->v;
        RAM16_SET(0x00B0 + x_ret6, RAM16(0x0295));
        RAM16_SET(0x00B2 + x_ret6, 0x03FC);
        RAM16_SET(0x00B4 + x_ret6, 8);
        RAM16_SET(0x0295, x_ret6);
        a_hi1 = 0;
        carry1 = carry_ret6;
        overflow1 = overflow_ret6;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = 0x77BF;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x75CB, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret7 = r->x;
    RAM16_SET(0x00B0 + x_ret7, RAM16(0x0295));
    RAM16_SET(0x00B2 + x_ret7, 0x04C8);
    RAM16_SET(0x00B4 + x_ret7, 8);
    RAM16_SET(0x0042 + x_ret7, 0);
    RAM16_SET(0x0295, x_ret7);
    r->a = 8;
    r->x = 0x77BF;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x75EA, 0xC20D53); /* allocate_boss_object_pool_slot */
    uint16_t x_ret8 = r->x;
    RAM16_SET(0x00B0 + x_ret8, RAM16(0x0295));
    RAM16_SET(0x00B2 + x_ret8, 0x0594);
    RAM16_SET(0x00B4 + x_ret8, 8);
    RAM16_SET(0x0042 + x_ret8, 1);
    RAM16_SET(0x0295, x_ret8);
    r->a = 1;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC274F9, SOM_RTS, "gen", initialize_descriptor_ten_linked_child_allocation_chain, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 268, 96)
