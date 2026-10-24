#include "som_c.h"

/* C23CE8 scan_projectile_collision_and_mark_parent_target_contacts   [class B, 76 bytes, 36 instructions]
 * Source: src/rom/scan_projectile_collision_and_mark_parent_target_contacts.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void scan_projectile_collision_and_mark_parent_target_contacts(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x3CEA, 0xC205BF); /* scan_three_party_collision_targets_for_boss */
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    if (!carry_ret) {
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value = RAM16(0x00B0 + x_ret);
    uint16_t value2 = RAM16(0x0224);
    uint8_t value3 = BUS8(c, 0xC205F0 + value2);
    uint8_t value4 = RAM8(0x005A + value);
    if ((value3 & value4) != 0) {
        r->x = value2;
        r->y = value;
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value5 = BUS8(c, 0xC205F0 + value2);
    RAM8(0x005A + value) = value5 | value4;
    uint16_t value6 = RAM16(0x0224);
    uint16_t value8 = RAM16(0x00B0 + RAM16(0x0287));
    uint16_t value9 = BUS16(c, 0xC205F0 + (((uint8_t)((uint16_t)(value8 - 0xE600) >> 1) << 8) | ((uint16_t)(value8 - 0xE600) >> 1 >> 8)));
    uint8_t value10 = RAM8(0x0059 + (uint16_t)((uint16_t)((((uint8_t)value6 << 8) | (value6 >> 8)) << 1) + 0xE000));
    RAM8(0x0059 + (uint16_t)((uint16_t)((((uint8_t)value6 << 8) | (value6 >> 8)) << 1) + 0xE000)) = (uint8_t)value9 | value10;
    uint16_t value11 = RAM16(0x0287);
    r->a = (value9 >> 8 << 8) | ((uint8_t)value9 | value10);
    r->x = value11;
    r->y = (uint16_t)((uint16_t)((((uint8_t)value6 << 8) | (value6 >> 8)) << 1) + 0xE000);
    r->c = 1;
    r->v = ((value8 ^ 0xE600) & (value8 ^ (uint16_t)(value8 - 0xE600)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23CE8, SOM_RTS, "gen", scan_projectile_collision_and_mark_parent_target_contacts, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 76, 36)
