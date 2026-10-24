#include "som_c.h"

/* C7602B snapshot_native_settings_selector_and_eight_icon_variants   [class A, 26 bytes, 11 instructions]
 * Source: src/rom/snapshot_native_settings_selector_and_eight_icon_variants.s
 * Documented in docs/ui-native-settings-page.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void snapshot_native_settings_selector_and_eight_icon_variants(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0xA24E);
    RAM8(0xA222) = value;
    r->a = (a_hi << 8) | value;
    JSR(c, 0x6033, 0xC76045); /* copy_sixteen_native_settings_color_components_into_selectors */
    uint16_t a_all = r->a;
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = 0;
    uint16_t y1 = 8;
    for (;;) {
        RAM8(0xA223 + x1) = RAM8(0xA24F + x1);
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7602B, SOM_RTS, "gen", snapshot_native_settings_selector_and_eight_icon_variants, 0, 0, 1, 1, 0, 26, 11)
