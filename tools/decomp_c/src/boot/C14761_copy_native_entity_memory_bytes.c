#include "som_c.h"
#include "som_hand.h"

/* C14761 copy_native_entity_memory_bytes   [class B, 60 bytes, 38 instructions]
 * Source: src/rom/copy_native_entity_memory_bytes.s
 * Documented in docs/actor-cast-entity-queue.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0198.  Callers read: BXY.
 */
static void copy_native_entity_memory_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0198) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 1;
    RAM8(0x0000 + sp0 - 1) = 0x98;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    uint8_t a_hi5;
    uint16_t x5;
    uint16_t y5;
    if (a == 0) {
        a_hi5 = a >> 8;
        x5 = x;
        y5 = y;
    } else {
        uint8_t a_hi4;
        uint16_t x4;
        uint16_t y4;
        if ((a & 1) == 0) {
            RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), a >> 1);
            uint8_t a_hi1 = a >> 1 >> 8;
            uint16_t x1 = x;
            uint16_t y1 = y;
            do {
                uint16_t value = RAM16(0x0000 + x1);
                RAM16_SET(0x0000 + y1, value);
                RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 5)) - 1));
                a_hi1 = value >> 8;
                x1 = (uint16_t)(x1 + 2);
                y1 = (uint16_t)(y1 + 2);
            } while (RAM16(0x0001 + (uint16_t)(sp0 - 5)) != 0);
            a_hi4 = a_hi1;
            x4 = x1;
            y4 = y1;
        } else {
            RAM8(0x0000 + sp0 - 5) = a >> 8;
            RAM8(0x0000 + sp0 - 6) = (uint8_t)a;
            RAM8(0x0000 + y) = RAM8(0x0000 + x);
            uint8_t a_hi3;
            uint16_t x3;
            uint16_t y3;
            if ((uint16_t)(a - 1) == 0) {
                a_hi3 = (uint16_t)(a - 1) >> 8;
                x3 = (uint16_t)(x + 1);
                y3 = (uint16_t)(y + 1);
            } else {
                RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), (uint16_t)(a - 1) >> 1);
                uint8_t a_hi2 = (uint16_t)(a - 1) >> 1 >> 8;
                uint16_t x2 = (uint16_t)(x + 1);
                uint16_t y2 = (uint16_t)(y + 1);
                do {
                    uint16_t value3 = RAM16(0x0000 + x2);
                    RAM16_SET(0x0000 + y2, value3);
                    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 5)) - 1));
                    a_hi2 = value3 >> 8;
                    x2 = (uint16_t)(x2 + 2);
                    y2 = (uint16_t)(y2 + 2);
                } while (RAM16(0x0001 + (uint16_t)(sp0 - 5)) != 0);
                a_hi3 = a_hi2;
                x3 = x2;
                y3 = y2;
            }
            a_hi4 = a_hi3;
            x4 = x3;
            y4 = y3;
        }
        a_hi5 = a_hi4;
        x5 = x4;
        y5 = y4;
    }
    r->a = (a_hi5 << 8) | RAM8(0x0000 + sp0 - 3);
    r->x = x5;
    r->y = y5;
    som_pull_p(c, sp0 - 2); /* PLP */
    r->dp = RAM8(sp0 - 1) | (RAM8(sp0) << 8); /* PLD */
    r->z = r->dp == 0;
    r->n = r->dp & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC14761, SOM_RTS, "hand", copy_native_entity_memory_bytes, 0, L_B | L_X | L_Y, 7, 0, 0, 60, 38)
