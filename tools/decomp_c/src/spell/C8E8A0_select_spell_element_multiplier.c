#include "som_c.h"

/* C8E8A0 select_spell_element_multiplier   [class A, 32 bytes, 16 instructions]
 * Source: src/rom/select_spell_element_multiplier.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void select_spell_element_multiplier(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint8_t value = BUS8_RDL(c, (RAM8(0x03DE) << 0x10) + RAM16(0x03DC) + 0x2ADC, RAM8(0x03DE));
    uint16_t battle_attacker_ptr = RAM16(BATTLE_ATTACKER_PTR);
    uint8_t value2 = RAM8(ACTOR_RESIST_ELEMENT + x);
    if ((value & value2) == 0) {
        uint8_t value3 = RAM8(ACTOR_WEAK_ELEMENT + x);
        if ((value & value3) == 0) {
            RAM8(0x038F) = 2;
            r->y = battle_attacker_ptr;
            r->v = value3 & 0x40;
            RETURN_RTS(c);
        }
        RAM8(0x038F) = 4;
        r->y = battle_attacker_ptr;
        r->v = value3 & 0x40;
        RETURN_RTS(c);
    }
    RAM8(0x038F) = 1;
    r->y = battle_attacker_ptr;
    r->v = value2 & 0x40;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC8E8A0, SOM_RTS, "gen", select_spell_element_multiplier, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 32, 16)
