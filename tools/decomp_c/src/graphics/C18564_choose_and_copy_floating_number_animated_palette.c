#include "som_c.h"

/* C18564 choose_and_copy_floating_number_animated_palette   [class B, 116 bytes, 50 instructions]
 * Source: src/rom/choose_and_copy_floating_number_animated_palette.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void choose_and_copy_floating_number_animated_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint8_t value = RAM8(0xE11F + x);
    uint8_t a10;
    bool carry8;
    if (value == 0) {
        uint8_t value2 = RAM8(0xE11C + x);
        uint8_t a3;
        bool carry2;
        if (value2 != 8) {
            a3 = 1;
            carry2 = value2 >= 8;
        } else {
            uint8_t value3 = RAM8(0xE11E + x);
            uint8_t a2;
            bool carry1;
            if (value3 >= 0x80) {
                a2 = 2;
                carry1 = value3 >= 0x80;
            } else {
                uint8_t a1;
                if (value3 >= 0x30) {
                    a1 = 1;
                } else {
                    a1 = 0;
                }
                a2 = a1;
                carry1 = value3 >= 0x30;
            }
            a3 = a2;
            carry2 = carry1;
        }
        a10 = a3;
        carry8 = carry2;
    } else {
        uint8_t a9;
        bool carry7;
        if (value >= 0xE0) {
            a9 = 1;
            carry7 = value >= 0xE0;
        } else {
            uint8_t a8;
            bool carry6;
            if (((value >> 5) ^ 7) >= 3) {
                a8 = (value >> 5) ^ 7;
                carry6 = ((value >> 5) ^ 7) >= 3;
            } else {
                uint8_t a7;
                bool carry5;
                if (((value >> 5) ^ 7) < 3) {
                    a7 = 1;
                    carry5 = ((value >> 5) ^ 7) >= 3;
                } else {
                    uint8_t value4 = RAM8(0xE11C + x);
                    uint8_t a6;
                    bool carry4;
                    if (value4 != 8) {
                        a6 = 1;
                        carry4 = value4 >= 8;
                    } else {
                        uint8_t value5 = RAM8(0xE11E + x);
                        uint8_t a5;
                        bool carry3;
                        if (value5 >= 0x80) {
                            a5 = 2;
                            carry3 = value5 >= 0x80;
                        } else {
                            uint8_t a4;
                            if (value5 >= 0x30) {
                                a4 = 1;
                            } else {
                                a4 = 0;
                            }
                            a5 = a4;
                            carry3 = value5 >= 0x30;
                        }
                        a6 = a5;
                        carry4 = carry3;
                    }
                    a7 = a6;
                    carry5 = carry4;
                }
                a8 = a7;
                carry6 = carry5;
            }
            a9 = a8;
            carry7 = carry6;
        }
        a10 = a9;
        carry8 = carry7;
    }
    BUS8_SET(c, 0x004202, a10 | RAM8(0xE04F + x));
    BUS8_SET(c, 0x004203, 0x0A);
    uint16_t value7 = RAM16(0xE0FA + x);
    uint16_t value8 = BUS16(c, 0x004216);
    uint16_t value9 = BUS16(c, 0xD1F600 + value8);
    RAM16_SET(0x0700 + value7, value9);
    uint16_t value10 = BUS16(c, 0xD1F602 + value8);
    RAM16_SET(0x0702 + value7, value10);
    uint16_t value11 = BUS16(c, 0xD1F604 + value8);
    RAM16_SET(0x0704 + value7, value11);
    uint16_t value12 = BUS16(c, 0xD1F606 + value8);
    RAM16_SET(0x0706 + value7, value12);
    uint16_t value13 = BUS16(c, 0xD1F608 + value8);
    RAM16_SET(0x0708 + value7, value13);
    r->a = value13;
    r->y = value7;
    r->c = carry8;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC18564, SOM_RTS, "gen", choose_and_copy_floating_number_animated_palette, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 116, 50)
