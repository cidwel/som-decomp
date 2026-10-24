#include "som_c.h"

/* C0541B apply_lucid_barrier_absorption   [class A, 28 bytes, 14 instructions]
 * Source: src/rom/apply_lucid_barrier_absorption.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XY.
 */
static void apply_lucid_barrier_absorption(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if ((RAM8(ACTOR_GUARD_FLAGS + x) & 0x10) != 0) {
        RAM16_SET(BATTLE_TEMP_A4, RAM16(0x0390) & 0xFF);
        RAM16_SET(BATTLE_DAMAGE, (uint16_t)(RAM16(BATTLE_DAMAGE) - RAM16(BATTLE_TEMP_A4)));
        RAM16_SET(0x0394, 0);
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0541B, SOM_RTS, "gen", apply_lucid_barrier_absorption, 0, L_X | L_Y, 1, 1, 0, 28, 14)
