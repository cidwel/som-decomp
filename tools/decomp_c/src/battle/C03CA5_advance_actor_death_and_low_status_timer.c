#include "som_c.h"

/* C03CA5 advance_actor_death_and_low_status_timer   [class B, 119 bytes, 49 instructions]
 * Source: src/rom/advance_actor_death_and_low_status_timer.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void advance_actor_death_and_low_status_timer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if ((RAM8(ACTOR_STATUS + x) & 3) == 0) {
        if (!(RAM8(ACTOR_KIND_FLAGS + x) & 0x80)) {
            if (RAM8(ACTOR_STATUS_HIGH + x) & 0x80) {
                RETURN_RTS(c);
            }
            uint16_t value4 = RAM16(ACTOR_HP + x);
            if (value4 != 0) {
                r->y = value4;
                RETURN_RTS(c);
            }
            RAM8(ACTOR_STATUS_HIGH + x) = 0x80;
            RAM8(0xE1FA + x) |= 2;
            RAM16_SET(0xE1EE + x, 0);
            RAM16_SET(0xE19E + x, 0);
            uint16_t value6 = RAM16(ACTOR_STATUS + x);
            RAM16_SET(ACTOR_STATUS + x, value6 & 0x8003);
            r->a = value6 & 0x8003;
            r->y = value4;
            r->mf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x3D1A, 0xC04203); GUARD_JSR(c, sp_call, 0x3D1A); } /* process_actor_death_rewards_and_drop_conversion */
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        if (RAM8(ACTOR_STATUS_HIGH + x) & 0x80) {
            RETURN_RTS(c);
        }
        uint16_t value8 = RAM16(ACTOR_HP + x);
        if (value8 == 0) {
            RAM8(0xE1E5 + x) = 0x2F;
            RAM8(0x0380) |= 0x40;
            RAM8(ACTOR_STATUS_HIGH + x) = 0x80;
            r->y = value8;
            RETURN_RTS(c);
        }
        r->y = value8;
        RETURN_RTS(c);
    }
    RAM8(ACTOR_DEATH_TIMER + x)--;
    if (RAM8(ACTOR_DEATH_TIMER + x) != 0) {
        RETURN_RTS(c);
    }
    if (RAM8(0xE175 + x) == 0) {
        RAM8(ACTOR_STATUS + x) &= 0xFC;
        uint16_t value12 = RAM16(ACTOR_HP + x);
        if (value12 == 0) {
            if (RAM8(ACTOR_KIND_FLAGS + x) & 0x80) {
                RAM8(0xE1E5 + x) = 0x2F;
                RAM8(0x0380) |= 0x40;
            }
            RAM8(ACTOR_STATUS_HIGH + x) = 0x80;
        }
        r->y = value12;
        RETURN_RTS(c);
    }
    RAM8(ACTOR_DEATH_TIMER + x)++;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC03CA5, SOM_RTS, "gen", advance_actor_death_and_low_status_timer, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 119, 49)
