#include "som_c.h"

/* C009BA copy_dialogue_window_style_and_fill_graphics_page   [class B, 122 bytes, 56 instructions]
 * Source: src/rom/copy_dialogue_window_style_and_fill_graphics_page.s
 * Documented in docs/event-dialogue-window-state.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BXYV.
 */
static void copy_dialogue_window_style_and_fill_graphics_page(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    RAM16_SET(0xA199, 0);
    uint16_t value = RAM16(0xA24E);
    RAM16_SET(0xA173, 8);
    uint8_t a_hi1 = 0;
    uint16_t x1 = (uint16_t)(((((value & 0xFF) << 8) | 0) >> 1) + 0xD080);
    uint16_t y1 = 0x9400;
    for (;;) {
        r->a = 0x0F;
        r->x = x1;
        r->y = y1;
        r->mf = 0;
        i_mvn(c, 0xD2, 0x7E); /* copy up bank $D2 to bank $7E */
        uint16_t x_moved = r->x;
        uint16_t y_moved = r->y;
        uint16_t value2 = RAM16(0xA199);
        uint16_t value3 = RAM16(0xA173);
        RAM16_SET(0xA173, (uint16_t)(value3 - 1));
        a_hi1 = (uint16_t)(value3 - 1) >> 8;
        x1 = x_moved;
        y1 = (uint16_t)(y_moved + value2);
        if (!((uint16_t)(value3 - 1) != 0)) break;
    }
    uint8_t value5 = RAM8(0xA24F + RAM8(0xA24E));
    RAM16_SET(0xA173, 8);
    uint8_t a_hi2 = 0;
    uint16_t x2 = (uint16_t)((((value5 << 8) | 0) >> 1) + 0xD480);
    uint16_t y2 = y1;
    bool carry1 = (((value5 << 8) | 0) >> 1) + 0xD480 > 0xFFFF;
    bool overflow1 = (((((value5 << 8) | 0) >> 1) ^ (uint16_t)((((value5 << 8) | 0) >> 1) + 0xD480)) & ((uint16_t)((((value5 << 8) | 0) >> 1) + 0xD480) ^ 0xD480) & 0x8000) != 0;
    for (;;) {
        r->a = 0x0F;
        r->x = x2;
        r->y = y2;
        r->mf = 0;
        i_mvn(c, 0xD2, 0x7E); /* copy up bank $D2 to bank $7E */
        uint16_t x_moved2 = r->x;
        uint16_t y_moved2 = r->y;
        uint16_t value6 = RAM16(0xA199);
        uint16_t value7 = RAM16(0xA173);
        RAM16_SET(0xA173, (uint16_t)(value7 - 1));
        a_hi2 = (uint16_t)(value7 - 1) >> 8;
        x2 = x_moved2;
        y2 = (uint16_t)(y_moved2 + value6);
        carry1 = y_moved2 + value6 > 0xFFFF;
        overflow1 = ((y_moved2 ^ (uint16_t)(y_moved2 + value6)) & (value6 ^ (uint16_t)(y_moved2 + value6)) & 0x8000) != 0;
        if (!((uint16_t)(value7 - 1) != 0)) break;
    }
    RAM16_SET(0x000E + y2, 0xFF);
    RAM16_SET(0x1D06, 0x4880);
    r->a = 0x0110;
    r->x = y2;
    r->y = y2;
    r->c = carry1;
    r->z = 0;
    r->n = 0;
    r->v = overflow1;
    r->mf = 0;
    JSR(c, 0x0A30, 0xC01936); /* set_dialogue_graphics_transfer_size_preserving_status */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC009BA, SOM_RTS, "gen", copy_dialogue_window_style_and_fill_graphics_page, 0, L_B | L_X | L_Y | L_V, 1, 1, 0, 122, 56)
