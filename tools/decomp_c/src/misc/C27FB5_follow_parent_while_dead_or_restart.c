#include "som_c.h"

/* C27FB5 follow_parent_while_dead_or_restart   [class B, 48 bytes, 21 instructions]
 * Source: src/rom/follow_parent_while_dead_or_restart.s
 * Documented in docs/boss-native58-left-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void follow_parent_while_dead_or_restart(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(0x00B0 + battle_defence_work);
    RAM16_SET(0x002B + battle_defence_work, (uint16_t)(RAM16(0x002B + value) - 0x40));
    uint16_t value3 = RAM16(0x0032 + value);
    RAM16_SET(0x0032 + battle_defence_work, (uint16_t)(value3 + 0x10));
    uint16_t value4 = RAM16(OBJECT_PHASE + value);
    if (value4 == 6) {
        r->a = value4;
        r->x = battle_defence_work;
        r->y = value;
        r->c = 1;
        r->z = value4 == 6;
        r->n = (uint16_t)(value4 - 6) & 0x8000;
        r->v = ((value3 ^ (uint16_t)(value3 + 0x10)) & ((uint16_t)(value3 + 0x10) ^ 0x10) & 0x8000) != 0;
        RETURN_RTS(c);
    }
    uint16_t value5 = RAM16(0x0190 + battle_defence_work);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value5 & 0x8000) {
        a1 = (uint8_t)value5;
        a_hi1 = value5 >> 8;
        zero1 = value5 == 0;
        negative1 = value5 & 0x8000;
    } else {
        RAM16_SET(OBJECT_PHASE + battle_defence_work, 1);
        a1 = 1;
        a_hi1 = 0;
        zero1 = 0;
        negative1 = 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = battle_defence_work;
    r->y = value;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = ((value3 ^ (uint16_t)(value3 + 0x10)) & ((uint16_t)(value3 + 0x10) ^ 0x10) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27FB5, SOM_RTS, "gen", follow_parent_while_dead_or_restart, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 48, 21)
