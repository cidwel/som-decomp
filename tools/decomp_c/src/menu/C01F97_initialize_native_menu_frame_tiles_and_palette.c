#include "som_c.h"

/* C01F97 initialize_native_menu_frame_tiles_and_palette   [class D, 121 bytes, 49 instructions]
 * Source: src/rom/initialize_native_menu_frame_tiles_and_palette.s
 * Documented in docs/event-menu-constructor.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void initialize_native_menu_frame_tiles_and_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const bool carry = r->c;
    const bool overflow = r->v;
    BUS16_SET(c, 0x002116, 0x4000);
    RAM16_SET(0xA191, 0x0400);
    RAM16_SET(0xA194, 0xFC00);
    JSR(c, 0x1FB0, 0xC025C8); /* select_rom_source_for_native_menu_tile_dma */
    BUS8_SET(c, 0x002121, 0x20);
    RAM16_SET(0xA194, 0xFBE0);
    RAM16_SET(0xA191, 0x20);
    r->x = 0x20;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x1FC5, 0xC025F7); /* select_rom_source_for_native_menu_palette_dma */
    uint16_t a_all2 = r->a;
    RAM8(0xA176) = 8;
    uint8_t a_hi1 = a_all2 >> 8;
    uint16_t x1 = 0x20;
    uint16_t y1 = 0;
    bool carry1 = carry;
    bool overflow1 = overflow;
    do {
        RAM8(0xA171) = 8;
        uint8_t a_hi2 = a_hi1;
        uint16_t x2 = x1;
        uint16_t y2 = y1;
        do {
            r->a = (a_hi2 << 8) | a;
            r->y = y2;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = 0;
            r->sp -= 2;
            JSR(c, 0x1FD6, 0xC0205A); /* copy_four_native_menu_frame_tile_chunks */
            r->sp += 2;
            uint16_t x_ret = r->x;
            RAM8(0xA171)--;
            uint8_t a_hi2_next = (uint16_t)(y2 + 8) >> 8;
            uint16_t x2_next = x_ret;
            uint16_t y2_next = (uint16_t)(y2 + 8);
            a_hi2 = a_hi2_next;
            x2 = x2_next;
            y2 = y2_next;
        } while (RAM8(0xA171) != 0);
        RAM8(0xA176)--;
        a_hi1 = (uint16_t)(y2 + 0xC0) >> 8;
        x1 = x2;
        y1 = (uint16_t)(y2 + 0xC0);
        carry1 = y2 + 0xC0 > 0xFFFF;
        overflow1 = ((y2 ^ (uint16_t)(y2 + 0xC0)) & ((uint16_t)(y2 + 0xC0) ^ 0xC0) & 0x8000) != 0;
    } while (RAM8(0xA176) != 0);
    BUS16_SET(c, 0x002116, 0x4800);
    RAM16_SET(0xA191, 0x0800);
    RAM16_SET(0xA194, 0x9000);
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    JSR(c, 0x200E, 0xC025CC); /* select_wram_source_for_native_menu_tile_dma */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01F97, SOM_RTS, "gen", initialize_native_menu_frame_tiles_and_palette, 0, L_B | L_Y | L_C | L_V, 2, 1, 0, 121, 49)
