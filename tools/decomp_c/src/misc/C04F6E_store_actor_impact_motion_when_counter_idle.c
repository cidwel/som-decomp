#include "som_c.h"

/* C04F6E store_actor_impact_motion_when_counter_idle   [class A, 13 bytes, 8 instructions]
 * Source: src/rom/store_actor_impact_motion_when_counter_idle.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void store_actor_impact_motion_when_counter_idle(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    if (RAM8(0xE175 + x) == 0) {
        RAM8(0xE1E5 + x) = a;
        RETURN_RTS(c);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04F6E, SOM_RTS, "gen", store_actor_impact_motion_when_counter_idle, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 13, 8)
