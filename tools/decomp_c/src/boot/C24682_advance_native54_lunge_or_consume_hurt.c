#include "som_c.h"

/* C24682 advance_native54_lunge_or_consume_hurt   [class B, 50 bytes, 22 instructions]
 * Source: src/rom/advance_native54_lunge_or_consume_hurt.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_native54_lunge_or_consume_hurt(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0287);
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4686, 0xC2496C); GUARD_JSR(c, sp_call, 0x4686); } /* consume_native54_action_damage_and_initialize_auxiliary_recoil */
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    uint16_t x_ret2 = r->x;
    bool carry_ret = r->c;
    if (carry_ret) {
        r->c = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    uint16_t value2 = BUS16_RDP(c, (db_ret << 0x10) + 0x96 + x_ret2);
    if (value2 != 6) {
        r->a = value2;
        r->c = value2 >= 6;
        r->z = value2 == 6;
        r->n = (uint16_t)(value2 - 6) & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0x46B1, 0xC246B4); GUARD_JSR(c, sp_call, 0x46B1); } /* accelerate_native54_auxiliary_lunge */
        r->c = 0;
        r->mf = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    BUS16_SET(c, (db_ret << 0x10) + 0x94 + x_ret2, 0x0C);
    BUS16_SET(c, (db_ret << 0x10) + 0x96 + x_ret2, 0);
    BUS8_SET(c, (db_ret << 0x10) + 0xF812 + y, 0xC1);
    BUS8_SET(c, (db_ret << 0x10) + 0xF80E + y, 0xDE);
    BUS8_SET(c, (db_ret << 0x10) + 0xF813 + y, 0x40);
    r->a = 0x40;
    r->c = 0;
    r->z = 0;
    r->n = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24682, SOM_RTS, "gen", advance_native54_lunge_or_consume_hurt, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 50, 22)
