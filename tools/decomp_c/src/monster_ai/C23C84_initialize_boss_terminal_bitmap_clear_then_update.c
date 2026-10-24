#include "som_c.h"

/* C23C84 initialize_boss_terminal_bitmap_clear_then_update   [class B, 39 bytes, 22 instructions]
 * Source: src/rom/initialize_boss_terminal_bitmap_clear_then_update.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void initialize_boss_terminal_bitmap_clear_then_update(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value3 = RAM16(OBJECT_AGE + value2);
    if (value3 >= 0x54) {
        r->a = value3;
        r->x = value2;
        r->c = 1;
        r->z = value3 == 0x54;
        r->n = (uint16_t)(value3 - 0x54) & 0x8000;
        RETURN_RTS(c);
    }
    RAM8(0x0000 + sp0) = 0x7E;
    RAM8(0x0000 + sp0 - 1) = 0x7F;
    uint16_t x1 = 0x1FFE;
    bool zero1 = 0;
    bool negative1 = 0;
    for (;;) {
        BUS16_SET(c, 0x7F6000 + x1, 0);
        uint16_t x1_next = (uint16_t)(x1 - 2);
        bool zero1_next = (uint16_t)(x1 - 2) == 0;
        bool negative1_next = (uint16_t)(x1 - 2) & 0x8000;
        x1 = x1_next;
        zero1 = zero1_next;
        negative1 = negative1_next;
        if (!(!negative1)) break;
    }
    uint8_t value4 = RAM8(0x0000 + sp0);
    r->a = (value3 >> 8 << 8) | 0x7F;
    r->x = x1;
    r->y = y;
    r->c = 0;
    r->z = value4 == 0;
    r->n = value4 & 0x80;
    r->v = overflow;
    r->db = value4;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23C84, SOM_RTS, "gen", initialize_boss_terminal_bitmap_clear_then_update, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 39, 22)
