#include "som_c.h"

/* C24D4C update_body_terminal_tiles_or_deactivate_after_seven_ticks   [class B, 95 bytes, 47 instructions]
 * Source: src/rom/update_body_terminal_tiles_or_deactivate_after_seven_ticks.s
 * Documented in docs/boss-native54-body.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void update_body_terminal_tiles_or_deactivate_after_seven_ticks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const bool overflow = r->v;
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(OBJECT_AGE + battle_defence_work);
    if (value >= 7) {
        RAM16_SET(0x0000 + battle_defence_work, 0);
        uint8_t value2 = RAM8(0x0380);
        RAM8(0x0380) = value2 & 0x7F;
        r->a = value >> 8 << 8 | (value2 & 0x7F);
        r->x = battle_defence_work;
        r->c = 1;
        r->z = (value2 & 0x7F) == 0;
        r->n = value2 & 0x7F & 0x80;
        RETURN_RTS(c);
    }
    uint16_t battle_damage = RAM16(BATTLE_DAMAGE);
    uint16_t value3 = RAM16(0x0000 + battle_damage);
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t x2;
    uint16_t y2;
    bool zero2;
    bool negative2;
    bool overflow2;
    if ((value3 & 0xFF) == 0) {
        a2 = value3 & 0xFF;
        a_hi2 = 0;
        x2 = (uint16_t)(value << 1);
        y2 = battle_damage;
        zero2 = (value3 & 0xFF) == 0;
        negative2 = value3 & 0xFF & 0x8000;
        overflow2 = overflow;
    } else {
        RAM16_SET(0x0395, value3 & 0xFF);
        RAM8(0x0000 + sp0) = (uint16_t)(battle_damage + 3) >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)(battle_damage + 3);
        uint16_t value4 = BUS16(c, 0xC24DAB + (uint16_t)(value << 1));
        RAM16_SET(0x0397, value4);
        r->a = value4 & 0x01FF;
        r->y = (uint8_t)(battle_damage + 3);
        r->c = battle_damage + 3 > 0xFFFF;
        r->v = ((battle_damage ^ (uint16_t)(battle_damage + 3)) & ((uint16_t)(battle_damage + 3) ^ 3) & 0x8000) != 0;
        r->xf = 1;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSR(c, 0x4D78, 0xC21B03); GUARD_JSR(c, sp_call, 0x4D78); } /* ensure_regular_boss_animation_graphic_cached */
        r->sp += 2;
        bool overflow_ret = r->v;
        uint16_t value5 = RAM16(0x0397);
        RAM16_SET(0x0397, (value5 & 0xFE00) | 0x0A);
        uint8_t value6 = RAM8(0x0000 + sp0 - 1);
        uint8_t value7 = RAM8(0x0000 + sp0);
        uint16_t value8 = RAM16(0x03C5);
        uint8_t a1 = (uint8_t)((value5 & 0xFE00) | 0x0A);
        uint8_t a_hi1 = ((value5 & 0xFE00) | 0x0A) >> 8;
        uint16_t x1 = value8;
        uint16_t y1 = (value7 << 8) | value6;
        bool zero1 = value8 == 0;
        bool negative1 = value8 & 0x8000;
        bool overflow1 = overflow_ret;
        for (;;) {
            RAM16_SET(0x0000 + y1, RAM16(0x0397));
            uint16_t value10 = RAM16(0x0395);
            uint8_t a1_next = (uint8_t)(y1 + 4);
            uint8_t a_hi1_next = (uint16_t)(y1 + 4) >> 8;
            uint16_t x1_next = (uint16_t)(x1 + 1);
            uint16_t y1_next = (uint16_t)(y1 + 4);
            bool zero1_next = (uint16_t)(x1 + 1) == value10;
            bool negative1_next = (uint16_t)((uint16_t)(x1 + 1) - value10) & 0x8000;
            bool overflow1_next = ((y1 ^ (uint16_t)(y1 + 4)) & ((uint16_t)(y1 + 4) ^ 4) & 0x8000) != 0;
            a1 = a1_next;
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            y1 = y1_next;
            zero1 = zero1_next;
            negative1 = negative1_next;
            overflow1 = overflow1_next;
            if (!(x1 < value10)) break;
        }
        a2 = a1;
        a_hi2 = a_hi1;
        x2 = x1;
        y2 = y1;
        zero2 = zero1;
        negative2 = negative1;
        overflow2 = overflow1;
    }
    r->a = (a_hi2 << 8) | a2;
    r->x = x2;
    r->y = y2;
    r->c = 0;
    r->z = zero2;
    r->n = negative2;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24D4C, SOM_RTS, "gen", update_body_terminal_tiles_or_deactivate_after_seven_ticks, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 95, 47)
