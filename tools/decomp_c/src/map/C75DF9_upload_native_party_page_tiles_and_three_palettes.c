#include "som_c.h"

/* C75DF9 upload_native_party_page_tiles_and_three_palettes   [class D, 156 bytes, 59 instructions]
 * Source: src/rom/upload_native_party_page_tiles_and_three_palettes.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void upload_native_party_page_tiles_and_three_palettes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const bool overflow = r->v;
    BUS16_SET(c, 0x002116, 0x4300);
    RAM16_SET(0xA194, 0);
    RAM16_SET(0xA191, 0x0100);
    r->a = 0x43D5;
    r->x = 0x0100;
    r->z = 0;
    r->n = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5E15, 0xC02AEE); GUARD_JSL(c, sp_call, 0x5E15); } /* native_menu_selected_bank_tile_dma_long_wrapper */
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    RAM16_SET(0xA194, 0x8000);
    r->a = (a_all >> 8 << 8) | 0xD5;
    r->x = 0x8000;
    r->z = 0;
    r->n = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5E21, 0xC02AEE); GUARD_JSL(c, sp_call, 0x5E21); } /* native_menu_selected_bank_tile_dma_long_wrapper */
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    RAM16_SET(0xA194, 0);
    r->a = (a_all2 >> 8 << 8) | 0xD6;
    r->x = 0;
    r->z = 0;
    r->n = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5E2D, 0xC02AEE); GUARD_JSL(c, sp_call, 0x5E2D); } /* native_menu_selected_bank_tile_dma_long_wrapper */
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all3 = r->a;
    uint8_t value = RAM8(0xA202);
    uint8_t a_hi2;
    if (value != 7) {
        a_hi2 = a_all3 >> 8;
    } else {
        RAM16_SET(0xA191, 0x0200);
        RAM16_SET(0xA194, 0xFE00);
        r->a = (a_all3 >> 8 << 8) | 0xCC;
        r->x = 0xFE00;
        r->c = value >= 7;
        r->z = 0;
        r->n = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x5E46, 0xC02AEE); GUARD_JSL(c, sp_call, 0x5E46); } /* native_menu_selected_bank_tile_dma_long_wrapper */
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all4 = r->a;
        BUS8_SET(c, 0x002121, 0xC0);
        uint8_t a_hi1 = a_all4 >> 8;
        uint16_t x1 = 0;
        uint16_t y1 = 0x80;
        for (;;) {
            uint8_t value2 = BUS8(c, 0xCCFD80 + x1);
            BUS8_SET(c, 0x002122, value2);
            x1 = (uint16_t)(x1 + 1);
            y1 = (uint16_t)(y1 - 1);
            if (!(y1 != 0)) break;
        }
        a_hi2 = a_hi1;
    }
    RAM8(0xA175) = 3;
    BUS8_SET(c, 0x002121, 0x90);
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = 0xC8;
    uint8_t a1 = 0xC8;
    uint8_t a_hi3 = a_hi2;
    uint16_t x2 = 0x0F00;
    uint16_t y2 = 0;
    bool zero1 = 0;
    for (;;) {
        BUS8_SET(c, 0x002122, a1);
        BUS8_SET(c, 0x002122, a1);
        uint8_t a_hi4 = a_hi3;
        uint16_t x3 = x2;
        uint16_t y3 = 0x1E;
        for (;;) {
            uint8_t value3 = BUS8(c, 0xC81000 + x3);
            BUS8_SET(c, 0x002122, value3);
            x3 = (uint16_t)(x3 + 1);
            y3 = (uint16_t)(y3 - 1);
            if (!(y3 != 0)) break;
        }
        uint8_t value4 = RAM8(0xA175);
        RAM8(0xA175) = (uint8_t)(value4 - 1);
        a1 = (uint8_t)(value4 - 1);
        a_hi3 = a_hi4;
        x2 = x3;
        y2 = y3;
        zero1 = (uint8_t)(value4 - 1) == 0;
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi3 << 8) | a1;
    r->x = x2;
    r->y = y2;
    r->c = value >= 7;
    r->z = 0;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75DF9, SOM_RTS, "gen", upload_native_party_page_tiles_and_three_palettes, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 2, 1, 0, 156, 59)
