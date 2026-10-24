#include "som_c.h"

/* D0DA3D place_one_eligible_active_hero_shop_marker   [class B, 35 bytes, 16 instructions]
 * Source: src/rom/place_one_eligible_active_hero_shop_marker.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: Y.
 */
static void place_one_eligible_active_hero_shop_marker(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool zero = r->z;
    uint8_t a_hi2;
    if (zero) {
        a_hi2 = a >> 8;
    } else {
        uint16_t value = RAM16(0x0000 + x);
        uint8_t a_hi1;
        if ((value & 0xFF) != 1) {
            a_hi1 = 0;
        } else {
            uint16_t value2 = RAM16(0x1820);
            BUS16_SET(c, 0x000000 + y, value2);
            a_hi1 = value2 >> 8;
        }
        a_hi2 = a_hi1;
    }
    RAM16_SET(0x1820, (uint16_t)(RAM16(0x1820) + 0x0A));
    r->y = (uint16_t)(y + 4);
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0DA3D, SOM_RTS, "gen", place_one_eligible_active_hero_shop_marker, 0, L_Y, 1, 0, 0, 35, 16)
