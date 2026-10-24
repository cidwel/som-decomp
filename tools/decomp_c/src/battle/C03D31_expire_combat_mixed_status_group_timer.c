#include "som_c.h"

/* C03D31 expire_combat_mixed_status_group_timer   [class B, 28 bytes, 12 instructions]
 * Source: src/rom/expire_combat_mixed_status_group_timer.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void expire_combat_mixed_status_group_timer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(ACTOR_STATUS + x);
    uint8_t a_hi2;
    if ((value & 0x0180) == 0) {
        a_hi2 = value >> 8;
    } else {
        RAM8(ACTOR_TIMER_1B3 + x)--;
        uint8_t a_hi1;
        if (RAM8(ACTOR_TIMER_1B3 + x) != 0) {
            a_hi1 = value >> 8;
        } else {
            RAM16_SET(ACTOR_STATUS + x, value & 0xFE7F);
            a_hi1 = (value & 0xFE7F) >> 8;
        }
        a_hi2 = a_hi1;
    }
    r->a = (r->a & 0x00FF) | (a_hi2 << 8);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC03D31, SOM_RTS, "gen", expire_combat_mixed_status_group_timer, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 28, 12)
