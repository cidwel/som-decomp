#include "som_c.h"

/* D0D5D7 set_native_menu_dialogue_script_and_close_prior_window   [class A, 28 bytes, 14 instructions]
 * Source: src/rom/set_native_menu_dialogue_script_and_close_prior_window.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void set_native_menu_dialogue_script_and_close_prior_window(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    uint8_t value = RAM8(0x1D04);
    uint8_t a_hi1;
    bool carry1;
    bool overflow1;
    if ((value & 1) == 0) {
        a_hi1 = a >> 8;
        carry1 = carry;
        overflow1 = value & 0x40;
    } else {
        r->a = (a >> 8 << 8) | 1;
        r->z = (value & 1) == 0;
        r->n = value & 0x80;
        r->v = value & 0x40;
        r->mf = 1;
        r->sp -= 3;
        JSL(c, 0xD5E7, 0xC00095); /* close_dialogue_public_jump */
        r->sp += 3;
        uint16_t a_all = r->a;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        a_hi1 = a_all >> 8;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
    }
    RAM8(0x1D03) = (uint8_t)a;
    RAM16_SET(0x1D01, x);
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = x;
    r->c = carry1;
    r->z = (uint8_t)a == 0;
    r->n = (uint8_t)a & 0x80;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D5D7, SOM_RTS, "gen", set_native_menu_dialogue_script_and_close_prior_window, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 0, 0, 28, 14)
