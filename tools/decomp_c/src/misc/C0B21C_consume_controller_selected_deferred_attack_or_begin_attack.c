#include "som_c.h"

/* C0B21C consume_controller_selected_deferred_attack_or_begin_attack   [class C, 580 bytes, 251 instructions]
 * Source: src/rom/consume_controller_selected_deferred_attack_or_begin_attack.s
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void consume_controller_selected_deferred_attack_or_begin_attack(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const bool overflow = r->v;
    uint8_t value = RAM8(0xE060 + (((a & 6) << 8) | 0));
    if (value == 0x40) {
        r->a = ((a & 6) << 8) | value;
        r->x = ((a & 6) << 8) | 0;
        r->c = value >= 0x40;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if (RAM8(ACTOR_CHARGE_STAGE + (((a & 6) << 8) | 0)) != 0) {
        RAM8(0x0000) = 0;
        uint8_t value3 = RAM8(0xE060 + (((a & 6) << 8) | 0));
        uint8_t value4 = RAM8(0xE061 + (((a & 6) << 8) | 0));
        uint8_t value5 = RAM8(0xE01C + (((a & 6) << 8) | 0));
        if ((value3 | value4 | value5) == 0) {
            RAM8(0xE030 + (((a & 6) << 8) | 0)) = 0xFF;
            RAM8(0xE01C + (((a & 6) << 8) | 0)) = 0x80;
            RAM8(0xE036 + (((a & 6) << 8) | 0)) = 0;
            RAM8(0xE01D + (((a & 6) << 8) | 0)) = 0;
            RAM8(0xE006 + (((a & 6) << 8) | 0)) = 0;
            RAM8(0xE007 + (((a & 6) << 8) | 0)) = 0;
            uint8_t value6 = RAM8(0x0000);
            RAM8(0x0000) <<= 1;
            uint8_t value7 = RAM8(0x0000);
            r->a = ((a & 6) << 8) | 0;
            r->x = (a & 6) << 8;
            r->c = value6 & 0x80;
            r->z = value7 == 0;
            r->n = value7 & 0x80;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSL(c, 0xB27C, 0x01E40E); GUARD_JSL(c, sp_call, 0xB27C); } /* select_actor_target_and_attack_animation */
            uint16_t a_all = r->a;
            uint16_t x_ret = r->x;
            RAM8(0xE011 + x_ret) = (uint8_t)a_all;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB285, 0xC0B313); GUARD_JSR(c, sp_call, 0xB285); } /* restore_actor_attack_palette_with_saved_bank */
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        r->a = ((a & 6) << 8) | (value3 | value4 | value5);
        r->x = ((a & 6) << 8) | 0;
        r->c = value >= 0x40;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value8 = RAM8(0xE01C + (((a & 6) << 8) | 0));
    if (value8 != 0) {
        r->a = ((a & 6) << 8) | value8;
        r->x = ((a & 6) << 8) | 0;
        r->c = value >= 0x40;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint8_t value9 = RAM8(0xE01A + (((a & 6) << 8) | 0));
    if (value9 == 0) {
        r->a = ((a & 6) << 8) | value9;
        r->x = ((a & 6) << 8) | 0;
        r->c = value >= 0x40;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM8(0xE01A + (((a & 6) << 8) | 0)) = 0;
    uint8_t a_hi1 = a & 6;
    uint16_t x1 = ((a & 6) << 8) | 0;
    bool overflow1 = overflow;
    for (;;) {
        BUS16_SET(c, 0x000A56 + (uint16_t)((((uint8_t)x1 << 8) | (x1 >> 8)) << 3), 0x2817);
        BUS16_SET(c, 0x000A50 + (uint16_t)((((uint8_t)x1 << 8) | (x1 >> 8)) << 3), 0);
        BUS16_SET(c, 0x000A52 + (uint16_t)((((uint8_t)x1 << 8) | (x1 >> 8)) << 3), 0);
        BUS16_SET(c, 0x000A53 + (uint16_t)((((uint8_t)x1 << 8) | (x1 >> 8)) << 3), 0);
        r->a = 0;
        r->x = x1;
        r->y = (uint16_t)((((uint8_t)x1 << 8) | (x1 >> 8)) << 3);
        r->c = (uint16_t)((((uint8_t)x1 << 8) | (x1 >> 8)) << 2) & 0x8000;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0;
        r->dp = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC0B21C, SOM_RTS, "gen", consume_controller_selected_deferred_attack_or_begin_attack, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 1946, 251)
