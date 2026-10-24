#include "som_c.h"

/* C03888 random_below_byte   [class A, 20 bytes, 9 instructions]
 * Source: src/rom/random_below_byte.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYV.
 */
static void random_below_byte(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    BUS8_SET(c, 0x004202, a);
    { const uint16_t sp_call = r->sp; JSR(c, 0x388E, 0xC038A0); GUARD_JSR(c, sp_call, 0x388E); } /* advance_additive_random_generator */
    bool m_ret = r->mf;
    uint16_t a_all = r->a;
    if (m_ret) {
        BUS8_SET(c, 0x004203, (uint8_t)a_all);
        uint8_t value = BUS8(c, 0x004217);
        SET_A8(r, value);
        r->mf = 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        BUS16_SET(c, 0x004203, a_all);
        uint16_t value2 = BUS16(c, 0x004217);
        r->a = value2;
        r->mf = 0;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC03888, SOM_RTS, "gen", random_below_byte, 0, L_A | L_B | L_X | L_Y | L_V, 1, 1, 0, 20, 9)
