#include "som_c.h"

/* C07108 select_native_menu_ring_hero_and_shop_geometry   [class B, 130 bytes, 58 instructions]
 * Source: src/rom/select_native_menu_ring_hero_and_shop_geometry.s
 * Documented in docs/event-menu-ring-list-geometry.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCZV.
 */
static void select_native_menu_ring_hero_and_shop_geometry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t ring_owner = RAM16(RING_OWNER);
    uint16_t y1;
    if ((((ring_owner & 0x0F) << 8) | 0) << 1 < 0x0400) {
        y1 = 0xFFEB;
    } else {
        y1 = 0xFFEE;
    }
    r->a = (((ring_owner & 0x0F) << 8) | 0) << 1;
    r->x = (((ring_owner & 0x0F) << 8) | 0) << 1;
    r->y = y1;
    JSR(c, 0x7120, 0xC07134); /* set_native_menu_ring_center_from_hero_position_and_offset */
    uint16_t y_ret = r->y;
    uint16_t value = RAM16(0x1847);
    uint8_t a_hi2;
    uint16_t y3;
    if ((value & 0xFF) == 0) {
        a_hi2 = 0;
        y3 = y_ret;
    } else {
        uint8_t a_hi1;
        uint16_t y2;
        if ((uint16_t)((value & 0xFF) - 1) == 0) {
            uint16_t value2 = RAM16(0x183E);
            RAM16_SET(0x1844, (uint16_t)(value2 + 0xE180));
            r->a = (uint16_t)(value2 + 0xE180);
            r->x = value2;
            r->y = 0xFFCF;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x715C, 0xC07134); /* set_native_menu_ring_center_from_hero_position_and_offset */
            uint16_t a_all2 = r->a;
            uint16_t y_ret2 = r->y;
            a_hi1 = a_all2 >> 8;
            y2 = y_ret2;
        } else {
            r->a = (uint16_t)((value & 0xFF) - 1);
            r->y = 0xFFF8;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x7131, 0xC07134); /* set_native_menu_ring_center_from_hero_position_and_offset */
            uint16_t a_all3 = r->a;
            uint16_t y_ret3 = r->y;
            a_hi1 = a_all3 >> 8;
            y2 = y_ret3;
        }
        a_hi2 = a_hi1;
        y3 = y2;
    }
    uint8_t a_hi3 = a_hi2;
    uint16_t x1 = 0;
    for (;;) {
        uint16_t value3 = BUS16(c, 0x1880 + x1);
        if (value3 != 0xFFFF) {
            a_hi3 = value3 >> 8;
            x1 = (uint16_t)(x1 + 2);
            continue;
        }
        a_hi3 = value3 >> 8;
        break;
    }
    RAM8(RING_ENTRY_COUNT) = (uint8_t)(x1 >> 1);
    uint16_t value4 = BUS16(c, 0xD8FF18 + (uint16_t)((uint16_t)(((x1 >> 1) & 0xFF) - 1) << 1));
    RAM16_SET(0x180E, value4);
    uint16_t ring_owner2 = RAM16(RING_OWNER);
    RAM16_SET(0x1849, (((uint8_t)((ring_owner2 & 0xFF) << 1) << 8) | ((ring_owner2 & 0xFF) << 1 >> 8)) & 0x0600);
    uint16_t value5 = RAM16(0x1880);
    uint8_t a_hi4;
    bool carry1;
    bool zero1;
    bool overflow1;
    if ((uint16_t)(value5 - 0xFFFF) == 0) {
        a_hi4 = (uint16_t)(value5 - 0xFFFF) >> 8;
        carry1 = value5 >= 0xFFFF;
        zero1 = (uint16_t)(value5 - 0xFFFF) == 0;
        overflow1 = ((value5 ^ 0xFFFF) & (value5 ^ (uint16_t)(value5 - 0xFFFF)) & 0x8000) != 0;
    } else {
        uint16_t value6 = BUS16(c, 0xD8FF16);
        a_hi4 = (uint16_t)(value5 - value6) >> 8;
        carry1 = value5 >= value6;
        zero1 = (uint16_t)(value5 - value6) == 0;
        overflow1 = ((value5 ^ value6) & (value5 ^ (uint16_t)(value5 - value6)) & 0x8000) != 0;
    }
    r->a = (a_hi4 << 8) | (uint8_t)a;
    r->x = (uint16_t)((uint16_t)(((x1 >> 1) & 0xFF) - 1) << 1);
    r->y = y3;
    r->c = carry1;
    r->z = zero1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC07108, SOM_RTS, "hand", select_native_menu_ring_hero_and_shop_geometry, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 0, 0, 154, 58)
