#include "som_c.h"

/* C29CCE mark_single_or_three_spell_targets_control19   [class B, 44 bytes, 17 instructions]
 * Source: src/rom/mark_single_or_three_spell_targets_control19.s
 * Documented in docs/boss-native-spell-status-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void mark_single_or_three_spell_targets_control19(SomCtx *c)
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
        JSR(c, 0x9CE2, 0xC298F6); /* mark_eligible_spell_target_control19 */
        uint16_t value2 = RAM16(0x0287);
        RAM16_SET(0x00B2 + value2, 0xE200);
        r->a = 0xE200;
        r->x = value2;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x9CED, 0xC298F6); /* mark_eligible_spell_target_control19 */
        uint16_t value3 = RAM16(0x0287);
        RAM16_SET(0x00B2 + value3, 0xE400);
        r->a = 0xE400;
        r->x = value3;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x9CF8, 0xC298F6); /* mark_eligible_spell_target_control19 */
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = value;
    JSR(c, 0x9CD8, 0xC298F6); /* mark_eligible_spell_target_control19 */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29CCE, SOM_RTS, "gen", mark_single_or_three_spell_targets_control19, 0, 0, 1, 0, 0, 44, 17)
