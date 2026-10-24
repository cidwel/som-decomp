#include "som_c.h"

/* C03C88 expire_party_mana_weapon_and_rebuild_attributes   [class B, 29 bytes, 10 instructions]
 * Source: src/rom/expire_party_mana_weapon_and_rebuild_attributes.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void expire_party_mana_weapon_and_rebuild_attributes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = RAM8(0xCC77);
    RAM8(0xE1E8) = value;
    r->a = (a_hi << 8) | value;
    r->z = value == 0;
    r->n = value & 0x80;
    { const uint16_t sp_call = r->sp; JSL(c, 0x3C91, 0xC8E5FB); GUARD_JSL(c, sp_call, 0x3C91); } /* select_actor_status_attack_row_long */
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    uint8_t value2 = RAM8(0xE1FA + x_ret2);
    RAM8(0xE1FA + x_ret2) = value2 | 4;
    r->a = (a_all >> 8 << 8) | (value2 | 4);
    r->z = (value2 | 4) == 0;
    r->n = (value2 | 4) & 0x80;
    { const uint16_t sp_call = r->sp; JSL(c, 0x3C9D, 0xC04530); GUARD_JSL(c, sp_call, 0x3C9D); } /* rebuild_actor_attributes_native */
    uint16_t dp_ret = r->dp;
    { const uint16_t sp_call = r->sp; JSL(c, 0x3CA1, 0xC058B9); GUARD_JSL(c, sp_call, 0x3CA1); } /* enqueue_actor_buff_expiration_notice */
    bool x_ret5 = r->xf;
    uint16_t y_ret3 = r->y;
    if (x_ret5) {
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x85));
        r->x = value3;
        r->y = (uint8_t)y_ret3;
        r->mf = 1;
        r->xf = 1;
        RETURN_RTS(c);
    } else {
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x85));
        r->x = value4;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC03C88, SOM_RTS, "gen", expire_party_mana_weapon_and_rebuild_attributes, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 29, 10)
