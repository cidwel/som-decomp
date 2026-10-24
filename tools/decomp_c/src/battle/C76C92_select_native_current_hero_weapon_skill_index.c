#include "som_c.h"

/* C76C92 select_native_current_hero_weapon_skill_index   [class A, 21 bytes, 10 instructions]
 * Source: src/rom/select_native_current_hero_weapon_skill_index.s
 * Documented in docs/ui-native-personality-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYV.
 */
static void select_native_current_hero_weapon_skill_index(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0x19FE);
    RAM8(0xA175) = RAM8(0xE1E4 + (uint16_t)((((value << 8) | a_hi) & 0xFF00) << 1));
    r->a = (r->a & 0x00FF) | (((uint16_t)((((value << 8) | a_hi) & 0xFF00) << 1) >> 8) << 8);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76C92, SOM_RTS, "gen", select_native_current_hero_weapon_skill_index, 0, L_B | L_Y | L_V, 1, 1, 0, 21, 10)
