#include "som_c.h"
/* SOM_POLL_HOOK */

/* C0ADE3 switch_world_map_survey_visible_vram_page_and_scroll   [class D, 82 bytes, 37 instructions]
 * Source: src/rom/switch_world_map_survey_visible_vram_page_and_scroll.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void switch_world_map_survey_visible_vram_page_and_scroll(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint64_t loop_guard = 0;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    RAM8(0x0015) = 1;
    BUS16_SET(c, 0x004372, 0x2000);
    BUS16_SET(c, 0x004370, 0x1801);
    BUS16_SET(c, 0x004375, 0x1000);
    BUS8_SET(c, 0x004374, 0x7F);
    RAM8(0x000E) = 0x80;
    bool overflow1 = overflow;
    for (;;) {
        LOOP_GUARD(loop_guard);
        uint8_t value = RAM8(0x000E);
        overflow1 = value & 0x40;
        if (!((value & 0x80) != 0)) break;
    }
    BUS8_SET(c, 0x002115, 0x80);
    BUS8_SET(c, 0x002116, 0);
    BUS8_SET(c, 0x002117, 0);
    BUS8_SET(c, 0x00420B, 0x80);
    uint8_t value2 = RAM8(0x0015);
    BUS8_SET(c, 0x00210E, (uint8_t)(value2 << 5));
    BUS8_SET(c, 0x00210E, 0);
    r->a = (0x10 << 8) | (uint8_t)(value2 << 5);
    r->x = x;
    r->y = y;
    r->c = (uint8_t)(value2 << 4) & 0x80;
    r->v = overflow1;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0ADE3, SOM_RTS, "gen", switch_world_map_survey_visible_vram_page_and_scroll, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 82, 37)
