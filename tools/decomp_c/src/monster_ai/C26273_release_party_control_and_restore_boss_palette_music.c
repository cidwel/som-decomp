#include "som_c.h"

/* C26273 release_party_control_and_restore_boss_palette_music   [class A, 31 bytes, 15 instructions]
 * Source: src/rom/release_party_control_and_restore_boss_palette_music.s
 * Documented in docs/boss-native-alternate-death.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: BYV.
 */
static void release_party_control_and_restore_boss_palette_music(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00A9 + x);
    RAM8(0x01B4 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) = 1;
    uint8_t value2 = RAM8(0x000E + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
    RAM8(0x000E + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) = value2 & 0x7F;
    r->a = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) >> 8 << 8 | (value2 & 0x7F);
    { const uint16_t sp_call = r->sp; JSR(c, 0x6290, 0xC2629C); GUARD_JSR(c, sp_call, 0x6290); } /* restore_boss_palette_and_load_song_four */
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26273, SOM_RTS, "gen", release_party_control_and_restore_boss_palette_music, 0, L_B | L_Y | L_V, 1, 0, 0, 31, 15)
