#include "som_c.h"

/* C04E6F select_actor_random_miss_reaction   [class B, 58 bytes, 24 instructions]
 * Source: src/rom/select_actor_random_miss_reaction.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void select_actor_random_miss_reaction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(ACTOR_STATUS + x);
    if ((value & 0xC57D) != 0) {
        r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
        RETURN_RTS(c);
    }
    if (RAM8(0xE1E5 + x) & 0x80) {
        uint8_t value3 = RAM8(0xE175 + x);
        bool x_flag;
        uint8_t a_hi1;
        uint16_t x1;
        uint16_t y1;
        bool carry1;
        bool overflow1;
        if (value3 != 0) {
            x_flag = 0;
            a_hi1 = value >> 8;
            x1 = x;
            y1 = y;
            carry1 = carry;
            overflow1 = overflow;
        } else {
            r->a = (value >> 8 << 8) | value3;
            r->z = value3 == 0;
            r->n = value3 & 0x80;
            { const uint16_t sp_call = r->sp; JSR(c, 0x4E88, 0xC038A0); GUARD_JSR(c, sp_call, 0x4E88); } /* advance_additive_random_generator */
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret = r->y;
            BUS8_SET(c, 0x004202, (uint8_t)a_all);
            BUS8_SET(c, 0x004203, 3);
            uint8_t value4 = RAM8(ACTOR_KIND_FLAGS + x_ret2);
            uint8_t a1;
            if ((value4 & 0x81) != 0) {
                a1 = 0x11;
            } else {
                a1 = 0x0C;
            }
            uint8_t value5 = BUS8(c, 0x004217);
            RAM8(0xE1E5 + x_ret2) = (uint8_t)(a1 + value5);
            x_flag = x_ret;
            a_hi1 = a_all >> 8;
            x1 = x_ret2;
            y1 = y_ret;
            carry1 = a1 + value5 > 0xFF;
            overflow1 = ((a1 ^ (uint8_t)(a1 + value5)) & (value5 ^ (uint8_t)(a1 + value5)) & 0x80) != 0;
        }
        r->a = (a_hi1 << 8) | a;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->v = overflow1;
        r->xf = x_flag;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
    r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04E6F, SOM_RTS, "gen", select_actor_random_miss_reaction, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 58, 24)
