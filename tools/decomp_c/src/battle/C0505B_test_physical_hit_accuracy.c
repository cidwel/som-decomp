#include "som_c.h"

/* C0505B test_physical_hit_accuracy   [class B, 111 bytes, hand written]
 * docs/rom-combat.md section 4.2.  X = defender (evasion already prepared by C04FED), Y = attacker.
 * The hit succeeds when  accuracy >= (evade/2) + (random * (evade/2) >> 8)  -- the result is left in the carry flag
 * (C set = hit).  Callers read: B, X, Y, C, V.
 */
static void test_physical_hit_accuracy(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t attacker = r->y;

    uint8_t accuracy = RAM8(ACTOR_ACCURACY + attacker);
    RAM8(BATTLE_ACCURACY_WORK) = accuracy;

    /* ROM quirk: when status bit 2 (accuracy -1/16) is clear, the "quarter" below is taken from the status byte
     * itself, not from the accuracy (docs/rom-combat.md section 4.2). */
    const uint8_t status = RAM8(ACTOR_STATUS + attacker);
    uint8_t quarter_source = status;
    if (status & 0x04) {
        const uint8_t sixteenth = accuracy >> 4;
        RAM8(BATTLE_TEMP_A4) = sixteenth;
        accuracy = (uint8_t)(accuracy - sixteenth);
        RAM8(BATTLE_ACCURACY_WORK) = accuracy;
        quarter_source = accuracy;
    }
    const uint8_t quarter = quarter_source >> 2;
    RAM8(BATTLE_TEMP_A6) = quarter;

    /* attack buff +25% (bit 4) / debuff -25% (bit 5), capped at 99, halved while the weapon gauge is charging */
    const uint8_t buffs = RAM8(ACTOR_BUFF_FLAGS + attacker);
    if (buffs & 0x10)      accuracy = (uint8_t)(accuracy + quarter);
    else if (buffs & 0x20) accuracy = (uint8_t)(accuracy - quarter);
    if (accuracy > 99) accuracy = 99;
    RAM8(BATTLE_ACCURACY_WORK) = accuracy;
    if (RAM8(ACTOR_WEAPON_GAUGE + attacker) != 0) {
        accuracy >>= 1;
        RAM8(BATTLE_ACCURACY_WORK) = accuracy;
    }

    /* threshold = half the evasion + (random byte * half the evasion) / 256, computed by the hardware multiplier */
    JSL(c, 0x50AA, 0xC0389C); /* random_byte_long_wrapper */
    const uint8_t random = (uint8_t)r->a;
    const uint8_t half_evade = RAM8(BATTLE_EVADE_WORK) >> 1;
    BUS8_SET(c, 0x004202, random);
    BUS8_SET(c, 0x004203, half_evade);
    RAM8(BATTLE_TEMP_A4) = half_evade;
    const uint8_t product_high = BUS8(c, 0x004217);
    const uint8_t threshold = (uint8_t)(product_high + half_evade);
    RAM8(BATTLE_TEMP_A4) = threshold;

    r->c = accuracy >= threshold; /* CMP: hit when accuracy >= threshold */
    r->v = ((product_high ^ threshold) & (half_evade ^ threshold) & 0x80) != 0; /* V of the preceding ADC */
    SET_A8(r, accuracy);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0505B, SOM_RTS, "hand", test_physical_hit_accuracy, 0, L_B | L_X | L_Y | L_C | L_V, 16, 1, 0, 111, 58)
