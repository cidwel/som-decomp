#include "som_c.h"

/* C2993D follow_spell_target_integer_position   [class A, 16 bytes, 6 instructions]
 * Source: src/rom/follow_spell_target_integer_position.s
 * Documented in docs/boss-native-spell-follow-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXV.
 */
static void follow_spell_target_integer_position(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00B2 + x);
    RAM16_SET(0x002B + x, RAM16(0x0002 + value));
    uint16_t value3 = RAM16(0x0004 + value);
    RAM16_SET(0x0032 + x, value3);
    r->a = value3;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2993D, SOM_RTS, "gen", follow_spell_target_integer_position, 0, L_B | L_X | L_V, 1, 0, 0, 16, 6)
