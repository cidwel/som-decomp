#include "som_c.h"

/* C7681F publish_native_status_bar_full_tiles_and_fractional_tail   [class D, 46 bytes, 23 instructions]
 * Source: src/rom/publish_native_status_bar_full_tiles_and_fractional_tail.s
 * Documented in docs/ui-native-party-status-page.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: nothing.
 */
static void publish_native_status_bar_full_tiles_and_fractional_tail(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    if (y != 0) {
        uint16_t y1 = y;
        for (;;) {
            BUS16_SET(c, 0x002118, x);
            y1 = (uint16_t)(y1 - 1);
            if (!(y1 != 0)) break;
        }
    }
    if (a != 0) {
        RAM16_SET(0xA173, (uint16_t)(a << 1));
        uint16_t value = RAM16(0x19FE);
        BUS16_SET(c, 0x002118, (uint16_t)((uint16_t)((uint16_t)((((uint8_t)((value & 0xFF) + 3) << 8) | ((value & 0xFF) + 3 >> 8)) << 2) + RAM16(0xA173)) + 0x2030));
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7681F, SOM_RTS, "gen", publish_native_status_bar_full_tiles_and_fractional_tail, 0, 0, 2, 0, 0, 46, 23)
