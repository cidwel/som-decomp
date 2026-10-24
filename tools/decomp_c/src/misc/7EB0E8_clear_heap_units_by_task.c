#include "som_c.h"

/* 7EB0E8 clear_heap_units_by_task   [class B, 65 bytes, 41 instructions]
 * Source: src/boot/clear_heap_units_by_task.s
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: CV.
 */
static void clear_heap_units_by_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 7) = 0x7F;
    RAM8(0x0001 + (uint16_t)(sp0 - 5)) = 0;
    uint16_t x1 = 0x0100;
    uint16_t y1 = 0x0100;
    do {
        uint8_t value = BUS8(c, 0x7F01C4 + (uint16_t)(x1 - 1));
        uint16_t y2;
        if ((uint8_t)a != value) {
            y2 = y1;
        } else {
            BUS8_SET(c, 0x7F00C4 + (uint16_t)(x1 - 1), 0);
            BUS8_SET(c, 0x7F01C4 + (uint16_t)(x1 - 1), 0);
            y2 = (uint16_t)(x1 - 1);
        }
        RAM8(0x0001 + (uint16_t)(sp0 - 5))--;
        x1 = (uint16_t)(x1 - 1);
        y1 = y2;
    } while (RAM8(0x0001 + (uint16_t)(sp0 - 5)) != 0);
    if (y1 != 0x0100) {
        if ((uint8_t)y1 < RAM8(0x100C2)) {
            RAM8(0x100C2) = (uint8_t)y1;
        }
    }
    uint8_t value3 = RAM8(0x0000 + sp0 - 5);
    uint8_t value6 = RAM8(0x0000 + sp0 - 2);
    uint8_t value7 = RAM8(0x0000 + sp0 - 1);
    uint8_t value8 = RAM8(0x0000 + sp0);
    r->c = value6 & 0x01;
    r->v = value6 & 0x40;
    r->mf = value6 & 0x20;
    r->xf = value6 & 0x10;
    r->db = value3;
    r->dp = (value8 << 8) | value7;
    r->i = value6 & 0x04;
    r->d = value6 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB0E8, SOM_RTS, "gen", clear_heap_units_by_task, 0, L_C | L_V, 8, 0, 0, 65, 41)
