#include "som_c.h"

/* C098E4 prepare_upper_or_lower_scene_tile_row_for_publication   [class B, 88 bytes, 50 instructions]
 * Source: src/rom/prepare_upper_or_lower_scene_tile_row_for_publication.s
 * Entry: M=any X=any DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void prepare_upper_or_lower_scene_tile_row_for_publication(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0x002E);
    if (value != 0) {
        if (value & 0x80) {
            r->x = value;
            r->y = (uint8_t)y;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        }
        uint8_t a1;
        uint8_t a_hi1;
        bool overflow1;
        if (value != 1) {
            uint16_t value2 = RAM16(0x00FC);
            a1 = (uint8_t)((value2 >> 3) - 0x40);
            a_hi1 = (uint16_t)((value2 >> 3) - 0x40) >> 8;
            overflow1 = (((value2 >> 3) ^ 0x40) & ((value2 >> 3) ^ (uint16_t)((value2 >> 3) - 0x40)) & 0x8000) != 0;
        } else {
            uint16_t value3 = RAM16(0x00FC);
            a1 = (uint8_t)((value3 >> 3) + 0x3F);
            a_hi1 = (value3 >> 3) + 0x3F >> 8;
            overflow1 = (((value3 >> 3) ^ (value3 >> 3) + 0x3F) & ((value3 >> 3) + 0x3F ^ 0x3F) & 0x8000) != 0;
        }
        RAM8(0x0000 + sp0) = a_hi1;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi1 << 8) | a1);
        r->a = (a_hi1 << 8) | a1;
        r->x = value;
        r->y = (uint8_t)y;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 1;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x98FF, 0xC099F3); GUARD_JSR(c, sp_call, 0x98FF); } /* configure_rom_row_cursor_and_execute_relocated_rle_decoder */
        r->sp += 2;
        uint16_t dp_ret = r->dp;
        uint16_t y_ret = r->y;
        uint8_t value4 = RAM8(0x0000 + sp0 - 1);
        uint8_t value5 = RAM8(0x0000 + sp0);
        BUS16_SET(c, (uint16_t)(dp_ret + 0x74), (uint16_t)((((uint8_t)((value5 << 8) | value4) << 8) | value5) << 1) & 0xFE00);
        uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xFA));
        uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x74));
        BUS16_SET(c, (uint16_t)(dp_ret + 0x74), ((uint16_t)((value6 >> 3) - 0x40) & 0x01FF) | value7);
        BUS16_SET(c, (uint16_t)(dp_ret + 0x76), (((uint16_t)((value6 >> 3) - 0x40) & 0x01FF) | value7) & 0x7F);
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x74));
        uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x76));
        BUS16_SET(c, (uint16_t)(dp_ret + 0x76), ((value8 >> 2) & 0x3F80) | value9);
        BUS8_SET(c, (uint16_t)(dp_ret + 0x2E), 0xFF);
        r->a = ((value8 >> 2) & 0x3F80) | value9;
        r->x = 0xFF;
        r->y = (uint8_t)y_ret;
        r->c = value8 >> 1 & 0x01;
        r->v = (((value6 >> 3) ^ 0x40) & ((value6 >> 3) ^ (uint16_t)((value6 >> 3) - 0x40)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 1;
        RETURN_RTS(c);
    }
    r->x = value;
    r->y = (uint8_t)y;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC098E4, SOM_RTS, "gen", prepare_upper_or_lower_scene_tile_row_for_publication, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, -1, -1, 88, 50)
