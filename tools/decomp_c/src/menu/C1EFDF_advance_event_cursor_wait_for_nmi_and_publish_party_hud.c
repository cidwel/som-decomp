#include "som_c.h"

/* C1EFDF advance_event_cursor_wait_for_nmi_and_publish_party_hud   [class A, 8 bytes, 4 instructions]
 * Source: src/rom/advance_event_cursor_wait_for_nmi_and_publish_party_hud.s
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void advance_event_cursor_wait_for_nmi_and_publish_party_hud(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0x00D1, (uint16_t)(RAM16(0x00D1) + 1));
    uint16_t value = RAM16(0x00D1);
    r->z = value == 0;
    r->n = value & 0x8000;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEFE5, 0xC1E326); GUARD_JSR(c, sp_call, 0xEFE5); } /* wait_for_native_nmi_and_refresh_party_hud_numbers */
    r->mf = 1;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1EFDF, SOM_RTS, "gen", advance_event_cursor_wait_for_nmi_and_publish_party_hud, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 1, 8, 4)
