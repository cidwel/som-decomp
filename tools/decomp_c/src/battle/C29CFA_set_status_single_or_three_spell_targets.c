#include "som_c.h"

/* C29CFA set_status_single_or_three_spell_targets   [class B, 44 bytes, 17 instructions]
 * Source: src/rom/set_status_single_or_three_spell_targets.s
 * Documented in docs/boss-native-spell-status-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BX.
 */
static void set_status_single_or_three_spell_targets(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B8 + x);
    if ((value & 4) != 0) {
        RAM16_SET(0x00B2 + x, 0xE000);
        r->a = 0xE000;
        JSR(c, 0x9D0E, 0xC29910); /* set_eligible_spell_target_status_and_timer */
        uint16_t value2 = RAM16(0x0287);
        RAM16_SET(0x00B2 + value2, 0xE200);
        r->a = 0xE200;
        r->x = value2;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x9D19, 0xC29910); /* set_eligible_spell_target_status_and_timer */
        uint16_t value3 = RAM16(0x0287);
        RAM16_SET(0x00B2 + value3, 0xE400);
        r->a = 0xE400;
        r->x = value3;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x9D24, 0xC29910); /* set_eligible_spell_target_status_and_timer */
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = value;
    JSR(c, 0x9D04, 0xC29910); /* set_eligible_spell_target_status_and_timer */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29CFA, SOM_RTS, "gen", set_status_single_or_three_spell_targets, 0, L_B | L_X, 1, 0, 0, 44, 17)
