#include "som_c.h"

/* C26BAE spawn_boss_child_with_direction_velocity_and_parent   [class B, 81 bytes, 34 instructions]
 * Source: src/rom/spawn_boss_child_with_direction_velocity_and_parent.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void spawn_boss_child_with_direction_velocity_and_parent(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    BUS8_SET(c, (uint16_t)(dp + 0x95), RAM8(0x002B + x));
    BUS8_SET(c, (uint16_t)(dp + 0x97), RAM8(0x0032 + x));
    BUS8_SET(c, (uint16_t)(dp + 0x9D), RAM8(0x00A9 + x));
    BUS16_SET(c, (uint16_t)(dp + 0x9F), x);
    uint8_t value4 = RAM8(0x00AB + x);
    uint8_t value5 = BUS8(c, 0xDCE440 + ((a_hi << 8) | (uint8_t)(value4 << 2)));
    BUS8_SET(c, (uint16_t)(dp + 0x99), value5);
    uint8_t value6 = BUS8(c, 0xDCE442 + ((a_hi << 8) | (uint8_t)(value4 << 2)));
    BUS8_SET(c, (uint16_t)(dp + 0x9B), value6);
    r->a = (a_hi << 8) | value6;
    r->x = 0x6D6F;
    r->y = 0xA901;
    r->c = (uint8_t)(value4 << 1) & 0x80;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6BD9, 0xC20D53); GUARD_JSR(c, sp_call, 0x6BD9); } /* allocate_boss_object_pool_slot */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
    bool overflow_ret = r->v;
    uint8_t a1;
    uint8_t a_hi1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (carry_ret) {
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        carry1 = carry_ret;
        zero1 = zero_ret;
        negative1 = negative_ret;
        overflow1 = overflow_ret;
    } else {
        uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp + 0x95));
        RAM16_SET(0x002B + x_ret, value7);
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp + 0x97));
        RAM16_SET(0x0032 + x_ret, (uint16_t)(value8 - 0x20));
        uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp + 0x99));
        RAM16_SET(0x003C + x_ret, value9);
        uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp + 0x9B));
        RAM16_SET(0x0040 + x_ret, value10);
        uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp + 0x9D));
        RAM16_SET(0x00A9 + x_ret, value11);
        uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp + 0x9F));
        RAM16_SET(0x00B0 + x_ret, value12);
        a1 = (uint8_t)value12;
        a_hi1 = value12 >> 8;
        carry1 = value8 >= 0x20;
        zero1 = value12 == 0;
        negative1 = value12 & 0x8000;
        overflow1 = ((value8 ^ 0x20) & (value8 ^ (uint16_t)(value8 - 0x20)) & 0x8000) != 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26BAE, SOM_RTS, "gen", spawn_boss_child_with_direction_velocity_and_parent, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 81, 34)
