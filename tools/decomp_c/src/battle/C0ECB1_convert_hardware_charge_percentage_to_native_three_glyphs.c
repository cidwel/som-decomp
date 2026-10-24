#include "som_c.h"

/* C0ECB1 convert_hardware_charge_percentage_to_native_three_glyphs   [class B, 64 bytes, 28 instructions]
 * Source: src/rom/convert_hardware_charge_percentage_to_native_three_glyphs.s
 * Documented in docs/actor-charge-gauge-presentation.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XY.
 */
static void convert_hardware_charge_percentage_to_native_three_glyphs(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x0000) = 0x0B;
    RAM8(0x0001) = 0x0B;
    RAM8(0x0002) = 0x0B;
    uint8_t value = BUS8(c, 0x004214);
    uint8_t a1;
    if ((uint8_t)(0x65 - value) < 0x65) {
        a1 = (uint8_t)(0x65 - value);
    } else {
        a1 = 0x64;
    }
    if (a1 >= 0x0A) {
        r->a = (a_hi << 8) | a1;
        JSR(c, 0xECCF, 0xC0ECF1); /* divide_native_charge_percentage_by_ten */
        uint16_t a_all = r->a;
        uint8_t value2 = BUS8(c, 0x004216);
        RAM8(0x0000) = value2;
        uint8_t value3 = BUS8(c, 0x004214);
        if (value3 >= 0x0A) {
            r->a = (a_all >> 8 << 8) | value3;
            r->mf = 1;
            r->xf = 0;
            JSR(c, 0xECE3, 0xC0ECF1); /* divide_native_charge_percentage_by_ten */
            uint8_t value4 = BUS8(c, 0x004216);
            RAM8(0x0001) = value4;
            uint8_t value5 = BUS8(c, 0x004214);
            RAM8(0x0002) = value5;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        RAM8(0x0001) = value3;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM8(0x0000) = a1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0ECB1, SOM_RTS, "gen", convert_hardware_charge_percentage_to_native_three_glyphs, 0, L_X | L_Y, 1, 1, 0, 64, 28)
