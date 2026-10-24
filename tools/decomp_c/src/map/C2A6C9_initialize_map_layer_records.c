#include "som_c.h"

/* C2A6C9 initialize_map_layer_records   [class B, 156 bytes, 79 instructions]
 * Source: src/rom/initialize_map_layer_records.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void initialize_map_layer_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    uint8_t x1 = (uint8_t)((a_hi << 8) | 0);
    for (;;) {
        RAM8(0x0A80 + x1) = 0;
        x1 = (uint8_t)(x1 + 1);
        if (!(x1 < 0x40)) break;
    }
    uint8_t value = RAM8(0x0080);
    uint8_t value2 = BUS8(c, 0xC80000 + (uint8_t)((a_hi << 8) | (uint8_t)(value << 2)));
    uint8_t value3 = RAM8(0x009C);
    uint8_t a1;
    if (value3 != 0) {
        a1 = value2;
    } else {
        a1 = value2 & 0xF0;
    }
    uint8_t value4 = RAM8(0x00A0);
    uint8_t a2;
    if (value4 != 0) {
        a2 = a1;
    } else {
        a2 = a1 & 0x0F;
    }
    RAM8(0x0080) = a2;
    RAM8(0x0A80) = a2 & 3;
    uint8_t value5 = RAM8(0x0080);
    RAM8(0x0A90) = (value5 >> 2) & 3;
    RAM8(0x0AA0) = (value5 >> 4) & 3;
    RAM8(0x0AB0) = (uint8_t)(((uint8_t)(((uint8_t)(value5 << 1) << 1) | (value5 >> 7)) << 1) | ((uint8_t)(value5 << 1) >> 7)) & 3;
    uint8_t a_hi2;
    uint8_t x3;
    bool carry2;
    bool overflow2;
    if (value3 == 0) {
        a_hi2 = a_hi;
        x3 = (uint8_t)((a_hi << 8) | (uint8_t)(value << 2));
        carry2 = (uint8_t)(((uint8_t)(value5 << 1) << 1) | (value5 >> 7)) & 0x80;
        overflow2 = overflow;
    } else {
        uint8_t value6 = BUS8(c, 0xC80003 + (uint8_t)((a_hi << 8) | (uint8_t)(value << 2)));
        uint8_t a_hi1;
        uint8_t x2;
        bool carry1;
        bool overflow1;
        if ((value6 & 0x0F) == 0) {
            uint8_t value7 = BUS8(c, 0xC80001 + (uint8_t)((a_hi << 8) | (uint8_t)(value << 2)));
            r->a = a_hi << 8 | (value7 & 0x0F);
            r->x = (uint8_t)((a_hi << 8) | (uint8_t)(value << 2));
            r->y = 0;
            r->c = (uint8_t)(((uint8_t)(value5 << 1) << 1) | (value5 >> 7)) & 0x80;
            r->v = overflow;
            JSR(c, 0xA72B, 0xC2A765); /* set_map_layer_nibble_parameters */
            uint16_t a_all = r->a;
            uint8_t value8 = BUS8(c, 0xC80001 + (uint8_t)((a_hi << 8) | (uint8_t)(value << 2)));
            r->a = (a_all >> 8 << 8) | (value8 >> 4);
            r->y = 0x10;
            r->c = value8 >> 3 & 0x01;
            r->mf = 1;
            r->xf = 1;
            JSR(c, 0xA738, 0xC2A765); /* set_map_layer_nibble_parameters */
            uint16_t a_all2 = r->a;
            bool carry_ret2 = r->c;
            a_hi1 = a_all2 >> 8;
            x2 = (uint8_t)((a_hi << 8) | (uint8_t)(value << 2));
            carry1 = carry_ret2;
            overflow1 = overflow;
        } else {
            r->a = a_hi << 8 | (value6 & 0x0F);
            r->x = (uint8_t)((a_hi << 8) | (uint8_t)(value << 2));
            r->y = 0;
            r->v = overflow;
            JSR(c, 0xA720, 0xC2A7AD); /* set_map_layer_paired_parameters */
            uint16_t a_all3 = r->a;
            uint8_t x_ret = r->x;
            bool carry_ret3 = r->c;
            bool overflow_ret = r->v;
            a_hi1 = a_all3 >> 8;
            x2 = x_ret;
            carry1 = carry_ret3;
            overflow1 = overflow_ret;
        }
        a_hi2 = a_hi1;
        x3 = x2;
        carry2 = carry1;
        overflow2 = overflow1;
    }
    uint8_t value9 = RAM8(0x00A0);
    uint8_t a4;
    uint8_t a_hi4;
    uint8_t x5;
    uint8_t y2;
    bool carry4;
    bool overflow4;
    if (value9 == 0) {
        a4 = value9;
        a_hi4 = a_hi2;
        x5 = x3;
        y2 = 0x20;
        carry4 = carry2;
        overflow4 = overflow2;
    } else {
        uint8_t value10 = BUS8(c, 0xC80003 + x3);
        uint8_t a3;
        uint8_t a_hi3;
        uint8_t x4;
        uint8_t y1;
        bool carry3;
        bool overflow3;
        if (value10 >> 4 == 0) {
            uint8_t value11 = BUS8(c, 0xC80002 + x3);
            r->a = a_hi2 << 8 | (value11 & 0x0F);
            r->x = x3;
            r->y = 0x20;
            r->c = value10 >> 3 & 0x01;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 1;
            JSR(c, 0xA756, 0xC2A765); /* set_map_layer_nibble_parameters */
            uint16_t a_all4 = r->a;
            uint8_t value12 = BUS8(c, 0xC80002 + x3);
            r->a = (a_all4 >> 8 << 8) | (value12 >> 4);
            r->y = 0x30;
            r->c = value12 >> 3 & 0x01;
            r->mf = 1;
            r->xf = 1;
            JSR(c, 0xA763, 0xC2A765); /* set_map_layer_nibble_parameters */
            uint16_t a_all5 = r->a;
            bool carry_ret5 = r->c;
            a3 = (uint8_t)a_all5;
            a_hi3 = a_all5 >> 8;
            x4 = x3;
            y1 = 0x30;
            carry3 = carry_ret5;
            overflow3 = overflow2;
        } else {
            r->a = (a_hi2 << 8) | (value10 >> 4);
            r->x = x3;
            r->y = 0x20;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 1;
            JSR(c, 0xA74B, 0xC2A7AD); /* set_map_layer_paired_parameters */
            uint16_t a_all6 = r->a;
            uint8_t x_ret2 = r->x;
            uint8_t y_ret2 = r->y;
            bool carry_ret6 = r->c;
            bool overflow_ret2 = r->v;
            a3 = (uint8_t)a_all6;
            a_hi3 = a_all6 >> 8;
            x4 = x_ret2;
            y1 = y_ret2;
            carry3 = carry_ret6;
            overflow3 = overflow_ret2;
        }
        a4 = a3;
        a_hi4 = a_hi3;
        x5 = x4;
        y2 = y1;
        carry4 = carry3;
        overflow4 = overflow3;
    }
    r->a = (a_hi4 << 8) | a4;
    r->x = x5;
    r->y = y2;
    r->c = carry4;
    r->v = overflow4;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2A6C9, SOM_RTS, "gen", initialize_map_layer_records, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 156, 79)
