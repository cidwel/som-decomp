#include "som_c.h"

/* C25906 prepare_boss_spell_if_enabled_otherwise_unwind_caller   [class C, 26 bytes, 13 instructions]
 * Source: src/rom/prepare_boss_spell_if_enabled_otherwise_unwind_caller.s
 * Documented in docs/boss-native-attack-selection.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void prepare_boss_spell_if_enabled_otherwise_unwind_caller(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp + 2;
    const uint16_t a = r->a;
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x0200, a);
    if (RAM8(0x0186 + value) == 0) {
        r->a = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
        r->x = value;
        r->sp += 2;
        RETURN_RTS(c);
    }
    r->a = RAM16(0x0200);
    r->x = value;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5917, 0xC2396D); GUARD_JSR(c, sp_call, 0x5917); } /* prepare_boss_spell_targets */
    uint16_t value6 = RAM16(0x0287);
    RAM16_SET(0x0360, value6);
    r->a = value6;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25906, SOM_RTS, "gen", prepare_boss_spell_if_enabled_otherwise_unwind_caller, SOM_UNWINDS, L_B | L_X | L_Y | L_C | L_V, 2, 0, 0, 26, 13)
