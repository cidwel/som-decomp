#include "som_c.h"

/* 7EC0C2 count_ppu_queue_entries   [class B, 59 bytes, 33 instructions]
 * Source: src/boot/count_ppu_queue_entries.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$4200.  Callers read: ABXYCZNV.
 */
static void count_ppu_queue_entries(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x4200) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0x42;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = 0x02DA;
    for (;;) {
        uint16_t value = BUS16(c, 0x7F0001 + y1);
        if ((value & 0xFF) != 0) {
            uint16_t value2 = RAM16(0x102D6);
            a_hi1 = (uint16_t)((value & 0xFF) + value2) >> 8;
            x1 = (uint16_t)(x1 + 1);
            y1 = (uint16_t)((value & 0xFF) + value2);
            continue;
        }
        a_hi1 = 0;
        break;
    }
    uint8_t a_hi2 = a_hi1;
    uint16_t x2 = x1;
    uint16_t y2 = 0x02DE;
    for (;;) {
        uint16_t value3 = BUS16(c, 0x7F0001 + y2);
        if ((value3 & 0xFF) != 0) {
            uint16_t value4 = RAM16(0x102D6);
            a_hi2 = (uint16_t)((value3 & 0xFF) + value4) >> 8;
            x2 = (uint16_t)(x2 + 1);
            y2 = (uint16_t)((value3 & 0xFF) + value4);
            continue;
        }
        a_hi2 = 0;
        break;
    }
    r->a = x2;
    r->x = x2;
    r->y = y2;
    r->c = carry;
    r->z = 0;
    r->n = 0;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC0C2, SOM_RTS, "gen", count_ppu_queue_entries, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 59, 33)
