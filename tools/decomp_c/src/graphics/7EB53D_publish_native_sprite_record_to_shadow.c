#include "som_c.h"

/* 7EB53D publish_native_sprite_record_to_shadow   [class B, 213 bytes, 108 instructions]
 * Source: src/boot/publish_native_sprite_record_to_shadow.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EC.  Callers read: BXY.
 */
static void publish_native_sprite_record_to_shadow(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EC) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 6) + 0x3 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEC;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = x >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
    uint8_t value = BUS8(c, 0x7F000A + x);
    RAM8(0x0001 + (uint16_t)(sp0 - 6)) = value;
    uint16_t value2 = RAM16(0x102CC);
    uint16_t value3 = BUS16(c, 0x7F0008 + x);
    uint8_t a_hi5;
    uint16_t x4;
    if ((value3 & 0xFF) == 0) {
        BUS8_SET(c, 0x7F0001 + (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2), 0xF0);
        a_hi5 = 0;
        x4 = (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2);
    } else {
        uint16_t value4 = BUS16(c, 0x7F0002 + x);
        uint8_t a_hi4;
        uint16_t x3;
        if ((uint16_t)(value4 + 0x10) >= 0xF0) {
            BUS8_SET(c, 0x7F0001 + (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2), 0xF0);
            a_hi4 = (uint16_t)(value4 + 0x10) >> 8;
            x3 = (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2);
        } else {
            uint16_t value5 = BUS16(c, 0x7F0004 + x);
            uint8_t a_hi3;
            uint16_t x2;
            if ((uint16_t)(value5 + 0x10) < 0x0110) {
                uint8_t value6 = BUS8(c, 0x7F000B + x);
                RAM8(0x0000 + sp0 - 6) = (value6 & 3) << 1 << 1 << 1;
                uint8_t value7 = BUS8(c, 0x7F0001 + x);
                RAM8(0x0000 + sp0 - 6) = (uint8_t)(((value7 & 7) | RAM8(0x0000 + sp0 - 6)) << 1);
                uint8_t value9 = BUS8(c, 0x7F0007 + x);
                RAM8(0x0000 + sp0 - 6) = (value9 & 1) | RAM8(0x0000 + sp0 - 6);
                BUS8_SET(c, 0x7F0003 + (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2), (RAM8(0x10000 + x) & 0xC0) | RAM8(0x0000 + sp0 - 6));
                uint8_t value13 = BUS8(c, 0x7F0006 + x);
                BUS8_SET(c, 0x7F0002 + (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2), value13);
                uint8_t value14 = BUS8(c, 0x7F0002 + x);
                BUS8_SET(c, 0x7F0001 + (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2), value14);
                uint8_t value15 = BUS8(c, 0x7F0004 + x);
                RAM8(0x10000 + (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2)) = value15;
                uint8_t value16 = RAM8(0x102CF);
                uint8_t a_hi2;
                uint16_t x1;
                if (value16 != 0) {
                    a_hi2 = (uint16_t)(value5 + 0x10) >> 8;
                    x1 = (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2);
                } else {
                    RAM8(0x0000 + sp0 - 6) = RAM8(0x10000 + x) & 2;
                    uint8_t value18 = BUS8(c, 0x7F0005 + x);
                    RAM8(0x0000 + sp0 - 6) = (value18 & 1) | RAM8(0x0000 + sp0 - 6);
                    RAM8(0x0002 + (uint16_t)(sp0 - 6)) = (RAM8(0x0001 + (uint16_t)(sp0 - 6)) & 3) + 1;
                    RAM8(0x0003 + (uint16_t)(sp0 - 6)) = 3;
                    uint8_t a1 = RAM8(0x0000 + sp0 - 6);
                    uint8_t a_hi1 = (uint16_t)(value5 + 0x10) >> 8;
                    for (;;) {
                        RAM8(0x0002 + (uint16_t)(sp0 - 6))--;
                        if (RAM8(0x0002 + (uint16_t)(sp0 - 6)) != 0) {
                            RAM8(0x0003 + (uint16_t)(sp0 - 6)) <<= 1;
                            RAM8(0x0003 + (uint16_t)(sp0 - 6)) <<= 1;
                            a1 = (uint8_t)(a1 << 2);
                            continue;
                        }
                        break;
                    }
                    RAM8(0x0000 + sp0 - 6) = a1;
                    RAM8(0x0003 + (uint16_t)(sp0 - 6)) ^= 0xFF;
                    uint8_t value25 = RAM8(0x0001 + (uint16_t)(sp0 - 6));
                    uint16_t value26 = RAM16(0x102CC);
                    uint8_t value27 = BUS8(c, 0x7F0200 + (uint16_t)((((a_hi1 << 8) | (value25 >> 2)) & 0x1F) + value26));
                    BUS8_SET(c, 0x7F0200 + (uint16_t)((((a_hi1 << 8) | (value25 >> 2)) & 0x1F) + value26), (value27 & RAM8(0x0003 + (uint16_t)(sp0 - 6))) | RAM8(0x0000 + sp0 - 6));
                    a_hi2 = (uint16_t)((((a_hi1 << 8) | (value25 >> 2)) & 0x1F) + value26) >> 8;
                    x1 = (uint16_t)((((a_hi1 << 8) | (value25 >> 2)) & 0x1F) + value26);
                }
                a_hi3 = a_hi2;
                x2 = x1;
            } else {
                BUS8_SET(c, 0x7F0001 + (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2), 0xF0);
                a_hi3 = (uint16_t)(value5 + 0x10) >> 8;
                x2 = (uint16_t)((((((uint16_t)(sp0 - 6) >> 8 << 8) | value) & 0xFF) << 1 << 1) + value2);
            }
            a_hi4 = a_hi3;
            x3 = x2;
        }
        a_hi5 = a_hi4;
        x4 = x3;
    }
    uint8_t value33 = RAM8(0x0000 + sp0 - 3);
    uint8_t value34 = RAM8(0x0000 + sp0 - 2);
    uint8_t value35 = RAM8(0x0000 + sp0 - 1);
    uint8_t value36 = RAM8(0x0000 + sp0);
    r->a = (a_hi5 << 8) | value33;
    r->x = x4;
    r->y = x;
    r->mf = value34 & 0x20;
    r->xf = value34 & 0x10;
    r->dp = (value36 << 8) | value35;
    r->i = value34 & 0x04;
    r->d = value34 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB53D, SOM_RTS, "gen", publish_native_sprite_record_to_shadow, 0, L_B | L_X | L_Y, 7, 1, 0, 213, 108)
