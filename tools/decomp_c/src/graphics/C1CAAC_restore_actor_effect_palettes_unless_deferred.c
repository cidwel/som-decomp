#include "som_c.h"

/* C1CAAC restore_actor_effect_palettes_unless_deferred   [class B, 33 bytes, 14 instructions]
 * Source: src/rom/restore_actor_effect_palettes_unless_deferred.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void restore_actor_effect_palettes_unless_deferred(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    uint8_t value = RAM8(0x005C);
    uint8_t a_hi4;
    uint16_t y4;
    bool carry1;
    if (!(value & 0x80)) {
        uint8_t value2 = RAM8(0xE100 + x);
        uint8_t a_hi1;
        uint16_t y1;
        if (!(value2 & 0x80)) {
            a_hi1 = a_hi;
            y1 = y;
        } else {
            r->v = value & 0x40;
            JSR(c, 0xCABC, 0xC1D8F3); /* restore_actor_cached_fifteen_palette_colors */
            uint16_t a_all = r->a;
            uint16_t y_ret = r->y;
            a_hi1 = a_all >> 8;
            y1 = y_ret;
        }
        a_hi4 = a_hi1;
        y4 = y1;
        carry1 = carry;
    } else {
        uint8_t a_hi3;
        uint16_t y3;
        if (x >= 0x0600) {
            a_hi3 = a_hi;
            y3 = y;
        } else {
            uint8_t value3 = RAM8(0xE100 + x);
            uint8_t a_hi2;
            uint16_t y2;
            if (!(value3 & 0x80)) {
                a_hi2 = a_hi;
                y2 = y;
            } else {
                r->c = x >= 0x0600;
                r->v = value & 0x40;
                JSR(c, 0xCABC, 0xC1D8F3); /* restore_actor_cached_fifteen_palette_colors */
                uint16_t a_all2 = r->a;
                uint16_t y_ret2 = r->y;
                a_hi2 = a_all2 >> 8;
                y2 = y_ret2;
            }
            a_hi3 = a_hi2;
            y3 = y2;
        }
        a_hi4 = a_hi3;
        y4 = y3;
        carry1 = x >= 0x0600;
    }
    uint8_t value4 = RAM8(0xE104 + x);
    uint8_t a_hi5;
    uint16_t x1;
    uint16_t y5;
    bool carry2;
    if (!(value4 & 0x80)) {
        a_hi5 = a_hi4;
        x1 = x;
        y5 = y4;
        carry2 = carry1;
    } else {
        r->a = (a_hi4 << 8) | RAM8(0xE069 + x);
        r->c = carry1;
        r->v = value & 0x40;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0xCAC9, 0xC1859B); /* copy_object_weapon_palette */
        uint16_t a_all3 = r->a;
        uint16_t x_ret = r->x;
        uint16_t y_ret3 = r->y;
        bool carry_ret = r->c;
        a_hi5 = a_all3 >> 8;
        x1 = x_ret;
        y5 = y_ret3;
        carry2 = carry_ret;
    }
    r->a = (a_hi5 << 8) | a;
    r->x = x1;
    r->y = y5;
    r->c = carry2;
    r->v = value & 0x40;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1CAAC, SOM_RTS, "gen", restore_actor_effect_palettes_unless_deferred, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 33, 14)
