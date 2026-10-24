#include "som_c.h"

/* C8E4D7 filter_transformation_actor_statuses   [class B, 56 bytes, 23 instructions]
 * Source: src/rom/filter_transformation_actor_statuses.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: BXY.
 */
static void filter_transformation_actor_statuses(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    uint16_t value = RAM16(ACTOR_STATUS + x);
    if ((value & 0x1000) == 0) {
        if ((value & 0x0800) == 0) {
            uint8_t a_hi2;
            if ((value & 0x0400) == 0) {
                a_hi2 = value >> 8;
            } else {
                uint8_t a_hi1;
                if ((value & 0x617B) == 0) {
                    a_hi1 = value >> 8;
                } else {
                    RAM16_SET(ACTOR_STATUS + x, value & 0xFBFF);
                    a_hi1 = (value & 0xFBFF) >> 8;
                }
                a_hi2 = a_hi1;
            }
            r->a = (a_hi2 << 8) | (uint8_t)a;
            RETURN_RTS(c);
        }
        if ((value & 0x0260) != 0) {
            RAM16_SET(ACTOR_STATUS + x, value & 0xF7FF);
            r->a = value & 0xF7FF;
            RETURN_RTS(c);
        }
        RAM16_SET(ACTOR_STATUS + x, value & 0x9A13);
        r->a = value & 0x9A13;
        RETURN_RTS(c);
    }
    RAM16_SET(ACTOR_STATUS + x, value & 0x92FF);
    r->a = value & 0x92FF;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E4D7, SOM_RTS, "gen", filter_transformation_actor_statuses, 0, L_B | L_X | L_Y, 1, 0, 0, 56, 23)
