#include "som_c.h"

/* C038A0 advance_additive_random_generator   [class C, 46 bytes, 25 instructions]
 * Source: src/rom/advance_additive_random_generator.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCV.
 */
static void advance_additive_random_generator(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint8_t value = RAM8(0x03F0);
    RAM8(BATTLE_MUL_WORK) = RAM8(0x03F1 + value);
    uint8_t x1;
    if (!((uint8_t)(value - 1) & 0x80)) {
        x1 = (uint8_t)(value - 1);
    } else {
        x1 = 0x0E;
    }
    uint8_t value3 = RAM8(0x03F1 + x1);
    uint8_t battle_mul_work = RAM8(BATTLE_MUL_WORK);
    RAM8(0x03F1 + x1) = (uint8_t)(value3 + battle_mul_work);
    RAM8(0x03F0)++;
    if (RAM8(0x03F0) == 0x0F) {
        RAM8(0x03F0) = 0;
    }
    r->a = (0x0F << 8) | (uint8_t)(value3 + battle_mul_work);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC038A0, SOM_RTS, "gen", advance_additive_random_generator, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 5, 1, 0, 46, 25)
