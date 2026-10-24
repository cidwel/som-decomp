#include "som_c.h"

/* C2CFB8 temporarily_publish_map_overlay_for_sixty_four_frames   [class B, 29 bytes, 17 instructions]
 * Source: src/rom/temporarily_publish_map_overlay_for_sixty_four_frames.s
 * Documented in docs/ui-native-map-overlay-wait.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void temporarily_publish_map_overlay_for_sixty_four_frames(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    r->a = (a_hi << 8) | 1;
    r->db = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCFC3, 0xC2CFE0); GUARD_JSR(c, sp_call, 0xCFC3); } /* wait_and_toggle_two_map_overlay_vram_regions */
    r->sp += 1;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    uint8_t a1 = 0x40;
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = x;
    uint16_t y1 = y_ret;
    bool carry1 = carry_ret;
    bool overflow1 = overflow_ret;
    for (;;) {
        r->a = (a1 << 8) | a_hi1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0;
        r->dp = dp;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCFC9, 0xC2CFD5); GUARD_JSR(c, sp_call, 0xCFC9); } /* await_map_nmi_frame_request_two */
        r->sp += 1;
        uint16_t a_all2 = r->a;
        bool overflow_ret2 = r->v;
        a1 = (uint8_t)((a_all2 >> 8) - 1);
        a_hi1 = (uint8_t)a_all2;
        overflow1 = overflow_ret2;
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | 0;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0;
    r->dp = dp;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCFD2, 0xC2CFE0); GUARD_JSR(c, sp_call, 0xCFD2); } /* wait_and_toggle_two_map_overlay_vram_regions */
    r->sp += 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2CFB8, SOM_RTL, "gen", temporarily_publish_map_overlay_for_sixty_four_frames, 0, L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 29, 17)
