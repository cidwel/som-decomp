#include "som_c.h"

/* C24AD6 enter_native54_return_state_after_attack_notification   [class B, 20 bytes, 9 instructions]
 * Source: src/rom/enter_native54_return_state_after_attack_notification.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void enter_native54_return_state_after_attack_notification(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    r->x = battle_defence_work;
    r->z = battle_defence_work == 0;
    r->n = battle_defence_work & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4ADA, 0xC2496C); GUARD_JSR(c, sp_call, 0x4ADA); } /* consume_native54_action_damage_and_initialize_auxiliary_recoil */
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    bool carry_ret = r->c;
    bool zero_ret = r->z;
    bool negative_ret = r->n;
    uint8_t a2;
    uint8_t a_hi2;
    bool zero2;
    bool negative2;
    if (carry_ret) {
        a2 = (uint8_t)a_all;
        a_hi2 = a_all >> 8;
        zero2 = zero_ret;
        negative2 = negative_ret;
    } else {
        uint16_t value = BUS16_RDP(c, (db_ret << 0x10) + 0xB8 + x_ret2);
        uint8_t a1;
        uint8_t a_hi1;
        bool zero1;
        bool negative1;
        if (value == 0) {
            a1 = (uint8_t)value;
            a_hi1 = value >> 8;
            zero1 = value == 0;
            negative1 = value & 0x8000;
        } else {
            BUS16_SET(c, (db_ret << 0x10) + 0x94 + x_ret2, 7);
            a1 = 7;
            a_hi1 = 0;
            zero1 = 0;
            negative1 = 0;
        }
        a2 = a1;
        a_hi2 = a_hi1;
        zero2 = zero1;
        negative2 = negative1;
    }
    r->a = (a_hi2 << 8) | a2;
    r->c = 0;
    r->z = zero2;
    r->n = negative2;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24AD6, SOM_RTS, "gen", enter_native54_return_state_after_attack_notification, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 20, 9)
