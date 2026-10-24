#include "som_c.h"

/* C234B9 complete_boss_hurt_state_after_timeout_or_released_counter_status   [class B, 31 bytes, 14 instructions]
 * Source: src/rom/complete_boss_hurt_state_after_timeout_or_released_counter_status.s
 * Documented in docs/boss-actor-controller-pool.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XYCV.
 */
static void complete_boss_hurt_state_after_timeout_or_released_counter_status(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if (RAM16(OBJECT_AGE + x) >= 0x3C) {
        r->c = 1;
        RETURN_RTS(c);
    }
    if ((RAM16(0x0175 + x) & 0xFF) != 0) {
        r->c = 0;
        RETURN_RTS(c);
    }
    if ((RAM16(0x0060 + x) & 0xFF) == 0x40) {
        r->c = 0;
        RETURN_RTS(c);
    }
    r->c = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC234B9, SOM_RTS, "gen", complete_boss_hurt_state_after_timeout_or_released_counter_status, 0, L_X | L_Y | L_C | L_V, 1, 0, 0, 31, 14)
