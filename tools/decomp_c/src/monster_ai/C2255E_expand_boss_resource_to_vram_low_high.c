#include "som_c.h"

/* C2255E expand_boss_resource_to_vram_low_high   [class D, 79 bytes, 43 instructions]
 * Source: src/rom/expand_boss_resource_to_vram_low_high.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void expand_boss_resource_to_vram_low_high(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RAM16_SET(0x0270, 0);
    uint16_t value = RAM16(0x0268);
    RAM16_SET(0x0268, (uint16_t)(value + 7) >> 3);
    uint8_t a_hi1 = (uint16_t)(value + 7) >> 3 >> 8;
    do {
        uint16_t value2;
        BUS16_OK(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279), value2);
        RAM16_SET(0x026E, ((uint8_t)value2 << 8) | (value2 >> 8));
        RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) + 1));
        uint8_t a_hi2 = (uint8_t)value2;
        uint8_t x1 = 8;
        for (;;) {
            uint16_t value3 = RAM16(0x026E);
            RAM16_SET(0x026E, (uint16_t)(RAM16(0x026E) << 1));
            uint8_t a1;
            uint8_t a_hi3;
            if (!(value3 & 0x8000)) {
                uint16_t value4 = RAM16(0x026C);
                a1 = (uint8_t)value4;
                a_hi3 = value4 >> 8;
            } else {
                uint16_t value5;
                BUS16_OK(c, (RAM8(0x027B) << 0x10) + RAM16(0x0279), value5);
                RAM16_SET(0x0279, (uint16_t)(RAM16(0x0279) + 1));
                a1 = (uint8_t)value5;
                a_hi3 = value5 >> 8;
            }
            RAM8(0x026C) = RAM8(0x026A);
            RAM16_SET(0x026A, (a_hi3 << 8) | a1);
            uint16_t value7 = RAM16(0x0270);
            RAM16_SET(0x0270, value7 ^ 1);
            if ((value7 ^ 1) == 0) {
                BUS8_SET(c, 0x002119, RAM8(0x026A));
            } else {
                BUS8_SET(c, 0x002118, RAM8(0x026A));
            }
            a_hi2 = (value7 ^ 1) >> 8;
            x1 = (uint8_t)(x1 - 1);
            if (!(x1 != 0)) break;
        }
        RAM16_SET(0x0268, (uint16_t)(RAM16(0x0268) - 1));
        a_hi1 = a_hi2;
    } while (RAM16(0x0268) != 0);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2255E, SOM_RTS, "hand", expand_boss_resource_to_vram_low_high, 0, 0, 2, 0, 0, 79, 43)
