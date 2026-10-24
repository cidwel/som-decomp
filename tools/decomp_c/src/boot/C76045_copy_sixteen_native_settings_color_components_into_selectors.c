#include "som_c.h"

/* C76045 copy_sixteen_native_settings_color_components_into_selectors   [class A, 18 bytes, 10 instructions]
 * Source: src/rom/copy_sixteen_native_settings_color_components_into_selectors.s
 * Documented in docs/ui-native-settings-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void copy_sixteen_native_settings_color_components_into_selectors(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t a1 = 0x10;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0;
    for (;;) {
        uint8_t value = RAM8(0xA23E + x1);
        RAM8(0xA136 + x1) = value;
        a1 = (uint8_t)(a1 - 1);
        a_hi1 = value;
        x1 = (uint16_t)(x1 + 1);
        if (!(a1 != 0)) break;
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76045, SOM_RTS, "gen", copy_sixteen_native_settings_color_components_into_selectors, 0, 0, 1, 1, 0, 18, 10)
