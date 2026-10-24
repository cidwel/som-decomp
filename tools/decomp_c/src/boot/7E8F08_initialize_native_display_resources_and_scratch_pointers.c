#include "som_c.h"

/* 7E8F08 initialize_native_display_resources_and_scratch_pointers   [class B, 60 bytes, 30 instructions]
 * Source: src/boot/initialize_native_display_resources_and_scratch_pointers.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: BYCZNV.
 */
static void initialize_native_display_resources_and_scratch_pointers(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    r->a = (a >> 8 << 8) | 0;
    r->x = 0x0200;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8F1A, 0x7EB0A1); GUARD_JSR(c, sp_call, 0x8F1A); } /* allocate_and_fill_bytes */
    r->sp += 4;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    RAM16_SET(0x10064, x_ret);
    r->a = (a_all >> 8 << 8) | 0;
    r->x = 0x60;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8F25, 0x7EB0A1); GUARD_JSR(c, sp_call, 0x8F25); } /* allocate_and_fill_bytes */
    r->sp += 4;
    bool x_ret2 = r->xf;
    uint16_t x_ret3 = r->x;
    if (x_ret2) {
        RAM8(0x10066) = (uint8_t)x_ret3;
        RAM8(0x10068) = (uint8_t)((uint8_t)x_ret3 + 0x40);
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    } else {
        RAM16_SET(0x10066, x_ret3);
        RAM16_SET(0x10068, (uint16_t)(x_ret3 + 0x40));
        r->a = (uint16_t)(x_ret3 + 0x40);
        r->x = 0xC0;
        r->c = x_ret3 + 0x40 > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = ((x_ret3 ^ (uint16_t)(x_ret3 + 0x40)) & ((uint16_t)(x_ret3 + 0x40) ^ 0x40) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8F39, 0x7EB081); GUARD_JSR(c, sp_call, 0x8F39); } /* allocate_boot_heap_bytes_without_fill */
        r->sp += 4;
        uint8_t db_ret = r->db;
        bool m_ret2 = r->mf;
        bool x_ret4 = r->xf;
        uint16_t x_ret5 = r->x;
        uint16_t y_ret3 = r->y;
        if (x_ret4) {
            BUS8_SET(c, (db_ret << 0x10) + 0x6A, (uint8_t)x_ret5);
            if (m_ret2) {
                BUS8_SET(c, (db_ret << 0x10) + 0x6C, 0);
                uint8_t value = RAM8(0x0000 + sp0 - 3);
                uint8_t value2 = RAM8(0x0000 + sp0 - 2);
                uint8_t value3 = RAM8(0x0000 + sp0 - 1);
                uint8_t value4 = RAM8(0x0000 + sp0);
                r->y = (uint8_t)y_ret3;
                r->c = value2 & 0x01;
                r->z = ((value4 << 8) | value3) == 0;
                r->n = ((value4 << 8) | value3) & 0x8000;
                r->v = value2 & 0x40;
                r->mf = value2 & 0x20;
                r->xf = value2 & 0x10;
                r->db = value;
                r->dp = (value4 << 8) | value3;
                r->i = value2 & 0x04;
                r->d = value2 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                BUS16_SET(c, (db_ret << 0x10) + 0x6C, 0);
                uint8_t value5 = RAM8(0x0000 + sp0 - 3);
                uint8_t value6 = RAM8(0x0000 + sp0 - 2);
                uint8_t value7 = RAM8(0x0000 + sp0 - 1);
                uint8_t value8 = RAM8(0x0000 + sp0);
                r->y = (uint8_t)y_ret3;
                r->c = value6 & 0x01;
                r->z = ((value8 << 8) | value7) == 0;
                r->n = ((value8 << 8) | value7) & 0x8000;
                r->v = value6 & 0x40;
                r->mf = value6 & 0x20;
                r->xf = value6 & 0x10;
                r->db = value5;
                r->dp = (value8 << 8) | value7;
                r->i = value6 & 0x04;
                r->d = value6 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            BUS16_SET(c, (db_ret << 0x10) + 0x6A, x_ret5);
            if (m_ret2) {
                BUS8_SET(c, (db_ret << 0x10) + 0x6C, 0);
                uint8_t value9 = RAM8(0x0000 + sp0 - 3);
                uint8_t value10 = RAM8(0x0000 + sp0 - 2);
                uint8_t value11 = RAM8(0x0000 + sp0 - 1);
                uint8_t value12 = RAM8(0x0000 + sp0);
                r->c = value10 & 0x01;
                r->z = ((value12 << 8) | value11) == 0;
                r->n = ((value12 << 8) | value11) & 0x8000;
                r->v = value10 & 0x40;
                r->mf = value10 & 0x20;
                r->xf = value10 & 0x10;
                r->db = value9;
                r->dp = (value12 << 8) | value11;
                r->i = value10 & 0x04;
                r->d = value10 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                BUS16_SET(c, (db_ret << 0x10) + 0x6C, 0);
                uint8_t value13 = RAM8(0x0000 + sp0 - 3);
                uint8_t value14 = RAM8(0x0000 + sp0 - 2);
                uint8_t value15 = RAM8(0x0000 + sp0 - 1);
                uint8_t value16 = RAM8(0x0000 + sp0);
                r->c = value14 & 0x01;
                r->z = ((value16 << 8) | value15) == 0;
                r->n = ((value16 << 8) | value15) & 0x8000;
                r->v = value14 & 0x40;
                r->mf = value14 & 0x20;
                r->xf = value14 & 0x10;
                r->db = value13;
                r->dp = (value16 << 8) | value15;
                r->i = value14 & 0x04;
                r->d = value14 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
}
SOM_REGISTER(0x7E8F08, SOM_RTS, "gen", initialize_native_display_resources_and_scratch_pointers, 0, L_B | L_Y | L_C | L_Z | L_N | L_V, 5, 0, 0, 60, 30)
