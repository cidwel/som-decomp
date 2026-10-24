#include "som_c.h"

/* C1E104 initialize_party_hud   [class B, 15 bytes, 5 instructions]
 * Source: src/rom/initialize_party_hud.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void initialize_party_hud(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xE106, 0xC1E2FE); GUARD_JSR(c, sp_call, 0xE106); } /* reset_party_hud_workspace */
    r->mf = true;
    r->xf = true;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE109, 0xC1E2E5); GUARD_JSR(c, sp_call, 0xE109); } /* clear_party_hud_tilemap */
    r->mf = false;
    r->xf = false;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE10C, 0xC1E113); GUARD_JSR(c, sp_call, 0xE10C); } /* place_party_hud_frames */
    r->mf = true;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE10F, 0xC1E339); GUARD_JSR(c, sp_call, 0xE10F); } /* write_party_hud_numbers */
    r->mf = true;
    TAIL_CALL(c, 0xC1E6B6, SOM_RTS); /* upload_map_party_icons */
}
SOM_REGISTER(0xC1E104, SOM_RTS, "hand", initialize_party_hud, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 15, 5)
