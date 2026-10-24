#include "som_c.h"

/* 7E9FA4 request_image_row_and_replace_graphics   [class B, 101 bytes, 58 instructions]
 * Source: src/boot/request_image_row_and_replace_graphics.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$05E5.  Callers read: XYCV.
 */
static void request_image_row_and_replace_graphics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x05E5) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xE5;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 7) = 0;
    RAM8(0x0000 + sp0 - 8) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 9) = 0x7F;
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), value);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), x);
    r->c = (uint16_t)(sp0 - 5) >= 2;
    r->z = (uint8_t)value == 0;
    r->n = (uint8_t)value & 0x80;
    r->v = (((uint16_t)(sp0 - 5) ^ 2) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 7);
    r->sp -= 8;
    JSR(c, 0x9FC3, 0x7EB1A9); /* allocate_eight_byte_record */
    r->sp += 8;
    uint16_t x_ret = r->x;
    RAM16_SET(0x10003 + x_ret, 3);
    RAM16_SET(0x10004 + x_ret, RAM16(0x0003 + (uint16_t)(sp0 - 7)));
    uint16_t value3 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
    r->a = value3;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 8;
    JSR(c, 0x9FD3, 0x7EB258); /* append_pending_record */
    r->sp += 8;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 8;
    JSR(c, 0x9FD6, 0x7EB2FB); /* receive_raw_task_record */
    r->sp += 8;
    uint16_t x_ret3 = r->x;
    uint16_t y_ret2 = r->y;
    bool carry_ret3 = r->c;
    bool overflow_ret3 = r->v;
    uint16_t value4 = RAM16(0x10003 + x_ret3);
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool carry1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value4 == 0) {
        a_hi1 = value4 >> 8;
        x1 = x_ret3;
        y1 = y_ret2;
        carry1 = carry_ret3;
        zero1 = value4 == 0;
        negative1 = value4 & 0x8000;
        overflow1 = overflow_ret3;
    } else {
        RAM8(0x0000 + sp0 - 8) = x_ret3 >> 8;
        RAM8(0x0000 + sp0 - 9) = (uint8_t)x_ret3;
        r->z = value4 == 0;
        r->n = value4 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 10;
        JSR(c, 0x9FDF, 0x7E8686); /* queue_colour_sample_palette */
        r->sp += 10;
        bool overflow_ret4 = r->v;
        uint16_t value5 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
        RAM8(0x0000 + sp0 - 0x0A) = ((((((uint16_t)(value5 << 1) >> 0x0F << 7) | (overflow_ret4 << 6)) | (d_entry << 3)) | (i_entry << 2)) | (((uint16_t)(value5 << 1) == 0) << 1)) | (value5 >> 0x0F);
        BUS16_SET(c, 0x004202, ((uint8_t)(value5 << 1) << 8) | 0x20);
        RAM8(0x0000 + sp0 - 0x0B) = (uint8_t)(value5 << 1);
        RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)(((uint8_t)(value5 << 1) << 8) | 0x20);
        uint16_t value6 = BUS16(c, 0x004216);
        r->x = value6;
        r->c = value5 & 0x8000;
        r->z = value6 == 0;
        r->n = value6 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 10;
        JSR(c, 0x9FFA, 0x7EBEDD); /* replace_colour_graphics_workspace */
        r->sp += 10;
        uint16_t a_all5 = r->a;
        uint16_t y_ret4 = r->y;
        bool carry_ret5 = r->c;
        bool overflow_ret5 = r->v;
        uint8_t value7 = RAM8(0x0000 + sp0 - 9);
        uint8_t value8 = RAM8(0x0000 + sp0 - 8);
        a_hi1 = a_all5 >> 8;
        x1 = (value8 << 8) | value7;
        y1 = y_ret4;
        carry1 = carry_ret5;
        zero1 = ((value8 << 8) | value7) == 0;
        negative1 = ((value8 << 8) | value7) & 0x8000;
        overflow1 = overflow_ret5;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 8;
    JSR(c, 0x9FFE, 0x7EB1DD); /* release_eight_byte_record */
    r->sp += 8;
    uint8_t value13 = RAM8(0x0000 + sp0 - 1);
    uint8_t value14 = RAM8(0x0000 + sp0);
    r->c = carry;
    r->v = overflow;
    r->mf = 0;
    r->xf = 0;
    r->db = 0;
    r->dp = (value14 << 8) | value13;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9FA4, SOM_RTS, "gen", request_image_row_and_replace_graphics, 0, L_X | L_Y | L_C | L_V, 13, 0, 0, 101, 58)
