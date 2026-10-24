#include "som_c.h"

/* 7E8AB5 construct_four_title_colour_hdma_channels   [class B, 75 bytes, 33 instructions]
 * Source: src/boot/construct_four_title_colour_hdma_channels.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$06ED.  Callers read: ABCV.
 */
static void construct_four_title_colour_hdma_channels(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x06ED) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 6;
    RAM8(0x0000 + sp0 - 1) = 0xED;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->x = 0x4A;
    r->y = 0x5D86;
    r->z = 0;
    r->n = 0;
    r->mf = 1;
    r->i = 1;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8AC5, 0x7E8A54); GUARD_JSR(c, sp_call, 0x8AC5); } /* allocate_and_submit_title_colour_hdma_resource */
    r->sp += 4;
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x46;
    r->y = 0x5D79;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8ACE, 0x7E8A54); GUARD_JSR(c, sp_call, 0x8ACE); } /* allocate_and_submit_title_colour_hdma_resource */
    r->sp += 4;
    if (r->xf != 0) { c->fail = 3; return; }
    r->x = 0x42;
    r->y = 0x5D6C;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8AD7, 0x7E8A54); GUARD_JSR(c, sp_call, 0x8AD7); } /* allocate_and_submit_title_colour_hdma_resource */
    r->sp += 4;
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all3 = r->a;
    r->a = (a_all3 >> 8 << 8) | 5;
    r->z = 0;
    r->n = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8ADC, 0x7E8FC7); GUARD_JSR(c, sp_call, 0x8ADC); } /* allocate_transfer_descriptor */
    r->sp += 4;
    uint8_t db_ret4 = r->db;
    bool x_ret5 = r->xf;
    uint16_t x_ret6 = r->x;
    uint16_t y_ret4 = r->y;
    if (x_ret5) {
        BUS8_SET(c, (db_ret4 << 0x10) + 0x40, (uint8_t)x_ret6);
        BUS16_SET(c, (db_ret4 << 0x10) + 2 + (uint8_t)x_ret6, 0x5D63);
        BUS8_SET(c, (db_ret4 << 0x10) + 4 + (uint8_t)x_ret6, 0x7E);
        BUS8_SET(c, (db_ret4 << 0x10) + 1 + (uint8_t)x_ret6, 0x21);
        BUS8_SET(c, (db_ret4 << 0x10) + (uint8_t)x_ret6, 0);
        r->a = 0x5D00;
        r->x = (uint8_t)x_ret6;
        r->y = (uint8_t)y_ret4;
        r->z = 1;
        r->n = 0;
        r->mf = 1;
        r->xf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8AFB, 0x7E90DA); GUARD_JSR(c, sp_call, 0x8AFB); } /* submit_transfer_or_program_hdma */
        r->sp += 4;
        uint8_t value2 = RAM8(0x0000 + sp0 - 2);
        uint8_t value3 = RAM8(0x0000 + sp0 - 1);
        uint8_t value4 = RAM8(0x0000 + sp0);
        r->c = value2 & 0x01;
        r->v = value2 & 0x40;
        r->mf = value2 & 0x20;
        r->xf = value2 & 0x10;
        r->dp = (value4 << 8) | value3;
        r->i = value2 & 0x04;
        r->d = value2 & 0x08;
        RETURN_RTS(c);
    } else {
        BUS16_SET(c, (db_ret4 << 0x10) + 0x40, x_ret6);
        BUS16_SET(c, (db_ret4 << 0x10) + 2 + x_ret6, 0x5D63);
        BUS8_SET(c, (db_ret4 << 0x10) + 4 + x_ret6, 0x7E);
        BUS8_SET(c, (db_ret4 << 0x10) + 1 + x_ret6, 0x21);
        BUS8_SET(c, (db_ret4 << 0x10) + x_ret6, 0);
        r->a = 0x5D00;
        r->z = 1;
        r->n = 0;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8AFB, 0x7E90DA); GUARD_JSR(c, sp_call, 0x8AFB); } /* submit_transfer_or_program_hdma */
        r->sp += 4;
        uint8_t value6 = RAM8(0x0000 + sp0 - 2);
        uint8_t value7 = RAM8(0x0000 + sp0 - 1);
        uint8_t value8 = RAM8(0x0000 + sp0);
        r->c = value6 & 0x01;
        r->v = value6 & 0x40;
        r->mf = value6 & 0x20;
        r->xf = value6 & 0x10;
        r->dp = (value8 << 8) | value7;
        r->i = value6 & 0x04;
        r->d = value6 & 0x08;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7E8AB5, SOM_RTS, "gen", construct_four_title_colour_hdma_channels, 0, L_A | L_B | L_C | L_V, 4, 0, 0, 75, 33)
