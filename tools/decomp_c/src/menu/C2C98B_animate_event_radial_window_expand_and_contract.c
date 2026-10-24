#include "som_c.h"

/* C2C98B animate_event_radial_window_expand_and_contract   [class D, 76 bytes, 33 instructions]
 * Source: src/rom/animate_event_radial_window_expand_and_contract.s
 * Documented in docs/event-menu-effect-animation.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void animate_event_radial_window_expand_and_contract(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x0018 + dp, 0);
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            r->a = (a_hi1 << 8) | a;
            r->x = x1;
            r->y = y1;
            r->c = carry1;
            r->v = overflow1;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = dp;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC991, 0xC2C9D7); GUARD_JSR(c, sp_call, 0xC991); } /* update_event_radial_window_and_particles */
            uint16_t a_all = r->a;
            uint16_t x_ret = r->x;
            uint16_t y_ret = r->y;
            uint8_t value = RAM8(0x0018 + dp);
            if (value + 1 <= 0xFF) {
                RAM8(0x0018 + dp) = (uint8_t)(value + 1);
                a_hi1 = a_all >> 8;
                x1 = x_ret;
                y1 = y_ret;
                carry1 = value + 1 > 0xFF;
                overflow1 = ((value ^ (uint8_t)(value + 1)) & ((uint8_t)(value + 1) ^ 1) & 0x80) != 0;
                first_pass = false;
                continue;
            }
            a_hi1 = a_all >> 8;
            x1 = x_ret;
            y1 = y_ret;
            carry1 = value + 1 > 0xFF;
            overflow1 = ((value ^ (uint8_t)(value + 1)) & ((uint8_t)(value + 1) ^ 1) & 0x80) != 0;
            break;
        } else {
            r->a = (a_hi1 << 8) | a;
            r->x = x1;
            r->y = y1;
            r->c = carry1;
            r->v = overflow1;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = dp;
            { const uint16_t sp_call = r->sp; JSR(c, 0xC991, 0xC2C9D7); GUARD_JSR(c, sp_call, 0xC991); } /* update_event_radial_window_and_particles */
            uint16_t a_all2 = r->a;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret2 = r->y;
            uint8_t value2 = RAM8(0x0018 + dp);
            if (value2 + 1 <= 0xFF) {
                RAM8(0x0018 + dp) = (uint8_t)(value2 + 1);
                a_hi1 = a_all2 >> 8;
                x1 = x_ret2;
                y1 = y_ret2;
                carry1 = value2 + 1 > 0xFF;
                overflow1 = ((value2 ^ (uint8_t)(value2 + 1)) & ((uint8_t)(value2 + 1) ^ 1) & 0x80) != 0;
                continue;
            }
            a_hi1 = a_all2 >> 8;
            x1 = x_ret2;
            y1 = y_ret2;
            carry1 = value2 + 1 > 0xFF;
            overflow1 = ((value2 ^ (uint8_t)(value2 + 1)) & ((uint8_t)(value2 + 1) ^ 1) & 0x80) != 0;
            break;
        }
    }
    RAM8(0x0019 + dp)--;
    uint8_t a_hi2 = a_hi1;
    uint16_t x2 = x1;
    uint16_t y2 = y1;
    bool carry2 = carry1;
    bool overflow2 = overflow1;
    for (;;) {
        r->a = (a_hi2 << 8) | a;
        r->x = x2;
        r->y = y2;
        r->c = carry2;
        r->v = overflow2;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = dp;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC9A3, 0xC2C9D7); GUARD_JSR(c, sp_call, 0xC9A3); } /* update_event_radial_window_and_particles */
        uint16_t a_all3 = r->a;
        uint16_t x_ret3 = r->x;
        uint16_t y_ret3 = r->y;
        uint8_t value4 = RAM8(0x0018 + dp);
        if (value4 >= 1) {
            RAM8(0x0018 + dp) = (uint8_t)(value4 - 1);
            a_hi2 = a_all3 >> 8;
            x2 = x_ret3;
            y2 = y_ret3;
            carry2 = value4 >= 1;
            overflow2 = ((value4 ^ 1) & (value4 ^ (uint8_t)(value4 - 1)) & 0x80) != 0;
            continue;
        }
        a_hi2 = a_all3 >> 8;
        x2 = x_ret3;
        y2 = y_ret3;
        carry2 = value4 >= 1;
        overflow2 = ((value4 ^ 1) & (value4 ^ (uint8_t)(value4 - 1)) & 0x80) != 0;
        break;
    }
    r->y = y2;
    r->c = carry2;
    r->v = overflow2;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = dp;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC9B3, 0xC2CD55); GUARD_JSR(c, sp_call, 0xC9B3); } /* clear_event_radial_particle_oam */
    RAM8(0x002C + dp) = 0;
    BUS8_SET(c, 0x002125, 0);
    BUS8_SET(c, 0x00212C, RAM8(0x0021 + dp));
    BUS8_SET(c, 0x002130, 2);
    BUS8_SET(c, 0x002131, RAM8(0x0023 + dp));
    BUS8_SET(c, 0x002132, 0xE0);
    SET_A8(r, 0xE0);
    r->z = 0;
    r->n = 1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2C98B, SOM_RTS, "gen", animate_event_radial_window_expand_and_contract, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 76, 33)
