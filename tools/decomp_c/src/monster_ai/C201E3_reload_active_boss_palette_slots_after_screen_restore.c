#include "som_c.h"

/* C201E3 reload_active_boss_palette_slots_after_screen_restore   [class B, 22 bytes, 11 instructions]
 * Source: src/rom/reload_active_boss_palette_slots_after_screen_restore.s
 * Documented in docs/event-boss-screen-restore.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: XY.
 */
static void reload_active_boss_palette_slots_after_screen_restore(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x02C5);
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = value;
    uint16_t y1 = y;
    for (;;) {
        uint16_t value2 = RAM16(0x033F + x1);
        uint8_t a_hi2;
        uint16_t y2;
        if ((value2 & 0xFF) == 0) {
            a_hi2 = 0;
            y2 = y1;
        } else {
            r->a = value2 & 0xFF;
            r->x = x1;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0x0200;
            r->sp -= 2;
            JSR(c, 0x01F0, 0xC226AC); /* load_boss_palette_through_wram_dma */
            r->sp += 2;
            uint16_t a_all = r->a;
            uint16_t y_ret = r->y;
            a_hi2 = a_all >> 8;
            y2 = y_ret;
        }
        a_hi1 = a_hi2;
        x1 = (uint16_t)(x1 + 1);
        y1 = y2;
        if (!(x1 != 0x10)) break;
    }
    r->x = x1;
    r->y = y1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC201E3, SOM_RTS, "gen", reload_active_boss_palette_slots_after_screen_restore, 0, L_X | L_Y, 2, 0, 0, 22, 11)
