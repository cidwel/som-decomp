#include "som_c.h"

/* C8E487 filter_low_actor_statuses   [class B, 80 bytes, 32 instructions]
 * Source: src/rom/filter_low_actor_statuses.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void filter_low_actor_statuses(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    uint16_t value = RAM16(ACTOR_STATUS + x);
    if ((value & 0x40) == 0) {
        if ((value & 0x20) == 0) {
            if ((value & 0x10) == 0) {
                if ((value & 8) == 0) {
                    uint8_t a_hi1;
                    if ((value & 4) == 0) {
                        a_hi1 = value >> 8;
                    } else {
                        RAM16_SET(ACTOR_STATUS + x, value & 0xFFFC);
                        a_hi1 = (value & 0xFFFC) >> 8;
                    }
                    r->a = (a_hi1 << 8) | (uint8_t)a;
                    RETURN_RTS(c);
                }
                RAM16_SET(ACTOR_STATUS + x, value & 0xFBF0);
                r->a = value & 0xFBF0;
                RETURN_RTS(c);
            }
            RAM16_SET(ACTOR_STATUS + x, value & 0xFBF0);
            uint16_t value2 = RAM16(ACTOR_GUARD_FLAGS + x);
            RAM16_SET(ACTOR_GUARD_FLAGS + x, value2 | 1);
            r->a = value2 | 1;
            RETURN_RTS(c);
        }
        RAM16_SET(ACTOR_STATUS + x, value & 0x9AE0);
        r->a = value & 0x9AE0;
        RETURN_RTS(c);
    }
    RAM16_SET(ACTOR_STATUS + x, value & 0x9AC0);
    RAM16_SET(ACTOR_HP + x, RAM16(ACTOR_HP + x) >> 1);
    RAM16_SET(ACTOR_HP + x, (uint16_t)(RAM16(ACTOR_HP + x) + 1));
    r->a = value & 0x9AC0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E487, SOM_RTS, "gen", filter_low_actor_statuses, 0, L_B | L_X | L_Y, 1, 0, 0, 80, 32)
