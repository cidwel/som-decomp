#include "som_c.h"

/* C8E50F filter_damage_over_time_actor_statuses   [class B, 32 bytes, 13 instructions]
 * Source: src/rom/filter_damage_over_time_actor_statuses.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: XY.
 */
static void filter_damage_over_time_actor_statuses(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(ACTOR_STATUS + x);
    if ((value & 0x4000) == 0) {
        if ((value & 0x2000) != 0) {
            if ((value & 0x1860) != 0) {
                RAM16_SET(ACTOR_STATUS + x, value & 0xDFFF);
            }
        }
        RETURN_RTS(c);
    }
    RAM16_SET(ACTOR_STATUS + x, value & 0xDAFF);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E50F, SOM_RTS, "gen", filter_damage_over_time_actor_statuses, 0, L_X | L_Y, 1, 0, 0, 32, 13)
