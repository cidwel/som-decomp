#include "som_c.h"

/* D0CDF9 upload_ten_menu_graphics_blocks_with_dma5   [class D, 90 bytes, 44 instructions]
 * Source: src/rom/upload_ten_menu_graphics_blocks_with_dma5.s
 * Documented in docs/event-menu-palette-graphics.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void upload_ten_menu_graphics_blocks_with_dma5(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0x1820, 0xD2);
    uint8_t a1 = 0;
    uint8_t a_hi1 = 0;
    uint16_t x1 = 0;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool zero1 = 1;
    bool negative1 = 0;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value = BUS16(c, 0xD0CE53 + x1);
        BUS16_SET(c, 0x002116, ((value & 0xFF) + 0x0100 << 1 << 1 << 1 << 1) + 0x6000);
        BUS16_SET(c, 0x004352, (uint16_t)(((a_hi1 << 8) | a1) + 0xC680));
        BUS16_SET(c, 0x004355, 0x40);
        BUS8_SET(c, 0x004350, 1);
        BUS8_SET(c, 0x004351, 0x18);
        BUS8_SET(c, 0x004354, RAM8(0x1820));
        BUS8_SET(c, 0x00420B, 0x20);
        bool again = (uint16_t)(((a_hi1 << 8) | a1) + 0x40) < 0x0280;
        uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) + 0x40);
        uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) + 0x40) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 1);
        uint16_t y1_next = ((value & 0xFF) + 0x0100 << 1 << 1 << 1 << 1) + 0x6000;
        bool carry1_next = (uint16_t)(((a_hi1 << 8) | a1) + 0x40) >= 0x0280;
        bool zero1_next = (uint16_t)(((a_hi1 << 8) | a1) + 0x40) == 0x0280;
        bool negative1_next = (uint16_t)((uint16_t)(((a_hi1 << 8) | a1) + 0x40) - 0x0280) & 0x8000;
        bool overflow1_next = ((((a_hi1 << 8) | a1) ^ (uint16_t)(((a_hi1 << 8) | a1) + 0x40)) & ((uint16_t)(((a_hi1 << 8) | a1) + 0x40) ^ 0x40) & 0x8000) != 0;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        zero1 = zero1_next;
        negative1 = negative1_next;
        overflow1 = overflow1_next;
        if (!again) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0CDF9, SOM_RTL, "gen", upload_ten_menu_graphics_blocks_with_dma5, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 0, 0, 90, 44)
