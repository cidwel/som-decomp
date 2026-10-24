#include "som_c.h"

/* C2AFE3 clear_actor_status_four_and_refresh_live_weapon_graphics   [class B, 59 bytes, 26 instructions]
 * Source: src/rom/clear_actor_status_four_and_refresh_live_weapon_graphics.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABYCV.
 */
static void clear_actor_status_four_and_refresh_live_weapon_graphics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    uint8_t value = RAM8(0xE000 + x);
    if (value == 0) {
        SET_A8(r, value);
        RETURN_RTS(c);
    }
    if (value & 0x80) {
        SET_A8(r, value);
        RETURN_RTS(c);
    }
    uint8_t value2 = RAM8(ACTOR_STATUS_HIGH + x);
    if ((value2 & 0xC1) == 0) {
        if ((value2 & 4) == 0) {
            SET_A8(r, value2);
            RETURN_RTS(c);
        }
        RAM8(ACTOR_STATUS_HIGH + x) = value2 ^ 4;
        uint8_t value3 = RAM8(0xE060 + x);
        if (value3 != 0) {
            SET_A8(r, value3);
            RETURN_RTS(c);
        }
        uint8_t value4 = RAM8(0xE01C + x);
        bool carry1;
        if (value4 == 0) {
            carry1 = carry;
        } else {
            if (value4 != 0x20) {
                RAM8(0xE01C + x) = 0;
                RAM8(0xE011 + x) = 0;
            }
            carry1 = value4 >= 0x20;
        }
        RAM8(0xE030 + x) = 0xFF;
        RAM8(0x0000 + sp0) = x >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
        r->a = (a_hi << 8) | 0xFF;
        r->c = carry1;
        r->z = 0;
        r->n = 1;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSL(c, 0xB01B, 0x00E9F4); GUARD_JSL(c, sp_call, 0xB01B); } /* refresh_actor_weapon_graphics_long */
        r->sp += 2;
        bool x_ret = r->xf;
        if (x_ret) {
            c->fail = 3;
            return;
        } else {
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
    SET_A8(r, value2);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2AFE3, SOM_RTS, "gen", clear_actor_status_four_and_refresh_live_weapon_graphics, 0, L_A | L_B | L_Y | L_C | L_V, 2, 1, 0, 59, 26)
