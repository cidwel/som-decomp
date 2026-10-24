#include "som_c.h"

/* C03D4D expire_combat_high_status_group_timer   [class A, 18 bytes, 8 instructions]
 * Source: src/rom/expire_combat_high_status_group_timer.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void expire_combat_high_status_group_timer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t x = r->x;
    uint8_t value = RAM8(ACTOR_STATUS_HIGH + x);
    if ((value & 0x18) != 0) {
        RAM8(ACTOR_TIMER_1B5 + x)--;
        if (RAM8(ACTOR_TIMER_1B5 + x) == 0) {
            RAM8(ACTOR_STATUS_HIGH + x) = value & 0xE7;
        }
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC03D4D, SOM_RTS, "gen", expire_combat_high_status_group_timer, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 18, 8)
