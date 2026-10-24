#include "som_c.h"

/* C00E8D load_eight_native_boot_settings_presets_from_real_tables   [class B, 50 bytes, 25 instructions]
 * Source: src/rom/load_eight_native_boot_settings_presets_from_real_tables.s
 * Documented in docs/ui-native-boot-menu-workspace.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BY.
 */
static void load_eight_native_boot_settings_presets_from_real_tables(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0xA175) = 8;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    uint16_t y1 = 0;
    do {
        uint8_t value = BUS8(c, 0xC77161 + x1);
        RAM8(0xA173) = (uint8_t)(value << 1);
        uint16_t value3 = BUS16(c, 0xD2DB82 + (uint8_t)((uint8_t)(value << 2) + RAM8(0xA173)));
        RAM16_SET(0xA23E + y1, value3);
        RAM8(0xA175)--;
        a_hi1 = value3 >> 8;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 + 2);
    } while (RAM8(0xA175) != 0);
    r->a = (a_hi1 << 8) | a;
    r->y = y1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC00E8D, SOM_RTS, "gen", load_eight_native_boot_settings_presets_from_real_tables, 0, L_B | L_Y, 2, 1, 0, 50, 25)
