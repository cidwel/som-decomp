#include "som_c.h"

/* C124D7 mirror_confused_actor_command_direction   [class B, 67 bytes, 35 instructions]
 * Source: src/rom/mirror_confused_actor_command_direction.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BY.
 */
static void mirror_confused_actor_command_direction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    uint8_t value = RAM8(0x0140 + y);
    uint8_t a8;
    if (value == 0xC1) {
        uint8_t value2 = RAM8(0x0190 + y);
        uint8_t a3;
        if ((value2 & 0x80) == 0) {
            a3 = value2 & 0x80;
        } else {
            RAM8(0x0001 + (uint16_t)(sp0 - 4)) = 0;
            uint8_t value3 = RAM8(0x0141 + y);
            uint8_t a1;
            if ((value3 & 0x0C) == 0) {
                a1 = value3;
            } else {
                RAM8(0x0001 + (uint16_t)(sp0 - 4)) = 0x0C;
                a1 = RAM8(0x0141 + y);
            }
            uint8_t a2;
            if ((a1 & 3) == 0) {
                a2 = a1;
            } else {
                RAM8(0x0001 + (uint16_t)(sp0 - 4)) |= 3;
                a2 = RAM8(0x0141 + y);
            }
            uint8_t value7 = RAM8(0x0001 + (uint16_t)(sp0 - 4));
            RAM8(0x0141 + y) = a2 ^ value7;
            a3 = a2 ^ value7;
        }
        a8 = a3;
    } else {
        uint8_t a7;
        if (value != 0x40) {
            a7 = value;
        } else {
            uint8_t value8 = RAM8(0x0190 + y);
            uint8_t a6;
            if ((value8 & 0x80) == 0) {
                a6 = value8 & 0x80;
            } else {
                RAM8(0x0001 + (uint16_t)(sp0 - 4)) = 0;
                uint8_t value9 = RAM8(0x0141 + y);
                uint8_t a4;
                if ((value9 & 0x0C) == 0) {
                    a4 = value9;
                } else {
                    RAM8(0x0001 + (uint16_t)(sp0 - 4)) = 0x0C;
                    a4 = RAM8(0x0141 + y);
                }
                uint8_t a5;
                if ((a4 & 3) == 0) {
                    a5 = a4;
                } else {
                    RAM8(0x0001 + (uint16_t)(sp0 - 4)) |= 3;
                    a5 = RAM8(0x0141 + y);
                }
                uint8_t value13 = RAM8(0x0001 + (uint16_t)(sp0 - 4));
                RAM8(0x0141 + y) = a5 ^ value13;
                a6 = a5 ^ value13;
            }
            a7 = a6;
        }
        a8 = a7;
    }
    RAM8(0x0000 + sp0 - 3) = a8;
    r->a = (r->a & 0x00FF) | (((uint16_t)(sp0 - 4) >> 8) << 8);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC124D7, SOM_RTS, "gen", mirror_confused_actor_command_direction, 0, L_B | L_Y, 4, 1, 0, 67, 35)
