#include "som_c.h"

/* C26F2E request_boss_palette_44_and_expand_resource_25   [class B, 58 bytes, 22 instructions]
 * Source: src/rom/request_boss_palette_44_and_expand_resource_25.s
 * Documented in docs/boss-native-screen-requests.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void request_boss_palette_44_and_expand_resource_25(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    r->a = 0x44;
    r->x = 0x0D;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F36, 0xC226F9); GUARD_JSR(c, sp_call, 0x6F36); } /* copy_boss_palette_with_cpu_words */
    RAM8(0x033F + 6) = 0x44;
    RAM8(0x033F + 7) = 0x44;
    r->a = 0x36;
    r->x = 0x44;
    r->y = 6;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F54, 0xC2272D); GUARD_JSR(c, sp_call, 0x6F54); } /* allocate_boss_palette_transition_object */
    r->a = 0x36;
    r->x = 0x3F;
    r->y = 7;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F60, 0xC2272D); GUARD_JSR(c, sp_call, 0x6F60); } /* allocate_boss_palette_transition_object */
    r->a = 0x25;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6F66, 0xC224C3); GUARD_JSR(c, sp_call, 0x6F66); } /* prepare_boss_loader_resource_expansion */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26F2E, SOM_RTS, "gen", request_boss_palette_44_and_expand_resource_25, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 58, 22)
