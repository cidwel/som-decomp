#include "som_c.h"

/* C05BA4 enqueue_lunar_magic_effect_notice   [class A, 18 bytes, 9 instructions]
 * Source: src/rom/enqueue_lunar_magic_effect_notice.s
 * Documented in docs/actor-cast-spell-remaining.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BYV.
 */
static void enqueue_lunar_magic_effect_notice(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    uint16_t value = BUS16(c, 0xC05E59 + ((a_hi << 8) | (uint8_t)(a << 1)));
    r->x = value;
    r->c = a & 0x80;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5BB1, 0xC05D08); GUARD_JSR(c, sp_call, 0x5BB1); } /* allocate_reverse_combat_message_slot */
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5BB4, 0xC05C2A); GUARD_JSR(c, sp_call, 0x5BB4); } /* append_rom_message_text */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC05BA4, SOM_RTL, "gen", enqueue_lunar_magic_effect_notice, 0, L_B | L_Y | L_V, 1, 1, 0, 18, 9)
