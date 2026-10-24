#include "som_c.h"

/* C02BD9 await_native_menu_autojoy_and_poll_full_controller_chain   [class D, 17 bytes, 7 instructions]
 * Source: src/rom/await_native_menu_autojoy_and_poll_full_controller_chain.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void await_native_menu_autojoy_and_poll_full_controller_chain(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    uint8_t a1 = a;
    uint8_t a_hi1 = a_hi;
    bool zero1 = zero;
    bool negative1 = negative;
    for (;;) {
        uint8_t value = BUS8(c, 0x004212);
        a1 = value & 1;
        zero1 = (value & 1) == 0;
        negative1 = value & 1 & 0x80;
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = (uint8_t)x;
    r->y = (uint8_t)y;
    r->c = carry;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow;
    r->xf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x2BE6, 0x008000); GUARD_JSL(c, sp_call, 0x2BE6); } /* public_controller_poll_long */
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02BD9, SOM_RTS, "gen", await_native_menu_autojoy_and_poll_full_controller_chain, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 17, 7)
