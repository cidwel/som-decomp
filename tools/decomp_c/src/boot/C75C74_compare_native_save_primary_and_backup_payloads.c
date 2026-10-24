#include "som_c.h"

/* C75C74 compare_native_save_primary_and_backup_payloads   [class B, 104 bytes, 50 instructions]
 * Source: src/rom/compare_native_save_primary_and_backup_payloads.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void compare_native_save_primary_and_backup_payloads(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xA216);
    RAM8(0x0000 + sp0) = value;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    RAM8(0x0000 + sp0 - 2) = 0x30;
    RAM8(0xA175) = 4;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        RAM8(0x0000 + sp0 - 2) = x1 >> 8;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)x1;
        uint8_t value2 = RAM8(0xA216);
        uint8_t a_hi4;
        uint16_t y5;
        if (value2 & 0x01) {
            RAM8(0xA216) = (((value2 >> 1) | (carry1 << 7)) >> 1) | ((value2 & 1) << 7);
            RAM8(0xA215) = (((RAM8(0xA215) >> 1) | 0x80) >> 1) | 0x80;
            a_hi4 = a_hi1;
            y5 = y1;
        } else {
            RAM8(0xA216) = (((value2 >> 1) | (carry1 << 7)) >> 1) | ((value2 & 1) << 7);
            uint8_t a_hi3;
            uint16_t y4;
            if (((value2 >> 1) | (carry1 << 7)) & 0x01) {
                RAM8(0xA215) = (((RAM8(0xA215) >> 1) | 0x80) >> 1) | 0x80;
                a_hi3 = a_hi1;
                y4 = y1;
            } else {
                uint8_t a_hi2 = a_hi1;
                uint16_t x2 = x1;
                uint16_t y2 = 0x02BB;
                for (;;) {
                    uint8_t value5 = BUS8(c, 0x306000 + x2);
                    uint8_t value6 = BUS8(c, 0x307000 + x2);
                    uint16_t y3;
                    if (value5 != value6) {
                        RAM8(0xA215) = (((RAM8(0xA215) >> 1) | 0x80) >> 1) | 0x80;
                        y3 = y2;
                    } else {
                        if ((uint16_t)(y2 - 1) != 0) {
                            x2 = (uint16_t)(x2 + 1);
                            y2 = (uint16_t)(y2 - 1);
                            continue;
                        }
                        uint8_t value8 = RAM8(0xA215);
                        RAM8(0xA215) = (((value8 >> 1) | ((value5 >= value6) << 7)) >> 1) | ((value8 & 1) << 7);
                        y3 = (uint16_t)(y2 - 1);
                    }
                    y2 = y3;
                    break;
                }
                a_hi3 = a_hi2;
                y4 = y2;
            }
            a_hi4 = a_hi3;
            y5 = y4;
        }
        uint8_t value9 = RAM8(0xA175);
        RAM8(0xA175) = (uint8_t)(value9 - 1);
        uint8_t a_hi1_next = (uint16_t)(x1 + 0x0400) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 0x0400);
        uint16_t y1_next = y5;
        bool carry1_next = x1 + 0x0400 > 0xFFFF;
        bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 0x0400)) & ((uint16_t)(x1 + 0x0400) ^ 0x0400) & 0x8000) != 0;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
        if (!((uint8_t)(value9 - 1) != 0)) break;
    }
    RAM8(0xA216) = value;
    r->a = (a_hi1 << 8) | value;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75C74, SOM_RTS, "gen", compare_native_save_primary_and_backup_payloads, 0, L_B | L_X | L_Y | L_C | L_V, 4, 1, 0, 104, 50)
