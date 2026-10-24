#include "som_c.h"

/* C0B00D await_survey_nmi_and_clear_complete_vram_page   [class D, 50 bytes, 21 instructions]
 * Source: src/rom/await_survey_nmi_and_clear_complete_vram_page.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: XY.
 */
static void await_survey_nmi_and_clear_complete_vram_page(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(0x000E) = 0x80;
    BUS8_SET(c, 0x002115, 0x80);
    for (;;) {
        if (!((RAM8(0x000E) & 0x80) != 0)) break;
    }
    RAM16_SET(0x0000, 0);
    BUS16_SET(c, 0x002116, 0);
    BUS16_SET(c, 0x004372, 0);
    BUS16_SET(c, 0x004370, 0x1809);
    BUS16_SET(c, 0x004375, 0x1000);
    BUS8_SET(c, 0x004374, 0);
    BUS8_SET(c, 0x00420B, 0x80);
    RAM8(0x000F) = 0xFF;
    r->x = x;
    r->y = y;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0B00D, SOM_RTS, "gen", await_survey_nmi_and_clear_complete_vram_page, 0, L_X | L_Y, 1, 1, 0, 50, 21)
