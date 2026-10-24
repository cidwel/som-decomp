#include "som_c.h"

/* 7EB258 append_pending_record   [class B, 83 bytes, 48 instructions]
 * Source: src/boot/append_pending_record.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void append_pending_record_m16x16(SomCtx *c)
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
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
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
    RAM8(0x0000 + sp0 - 6) = (((((uint8_t)a >> 7 << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (((uint8_t)a == 0) << 1) | carry;
    RAM16_SET(0x10000 + x, 0);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x);
    r->z = (uint8_t)a == 0;
    r->n = (uint8_t)a & 0x80;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 5);
    r->i = 1;
    r->sp -= 7;
    JSR(c, 0xB275, 0x7EAD02); /* find_task_by_id */
    r->sp += 7;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x4;
    uint16_t y4;
    if (x_ret == 0) {
        a1 = (uint8_t)x_ret;
        a_hi1 = x_ret >> 8;
        x4 = x_ret;
        y4 = y_ret;
    } else {
        uint16_t value = RAM16(0x1000A + x_ret);
        uint16_t x3;
        uint16_t y3;
        if (value == 0) {
            uint16_t value2 = RAM16(0x0001 + (uint16_t)(sp0 - 5));
            RAM16_SET(0x1000A + x_ret, value2);
            r->a = value2;
            r->y = value;
            r->z = value2 == 0;
            r->n = value2 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 7;
            JSR(c, 0xB28A, 0x7EAC69); /* wake_waiting_task */
            r->sp += 7;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret2 = r->y;
            x3 = x_ret2;
            y3 = y_ret2;
        } else {
            uint16_t x2;
            uint16_t y2;
            if (value != 0xFFFF) {
                uint16_t x1 = x_ret;
                uint16_t y1 = value;
                for (;;) {
                    uint16_t value3 = RAM16(0x10000 + y1);
                    if (value3 != 0) {
                        x1 = value3;
                        y1 = value3;
                        continue;
                    }
                    x1 = value3;
                    break;
                }
                RAM16_SET(0x10000 + y1, RAM16(0x0001 + (uint16_t)(sp0 - 5)));
                x2 = x1;
                y2 = y1;
            } else {
                uint16_t value5 = RAM16(0x0001 + (uint16_t)(sp0 - 5));
                RAM16_SET(0x1000A + x_ret, value5);
                r->a = value5;
                r->y = value;
                r->c = value >= 0xFFFF;
                r->z = value5 == 0;
                r->n = value5 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                r->sp -= 7;
                JSR(c, 0xB28A, 0x7EAC69); /* wake_waiting_task */
                r->sp += 7;
                uint16_t x_ret3 = r->x;
                uint16_t y_ret3 = r->y;
                x2 = x_ret3;
                y2 = y_ret3;
            }
            x3 = x2;
            y3 = y2;
        }
        a1 = 0xFF;
        a_hi1 = 0xFF;
        x4 = x3;
        y4 = y3;
    }
    RAM8(0x0000 + sp0 - 3) = a1;
    uint8_t value7 = RAM8(0x0000 + sp0 - 3);
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value7;
    r->x = x4;
    r->y = y4;
    r->c = carry;
    r->z = ((value9 << 8) | value8) == 0;
    r->n = ((value9 << 8) | value8) & 0x8000;
    r->v = overflow;
    r->db = db;
    r->dp = (value9 << 8) | value8;
    r->i = i_entry; /* PLP restores the entry mode flags */
    r->d = d_entry;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}

/* 7EB258 append_pending_record   [class B, 83 bytes, 48 instructions]
 * Source: src/boot/append_pending_record.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void append_pending_record_m8x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = db;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 7) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = (((((uint8_t)((a_hi << 8) | a) >> 7 << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (((uint8_t)((a_hi << 8) | a) == 0) << 1) | carry;
    RAM16_SET(0x10000 + x, 0);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x);
    r->a = (a_hi << 8) | a;
    r->z = (uint8_t)((a_hi << 8) | a) == 0;
    r->n = (uint8_t)((a_hi << 8) | a) & 0x80;
    r->mf = 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 5);
    r->i = 1;
    r->sp -= 7;
    JSR(c, 0xB275, 0x7EAD02); /* find_task_by_id */
    r->sp += 7;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x4;
    uint16_t y4;
    if (x_ret == 0) {
        a1 = (uint8_t)x_ret;
        a_hi1 = x_ret >> 8;
        x4 = x_ret;
        y4 = y_ret;
    } else {
        uint16_t value = RAM16(0x1000A + x_ret);
        uint16_t x3;
        uint16_t y3;
        if (value == 0) {
            uint16_t value2 = RAM16(0x0001 + (uint16_t)(sp0 - 5));
            RAM16_SET(0x1000A + x_ret, value2);
            r->a = value2;
            r->y = value;
            r->z = value2 == 0;
            r->n = value2 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 7;
            JSR(c, 0xB28A, 0x7EAC69); /* wake_waiting_task */
            r->sp += 7;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret2 = r->y;
            x3 = x_ret2;
            y3 = y_ret2;
        } else {
            uint16_t x2;
            uint16_t y2;
            if (value != 0xFFFF) {
                uint16_t x1 = x_ret;
                uint16_t y1 = value;
                for (;;) {
                    uint16_t value3 = RAM16(0x10000 + y1);
                    if (value3 != 0) {
                        x1 = value3;
                        y1 = value3;
                        continue;
                    }
                    x1 = value3;
                    break;
                }
                RAM16_SET(0x10000 + y1, RAM16(0x0001 + (uint16_t)(sp0 - 5)));
                x2 = x1;
                y2 = y1;
            } else {
                uint16_t value5 = RAM16(0x0001 + (uint16_t)(sp0 - 5));
                RAM16_SET(0x1000A + x_ret, value5);
                r->a = value5;
                r->y = value;
                r->c = value >= 0xFFFF;
                r->z = value5 == 0;
                r->n = value5 & 0x8000;
                r->mf = 0;
                r->xf = 0;
                r->sp -= 7;
                JSR(c, 0xB28A, 0x7EAC69); /* wake_waiting_task */
                r->sp += 7;
                uint16_t x_ret3 = r->x;
                uint16_t y_ret3 = r->y;
                x2 = x_ret3;
                y2 = y_ret3;
            }
            x3 = x2;
            y3 = y2;
        }
        a1 = 0xFF;
        a_hi1 = 0xFF;
        x4 = x3;
        y4 = y3;
    }
    RAM8(0x0000 + sp0 - 3) = a1;
    uint8_t value7 = RAM8(0x0000 + sp0 - 3);
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value7;
    r->x = x4;
    r->y = y4;
    r->c = carry;
    r->z = ((value9 << 8) | value8) == 0;
    r->n = ((value9 << 8) | value8) & 0x8000;
    r->v = overflow;
    r->db = db;
    r->dp = (value9 << 8) | value8;
    r->i = i_entry; /* PLP restores the entry mode flags */
    r->d = d_entry;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}

/* Entered with M16/X16, M8/X16 accumulator/index widths: one body per width pair. */
static void append_pending_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (r->mf == 0 && r->xf == 0) { append_pending_record_m16x16(c); return; }
    if (r->mf == 1 && r->xf == 0) { append_pending_record_m8x16(c); return; }
    c->fail = 3;
}
SOM_REGISTER(0x7EB258, SOM_RTS, "hand", append_pending_record, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 8, -1, -1, 83, 48)
