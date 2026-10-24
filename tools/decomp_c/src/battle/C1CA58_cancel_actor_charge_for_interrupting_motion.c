#include "som_c.h"

/* C1CA58 cancel_actor_charge_for_interrupting_motion   [class B, 20 bytes, 9 instructions]
 * Source: src/rom/cancel_actor_charge_for_interrupting_motion.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void cancel_actor_charge_for_interrupting_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    uint8_t value = RAM8(0x005C);
    uint8_t a_hi4;
    bool carry4;
    bool overflow4;
    if (!(value & 0x80)) {
        uint8_t value2 = RAM8(0xE01C + x);
        uint8_t a_hi1;
        bool carry1;
        bool overflow1;
        if (!(value2 & 0x80)) {
            a_hi1 = a_hi;
            carry1 = carry;
            overflow1 = value & 0x40;
        } else {
            r->a = (a_hi << 8) | value2;
            JSR(c, 0xCA6A, 0xC1CACD); /* cancel_actor_charge_and_start_weapon_gauge */
            uint16_t a_all = r->a;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            a_hi1 = a_all >> 8;
            carry1 = carry_ret;
            overflow1 = overflow_ret;
        }
        a_hi4 = a_hi1;
        carry4 = carry1;
        overflow4 = overflow1;
    } else {
        uint8_t a_hi3;
        bool carry3;
        bool overflow3;
        if (x >= 0x0600) {
            a_hi3 = a_hi;
            carry3 = x >= 0x0600;
            overflow3 = value & 0x40;
        } else {
            uint8_t value3 = RAM8(0xE01C + x);
            uint8_t a_hi2;
            bool carry2;
            bool overflow2;
            if (!(value3 & 0x80)) {
                a_hi2 = a_hi;
                carry2 = x >= 0x0600;
                overflow2 = value & 0x40;
            } else {
                r->a = (a_hi << 8) | value3;
                JSR(c, 0xCA6A, 0xC1CACD); /* cancel_actor_charge_and_start_weapon_gauge */
                uint16_t a_all2 = r->a;
                bool carry_ret2 = r->c;
                bool overflow_ret2 = r->v;
                a_hi2 = a_all2 >> 8;
                carry2 = carry_ret2;
                overflow2 = overflow_ret2;
            }
            a_hi3 = a_hi2;
            carry3 = carry2;
            overflow3 = overflow2;
        }
        a_hi4 = a_hi3;
        carry4 = carry3;
        overflow4 = overflow3;
    }
    r->a = (a_hi4 << 8) | a;
    r->c = carry4;
    r->v = overflow4;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1CA58, SOM_RTS, "gen", cancel_actor_charge_for_interrupting_motion, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 20, 9)
