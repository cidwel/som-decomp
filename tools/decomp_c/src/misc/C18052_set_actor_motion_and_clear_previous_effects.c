#include "som_c.h"

/* C18052 set_actor_motion_and_clear_previous_effects   [class A, 29 bytes, 14 instructions]
 * Source: src/rom/set_actor_motion_and_clear_previous_effects.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void set_actor_motion_and_clear_previous_effects(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 1) = y >> 8;
    RAM8(0x0000 + sp0 - 2) = (uint8_t)y;
    RAM8(0xE011 + x) = a;
    RAM8(0xE006 + x) = 0;
    RAM8(0xE007 + x) = 0;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8061, 0xC1CA6C); GUARD_JSR(c, sp_call, 0x8061); } /* clear_actor_movement_charge_and_palette_effects */
    r->sp += 3;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    RAM8(0xE01C + x_ret2) = 0x40;
    RAM8(0xE064 + x_ret2) = 0x80;
    if (x_ret) {
        c->fail = 3;
        return;
    } else {
        uint8_t value5 = RAM8(0x0000 + sp0);
        r->mf = value5 & 0x20;
        r->xf = value5 & 0x10;
        r->i = value5 & 0x04;
        r->d = value5 & 0x08;
        RETURN_RTL(c);
    }
}
SOM_REGISTER(0xC18052, SOM_RTL, "gen", set_actor_motion_and_clear_previous_effects, 0, 0, 3, 1, 0, 29, 14)
