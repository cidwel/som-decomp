#include "som_c.h"

/* C04FED calculate_physical_defence_terms   [class B, 110 bytes, hand written]
 * docs/rom-combat.md section 4.3: evasion and defence of the DEFENDER (X) with the buff/debuff and Pygmized
 * adjustments, before the hit test (C0505B) and the damage subtraction (C052E7) use them.
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300; X = defender record offset.  Exit: working values in the battle
 * scratch (BATTLE_EVADE_WORK <= 99, BATTLE_DEFENCE_WORK <= 999).  Callers read: BXYV.
 */
static void calculate_physical_defence_terms(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t defender = r->x;
    bool overflow = r->v; /* only the ADC/SBC below touch V; CMP and shifts leave it alone */

    /* evasion: +25% with the speed-up buff (bit 2), -25% with the speed-down debuff (bit 3), capped at 99 */
    const uint8_t buffs = RAM8(ACTOR_BUFF_FLAGS + defender);
    uint8_t evade = RAM8(ACTOR_EVADE + defender);
    const uint8_t evade_quarter = evade >> 2;
    RAM8(BATTLE_TEMP_A6) = evade_quarter;
    if (buffs & 0x04) {
        const uint8_t sum = (uint8_t)(evade + evade_quarter);
        overflow = ((evade ^ sum) & (evade_quarter ^ sum) & 0x80) != 0;
        evade = sum;
    } else if (buffs & 0x08) {
        const uint8_t diff = (uint8_t)(evade - evade_quarter);
        overflow = ((evade ^ evade_quarter) & (evade ^ diff) & 0x80) != 0;
        evade = diff;
    }
    RAM8(BATTLE_EVADE_WORK) = evade;
    if (evade > 99) RAM8(BATTLE_EVADE_WORK) = 99;

    /* defence: +25% (bit 0) / -25% (bit 1) of the buff byte, a quarter when Pygmized (status high bit 1), cap 999 */
    uint16_t defence = RAM16(ACTOR_DEFENSE + defender);
    const uint16_t defence_quarter = defence >> 2;
    RAM16_SET(BATTLE_TEMP_AE, defence_quarter);
    if (buffs & 0x01) {
        const uint16_t sum = (uint16_t)(defence + defence_quarter);
        overflow = ((defence ^ sum) & (defence_quarter ^ sum) & 0x8000) != 0;
        defence = sum;
    } else if (buffs & 0x02) {
        const uint16_t diff = (uint16_t)(defence - defence_quarter);
        overflow = ((defence ^ defence_quarter) & (defence ^ diff) & 0x8000) != 0;
        defence = diff;
    }
    RAM16_SET(BATTLE_DEFENCE_WORK, defence);
    if (RAM8(ACTOR_STATUS_HIGH + defender) & 0x02) {
        defence >>= 2;
        RAM16_SET(BATTLE_DEFENCE_WORK, defence);
    }
    if (defence > 999) RAM16_SET(BATTLE_DEFENCE_WORK, 999);
    r->v = overflow;
    r->a = 0x03E7; /* LDA #$03E7 for the cap test */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04FED, SOM_RTS, "hand", calculate_physical_defence_terms, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 110, 56)
