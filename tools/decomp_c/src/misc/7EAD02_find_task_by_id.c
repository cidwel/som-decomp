#include "som_c.h"

/* 7EAD02 find_task_by_id   [class B, 63 bytes, 39 instructions]
 * Source: src/boot/find_task_by_id.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCV.
 */
static void find_task_by_id(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = db;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 7) = 0x7F;
    uint8_t a_hi3;
    uint16_t x3;
    uint16_t y3;
    if ((a & 0xFF) == 0) {
        a_hi3 = 0;
        x3 = 0;
        y3 = y;
    } else {
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), a & 0xFF);
        uint16_t value = RAM16(0x1009C);
        uint8_t a_hi1 = 0;
        uint16_t x1 = value;
        uint16_t y1 = 0x14;
        for (;;) {
            uint16_t value2 = BUS16(c, 0x7F0004 + x1);
            uint16_t value3 = RAM16(0x0001 + (uint16_t)(sp0 - 5));
            uint8_t a_hi2;
            uint16_t x2;
            uint16_t y2;
            if ((value2 & 0xFF) == value3) {
                a_hi2 = 0;
                x2 = x1;
                y2 = y1;
            } else {
                if ((uint16_t)(y1 - 1) != 0) {
                    uint8_t a_hi1_next = (uint16_t)(x1 + 0x10) >> 8;
                    uint16_t x1_next = (uint16_t)(x1 + 0x10);
                    uint16_t y1_next = (uint16_t)(y1 - 1);
                    a_hi1 = a_hi1_next;
                    x1 = x1_next;
                    y1 = y1_next;
                    continue;
                }
                a_hi2 = (uint16_t)(x1 + 0x10) >> 8;
                x2 = 0;
                y2 = (uint16_t)(y1 - 1);
            }
            a_hi1 = a_hi2;
            x1 = x2;
            y1 = y2;
            break;
        }
        a_hi3 = a_hi1;
        x3 = x1;
        y3 = y1;
    }
    r->a = (a_hi3 << 8) | RAM8(0x0000 + sp0 - 3);
    r->x = x3;
    r->y = y3;
    r->c = carry;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EAD02, SOM_RTS, "gen", find_task_by_id, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 8, 0, 0, 63, 39)
