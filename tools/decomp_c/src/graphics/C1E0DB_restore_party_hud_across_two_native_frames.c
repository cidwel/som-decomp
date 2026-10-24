#include "som_c.h"

/* C1E0DB restore_party_hud_across_two_native_frames   [class B, 30 bytes, 14 instructions]
 * Source: src/rom/restore_party_hud_across_two_native_frames.s
 * Documented in docs/event-party-hud-restore.md
 * Entry: M=8 bit X=any DB=$7E D=$0000.  Callers read: ABXYCZNV.
 */
static void restore_party_hud_across_two_native_frames(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xE0DD, 0xC1E2FE); GUARD_JSR(c, sp_call, 0xE0DD); } /* reset_party_hud_workspace */
    uint16_t a_all = r->a;
    r->a = (a_all >> 8 << 8) | 0;
    r->mf = 1;
    r->xf = 1;
    r->db = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE0E7, 0xC1E0F9); GUARD_JSR(c, sp_call, 0xE0E7); } /* request_frame_upload_and_wait_for_native_nmi */
    r->sp += 1;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE0EA, 0xC1E2E5); GUARD_JSR(c, sp_call, 0xE0EA); } /* clear_party_hud_tilemap */
    r->sp += 1;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE0ED, 0xC1E113); GUARD_JSR(c, sp_call, 0xE0ED); } /* place_party_hud_frames */
    r->sp += 1;
    r->mf = 1;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE0F0, 0xC1E0F9); GUARD_JSR(c, sp_call, 0xE0F0); } /* request_frame_upload_and_wait_for_native_nmi */
    r->sp += 1;
    r->mf = 1;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE0F3, 0xC1E339); GUARD_JSR(c, sp_call, 0xE0F3); } /* write_party_hud_numbers */
    r->sp += 1;
    r->mf = 1;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xE0F6, 0xC1E6B6); GUARD_JSR(c, sp_call, 0xE0F6); } /* upload_map_party_icons */
    r->sp += 1;
    r->z = 0;
    r->n = 0;
    r->db = 0x7E;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E0DB, SOM_RTS, "gen", restore_party_hud_across_two_native_frames, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, -1, 30, 14)
