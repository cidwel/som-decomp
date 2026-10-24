#include "som_c.h"

/* C1CA6C clear_actor_movement_charge_and_palette_effects   [class B, 64 bytes, 25 instructions]
 * Source: src/rom/clear_actor_movement_charge_and_palette_effects.s
 * Documented in docs/rom-combat.md
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void clear_actor_movement_charge_and_palette_effects(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    uint8_t value = RAM8(0x005C);
    if (!(value & 0x80)) {
        uint8_t value2 = RAM8(0xE01C + x);
        uint8_t a_hi1;
        bool carry1;
        bool overflow1;
        if (!(value2 & 0x80)) {
            a_hi1 = a >> 8;
            carry1 = carry;
            overflow1 = value & 0x40;
        } else {
            r->a = (a >> 8 << 8) | value2;
            r->mf = 1;
            JSR(c, 0xCA85, 0xC1CACD); /* cancel_actor_charge_and_start_weapon_gauge */
            uint16_t a_all = r->a;
            bool carry_ret = r->c;
            bool overflow_ret = r->v;
            a_hi1 = a_all >> 8;
            carry1 = carry_ret;
            overflow1 = overflow_ret;
        }
        uint8_t value3 = RAM8(0xE01A + x);
        uint8_t value4 = RAM8(0xE01B + x);
        uint8_t a1;
        uint8_t a_hi2;
        bool carry2;
        bool overflow2;
        if ((value3 | value4) == 0) {
            a1 = value3 | value4;
            a_hi2 = a_hi1;
            carry2 = carry1;
            overflow2 = overflow1;
        } else {
            r->a = (a_hi1 << 8) | (value3 | value4);
            r->mf = 1;
            r->xf = 0;
            JSR(c, 0xCA90, 0xC1CACD); /* cancel_actor_charge_and_start_weapon_gauge */
            uint16_t a_all2 = r->a;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            a1 = (uint8_t)a_all2;
            a_hi2 = a_all2 >> 8;
            carry2 = carry_ret2;
            overflow2 = overflow_ret2;
        }
        r->a = (a_hi2 << 8) | a1;
        r->c = carry2;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0xCA93, 0xC1CAAC); /* restore_actor_effect_palettes_unless_deferred */
        uint16_t x_ret = r->x;
        RAM8(0xE008 + x_ret) = 0;
        RAM8(0xE041 + x_ret) = 0;
        RAM8(0xE006 + x_ret) = 0;
        RAM8(0xE007 + x_ret) = 0;
        RAM8(0xE013 + x_ret) = 0;
        RAM8(0xE067 + x_ret) = 0;
        RAM8(0xE030 + x_ret) = 0xFF;
        SET_A8(r, 0xFF);
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if (x < 0x0600) {
        uint8_t value5 = RAM8(0xE01C + x);
        uint8_t a_hi3;
        bool carry3;
        bool overflow3;
        if (!(value5 & 0x80)) {
            a_hi3 = a >> 8;
            carry3 = x >= 0x0600;
            overflow3 = value & 0x40;
        } else {
            r->a = (a >> 8 << 8) | value5;
            r->mf = 1;
            JSR(c, 0xCA85, 0xC1CACD); /* cancel_actor_charge_and_start_weapon_gauge */
            uint16_t a_all4 = r->a;
            bool carry_ret4 = r->c;
            bool overflow_ret4 = r->v;
            a_hi3 = a_all4 >> 8;
            carry3 = carry_ret4;
            overflow3 = overflow_ret4;
        }
        uint8_t value6 = RAM8(0xE01A + x);
        uint8_t value7 = RAM8(0xE01B + x);
        uint8_t a2;
        uint8_t a_hi4;
        bool carry4;
        bool overflow4;
        if ((value6 | value7) == 0) {
            a2 = value6 | value7;
            a_hi4 = a_hi3;
            carry4 = carry3;
            overflow4 = overflow3;
        } else {
            r->a = (a_hi3 << 8) | (value6 | value7);
            r->mf = 1;
            r->xf = 0;
            JSR(c, 0xCA90, 0xC1CACD); /* cancel_actor_charge_and_start_weapon_gauge */
            uint16_t a_all5 = r->a;
            bool carry_ret5 = r->c;
            bool overflow_ret5 = r->v;
            a2 = (uint8_t)a_all5;
            a_hi4 = a_all5 >> 8;
            carry4 = carry_ret5;
            overflow4 = overflow_ret5;
        }
        r->a = (a_hi4 << 8) | a2;
        r->c = carry4;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0xCA93, 0xC1CAAC); /* restore_actor_effect_palettes_unless_deferred */
        uint16_t x_ret2 = r->x;
        RAM8(0xE008 + x_ret2) = 0;
        RAM8(0xE041 + x_ret2) = 0;
        RAM8(0xE006 + x_ret2) = 0;
        RAM8(0xE007 + x_ret2) = 0;
        RAM8(0xE013 + x_ret2) = 0;
        RAM8(0xE067 + x_ret2) = 0;
        RAM8(0xE030 + x_ret2) = 0xFF;
        SET_A8(r, 0xFF);
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM8(0xE104 + x) = 0;
    RAM8(0xE100 + x) = 0;
    r->c = x >= 0x0600;
    r->v = value & 0x40;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1CA6C, SOM_RTS, "gen", clear_actor_movement_charge_and_palette_effects, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, -1, 0, 64, 25)
