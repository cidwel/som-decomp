#include "som_c.h"

/* C194EA clear_actor_motion_and_graphic_state_before_refresh   [class A, 35 bytes, 13 instructions]
 * Source: src/rom/clear_actor_motion_and_graphic_state_before_refresh.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void clear_actor_motion_and_graphic_state_before_refresh(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x94EC, 0xC1CA6C); /* clear_actor_movement_charge_and_palette_effects */
    uint16_t x_ret = r->x;
    uint8_t value = RAM8(0xE060 + x_ret);
    RAM8(0xE01C + x_ret) = 0;
    RAM8(0xE011 + x_ret) = 0;
    RAM8(0xE084 + x_ret) = 0;
    RAM8(0xE060 + x_ret) = 0;
    RAM8(0xE061 + x_ret) = 0;
    RAM8(0xE064 + x_ret) = 0;
    RAM8(0xE062 + x_ret) = 0;
    RAM8(0xE00A + x_ret) = 0;
    SET_A8(r, value);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC194EA, SOM_RTS, "gen", clear_actor_motion_and_graphic_state_before_refresh, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 35, 13)
