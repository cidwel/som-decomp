#include "som_c.h"

/* C250C8 initialize_native54_effect_palette_ids_from_variant   [class A, 38 bytes, 19 instructions]
 * Source: src/rom/initialize_native54_effect_palette_ids_from_variant.s
 * Documented in docs/boss-native54-projectiles.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void initialize_native54_effect_palette_ids_from_variant(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    RAM16_SET(OBJECT_PHASE + battle_defence_work, (uint16_t)(RAM16(OBJECT_PHASE + battle_defence_work) + 1));
    uint16_t value = RAM16(0x0042 + battle_defence_work);
    RAM16_SET(0x00B0 + battle_defence_work, (uint16_t)((uint16_t)((uint16_t)(value << 2) + value) + 0x22));
    uint16_t value2 = RAM16(0x0042 + battle_defence_work);
    RAM16_SET(0x00B2 + battle_defence_work, (uint16_t)((uint16_t)((uint16_t)(value2 << 2) + value2) + 0x20 + ((uint16_t)(value2 << 2) + value2 > 0xFFFF)));
    r->a = (uint16_t)((uint16_t)((uint16_t)(value2 << 2) + value2) + 0x20 + ((uint16_t)(value2 << 2) + value2 > 0xFFFF));
    r->x = battle_defence_work;
    r->c = 0;
    r->z = (uint16_t)((uint16_t)((uint16_t)(value2 << 2) + value2) + 0x20 + ((uint16_t)(value2 << 2) + value2 > 0xFFFF)) == 0;
    r->n = (uint16_t)((uint16_t)((uint16_t)(value2 << 2) + value2) + 0x20 + ((uint16_t)(value2 << 2) + value2 > 0xFFFF)) & 0x8000;
    r->v = (((uint16_t)((uint16_t)(value2 << 2) + value2) ^ (uint16_t)((uint16_t)((uint16_t)(value2 << 2) + value2) + 0x20 + ((uint16_t)(value2 << 2) + value2 > 0xFFFF))) & ((uint16_t)((uint16_t)((uint16_t)(value2 << 2) + value2) + 0x20 + ((uint16_t)(value2 << 2) + value2 > 0xFFFF)) ^ 0x20) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC250C8, SOM_RTS, "gen", initialize_native54_effect_palette_ids_from_variant, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 38, 19)
