#include "som_c.h"

/* C2CFE0 wait_and_toggle_two_map_overlay_vram_regions   [class D, 119 bytes, 46 instructions]
 * Source: src/rom/wait_and_toggle_two_map_overlay_vram_regions.s
 * Documented in docs/ui-native-map-overlay-wait.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void wait_and_toggle_two_map_overlay_vram_regions(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    r->a = (a << 8) | a_hi;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCFE3, 0xC2CFD5); GUARD_JSR(c, sp_call, 0xCFE3); } /* await_map_nmi_frame_request_two */
    uint16_t a_all = r->a;
    BUS8_SET(c, 0x002115, 0x80);
    BUS16_SET(c, 0x004370, 0x1801);
    if (a_all >> 8 & 0x01) {
        BUS16_SET(c, 0x002116, 0x40B8);
        BUS16_SET(c, 0x004372, 0xD057);
        BUS8_SET(c, 0x004374, 2);
        BUS16_SET(c, 0x004375, 0x10);
        BUS8_SET(c, 0x00420B, 0x80);
        BUS16_SET(c, 0x002116, 0x4140);
        BUS16_SET(c, 0x004375, 0x10);
        BUS8_SET(c, 0x00420B, 0x80);
        r->a = (r->a & 0x00FF) | (0x80 << 8);
        r->y = 0x10;
        r->c = a_all >> 8 & 0x01;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    BUS16_SET(c, 0x002116, 0x40B8);
    BUS16_SET(c, 0x004372, 0x7FF0);
    BUS8_SET(c, 0x004374, 0xD2);
    BUS16_SET(c, 0x004375, 0x10);
    BUS8_SET(c, 0x00420B, 0x80);
    BUS16_SET(c, 0x002116, 0x4140);
    BUS16_SET(c, 0x004372, 0x8100);
    BUS16_SET(c, 0x004375, 0x10);
    BUS8_SET(c, 0x00420B, 0x80);
    r->a = (r->a & 0x00FF) | (0x80 << 8);
    r->y = 0x10;
    r->c = a_all >> 8 & 0x01;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2CFE0, SOM_RTS, "gen", wait_and_toggle_two_map_overlay_vram_regions, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 119, 46)
