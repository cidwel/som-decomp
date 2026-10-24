#include "som_c.h"

/* C2629C restore_boss_palette_and_load_song_four   [class A, 28 bytes, 13 instructions]
 * Source: src/rom/restore_boss_palette_and_load_song_four.s
 * Documented in docs/boss-native-alternate-death.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: BYV.
 */
static void restore_boss_palette_and_load_song_four(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(0x0018 + battle_defence_work);
    r->a = (uint16_t)((uint16_t)(RAM16(0x0042 + battle_defence_work) << 1) + 0x31);
    r->x = value & 0xFF;
    { const uint16_t sp_call = r->sp; JSR(c, 0x62B0, 0xC226F9); GUARD_JSR(c, sp_call, 0x62B0); } /* copy_boss_palette_with_cpu_words */
    r->a = 4;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x62B6, 0xC230C2); GUARD_JSR(c, sp_call, 0x62B6); } /* load_requested_song_with_native_parameter_four */
    r->mf = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2629C, SOM_RTS, "gen", restore_boss_palette_and_load_song_four, 0, L_B | L_Y | L_V, 1, 0, 0, 28, 13)
