#include "som_c.h"

/* C04315 clear_six_actor_references_to_dead_actor   [class B, 67 bytes, 30 instructions]
 * Source: src/rom/clear_six_actor_references_to_dead_actor.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void clear_six_actor_references_to_dead_actor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(BATTLE_TEMP_A6) = 0;
    RAM8(0x03A7) = 0;
    RAM8(0x03B2) = 6;
    uint8_t a_hi1 = a_hi;
    uint16_t y1 = y;
    bool carry1 = carry;
    do {
        uint16_t battle_temp_a6 = RAM16(BATTLE_TEMP_A6);
        if (RAM8(0x0381) == RAM8(0xE1AC + battle_temp_a6)) {
            RAM8(0xE1AC + battle_temp_a6) = 0xFF;
        }
        if (RAM8(0x0381) == RAM8(0xE1AD + battle_temp_a6)) {
            RAM8(0xE1AD + battle_temp_a6) = 0xFF;
        }
        if (RAM8(0x0381) == RAM8(0xE1EC + battle_temp_a6)) {
            RAM8(0xE1EC + battle_temp_a6) = 0x0F;
        }
        uint8_t value7 = RAM8(0x0381);
        uint8_t value8 = RAM8(0xE1F0 + battle_temp_a6);
        if (value7 == value8) {
            RAM8(0xE1EC + battle_temp_a6) = 0xFF;
        }
        RAM8(0x03A7)++;
        RAM8(0x03A7)++;
        RAM8(0x03B2)--;
        y1 = battle_temp_a6;
        carry1 = value7 >= value8;
    } while (RAM8(0x03B2) != 0);
    r->a = (a_hi1 << 8) | a;
    r->x = x;
    r->y = y1;
    r->c = carry1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04315, SOM_RTS, "gen", clear_six_actor_references_to_dead_actor, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 67, 30)
