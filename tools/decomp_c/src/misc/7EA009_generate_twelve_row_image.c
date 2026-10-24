#include "som_c.h"

/* 7EA009 generate_twelve_row_image   [class B, 88 bytes, 48 instructions]
 * Source: src/boot/generate_twelve_row_image.s
 * Documented in docs/boot.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$05F1.  Callers read: XYCZNV.
 */
static void generate_twelve_row_image(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x05F1) { c->fail = 3; return; }
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
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xF1;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 9) = 0x7F;
    RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 0x0B) = 0;
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), value);
    RAM16_SET(0x0116, x);
    RAM16_SET(0x0110, (((uint8_t)value << 8) | (value >> 8)) & 0xFF);
    RAM16_SET(0x0112, 0);
    RAM16_SET(0x0114, 0);
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), 0);
    uint8_t a1 = 0;
    uint8_t a_hi1 = 0;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = (uint16_t)(sp0 - 5) >= 4;
    bool overflow1 = (((uint16_t)(sp0 - 5) ^ 4) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
    uint8_t data_bank = 0;
    uint16_t direct_page = (uint16_t)(sp0 - 9);
    for (;;) {
        uint16_t value2 = RAM16(0x0005 + direct_page);
        r->a = (a_hi1 << 8) | a1;
        r->x = value2;
        r->y = y1;
        r->c = carry1;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 10;
        { const uint16_t sp_call = r->sp; JSR(c, 0xA03D, 0x7E9FA4); GUARD_JSR(c, sp_call, 0xA03D); } /* request_image_row_and_replace_graphics */
        r->sp += 10;
        bool x_ret = r->xf;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        RAM16_SET(0x0001 + direct_page, 0x10);
        uint8_t a_hi2 = 0;
        uint16_t x2 = x_ret2;
        uint16_t y2 = y_ret;
        bool carry2 = carry_ret;
        bool zero1 = 0;
        bool negative1 = 0;
        bool overflow2 = overflow_ret;
        uint8_t data_bank2 = data_bank;
        uint16_t direct_page2 = direct_page;
        for (;;) {
            r->x = x2;
            r->y = y2;
            r->c = carry2;
            r->z = zero1;
            r->n = negative1;
            r->v = overflow2;
            r->mf = 0;
            r->xf = x_ret;
            r->db = data_bank2;
            r->dp = direct_page2;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0xA045, 0x7E9DB6); GUARD_JSR(c, sp_call, 0xA045); } /* decode_transform_image_group */
            r->sp += 10;
            uint8_t db_ret = r->db;
            r->mf = 0;
            r->sp -= 10;
            { const uint16_t sp_call = r->sp; JSR(c, 0xA048, 0x7E9F74); GUARD_JSR(c, sp_call, 0xA048); } /* mix_convert_submit_image_group */
            r->sp += 10;
            uint16_t dp_ret2 = r->dp;
            uint16_t a_all3 = r->a;
            uint16_t x_ret6 = r->x;
            uint16_t y_ret3 = r->y;
            bool carry_ret3 = r->c;
            bool overflow_ret3 = r->v;
            RAM16_SET(0x0001 + dp_ret2, (uint16_t)(RAM16(0x0001 + dp_ret2) - 1));
            a_hi2 = a_all3 >> 8;
            x2 = x_ret6;
            y2 = y_ret3;
            carry2 = carry_ret3;
            zero1 = RAM16(0x0001 + dp_ret2) == 0;
            negative1 = RAM16(0x0001 + dp_ret2) & 0x8000;
            overflow2 = overflow_ret3;
            data_bank2 = db_ret;
            direct_page2 = dp_ret2;
            if (!(RAM16(0x0001 + direct_page2) != 0)) break;
        }
        uint16_t value3 = RAM16(0x0003 + direct_page2);
        RAM16_SET(0x0003 + direct_page2, (uint16_t)(value3 + 1));
        if (x_ret != 0) { c->fail = 3; return; }
        a1 = (uint8_t)(value3 + 1);
        a_hi1 = (uint16_t)(value3 + 1) >> 8;
        x1 = x2;
        y1 = y2;
        carry1 = (uint16_t)(value3 + 1) >= 0x0C;
        overflow1 = overflow2;
        data_bank = data_bank2;
        direct_page = direct_page2;
        if (!((uint16_t)(value3 + 1) != 0x0C)) break;
    }
    uint8_t value4 = RAM8(0x0000 + sp0 - 9);
    uint8_t value5 = RAM8(0x0000 + sp0 - 2);
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->x = x1;
    r->y = y1;
    r->c = value5 & 0x01;
    r->z = ((value7 << 8) | value6) == 0;
    r->n = ((value7 << 8) | value6) & 0x8000;
    r->v = value5 & 0x40;
    r->mf = value5 & 0x20;
    r->xf = value5 & 0x10;
    r->db = value4;
    r->dp = (value7 << 8) | value6;
    r->i = value5 & 0x04;
    r->d = value5 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA009, SOM_RTS, "gen", generate_twelve_row_image, 0, L_X | L_Y | L_C | L_Z | L_N | L_V, 12, 0, 0, 88, 48)
