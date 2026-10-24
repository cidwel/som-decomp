#include "som_c.h"

/* C03D1C expire_combat_low_status_group_timer   [class A, 21 bytes, 9 instructions]
 * Source: src/rom/expire_combat_low_status_group_timer.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void expire_combat_low_status_group_timer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if ((RAM8(ACTOR_STATUS + x) & 0x7E) != 0) {
        RAM8(ACTOR_LOW_STATUS_TIMER + x)--;
        if (RAM8(ACTOR_LOW_STATUS_TIMER + x) == 0) {
            RAM8(ACTOR_STATUS + x) &= 0x83;
        }
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC03D1C, SOM_RTS, "gen", expire_combat_low_status_group_timer, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 21, 9)
