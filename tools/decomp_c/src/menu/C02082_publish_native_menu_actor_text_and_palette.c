#include "som_c.h"

/* C02082 publish_native_menu_actor_text_and_palette   [class D, 37 bytes, 13 instructions]
 * Source: src/rom/publish_native_menu_actor_text_and_palette.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCZV.
 */
static void publish_native_menu_actor_text_and_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM16_SET(0xA191, 0x0120);
    RAM16_SET(0xA18C, 0x61F0);
    r->x = 0x61F0;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x2090, 0xC023BA); GUARD_JSR(c, sp_call, 0x2090); } /* upload_native_menu_assembled_text_tiles */
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    BUS8_SET(c, 0x002121, 0x18);
    RAM16_SET(0xA194, 0xA1A4);
    RAM16_SET(0xA191, 0x10);
    r->a = (a_all >> 8 << 8) | 0x18;
    r->x = 0x10;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x20A5, 0xC025FB); GUARD_JSR(c, sp_call, 0x20A5); } /* select_wram_source_for_native_menu_palette_dma */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC02082, SOM_RTS, "gen", publish_native_menu_actor_text_and_palette, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 37, 13)
