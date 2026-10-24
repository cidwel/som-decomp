#include "som_c.h"
#include "som_hand_b.h"

/* D0DE82 expand_native_coordinate_digit_tile_and_upload_real_dma_channel_five   [class D, 95 bytes, 44 instructions]
 * Source: src/rom/expand_native_coordinate_digit_tile_and_upload_real_dma_channel_five.s
 * Documented in docs/event-menu-coordinates.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void expand_native_coordinate_digit_tile_and_upload_real_dma_channel_five(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool overflow = r->v;
    if (!hand_rd_ok(0x1880u + x) || !hand_rd_ok(0x1881u + x)) { c->fail = 3; return; } /* open bus: out of contract */
    uint16_t value = BUS16(c, 0x1880 + x);
    uint8_t a_hi1 = 0;
    uint16_t x1 = (value & 0x0F) << 1 << 1 << 1;
    uint16_t y1 = 0;
    bool carry1 = (value & 0x0F) << 1 << 1 & 0x8000;
    for (;;) {
        uint8_t value2 = BUS8(c, 0xD9FF08 + x1);
        RAM8(0x8101 + y1) = value2;
        RAM8(0x8110 + y1) = value2;
        RAM8(0x8111 + y1) = value2;
        RAM8(0x8100 + y1) = 0xFF;
        uint16_t x1_next = (uint16_t)(x1 + 1);
        uint16_t y1_next = (uint16_t)(y1 + 2);
        bool carry1_next = (uint16_t)(y1 + 2) >= 0x10;
        x1 = x1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        if (!(y1 != 0x10)) break;
    }
    BUS16_SET(c, 0x002116, a);
    BUS8_SET(c, 0x004350, 1);
    BUS8_SET(c, 0x004351, 0x18);
    BUS16_SET(c, 0x004352, 0x8100);
    BUS8_SET(c, 0x004354, 0x7E);
    BUS16_SET(c, 0x004355, 0x20);
    BUS8_SET(c, 0x00420B, 0x20);
    r->a = 0x20;
    r->x = (uint16_t)(x + 1);
    r->y = (uint8_t)y1;
    r->c = carry1;
    r->z = (uint16_t)(x + 1) == 0;
    r->n = (uint16_t)(x + 1) & 0x8000;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0DE82, SOM_RTS, "hand", expand_native_coordinate_digit_tile_and_upload_real_dma_channel_five, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, 0, 0, 95, 44)
