#include "som_c.h"

/* C050CA select_physical_element_and_expire_saber   [class B, 79 bytes, 37 instructions]
 * Source: src/rom/select_physical_element_and_expire_saber.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void select_physical_element_and_expire_saber(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint16_t value = RAM16(ACTOR_WEAPON_MASK + x);
    uint16_t value2 = RAM16(0xE1A2 + x);
    bool overflow1;
    if ((value & value2) == 0) {
        uint16_t value3 = RAM16(0xE1A0 + x);
        if ((value & value3) == 0) {
            RAM8(0x038F) = 2;
        } else {
            RAM8(0x038F) = 4;
        }
        overflow1 = value3 & 0x4000;
    } else {
        RAM8(0x038F) = 1;
        overflow1 = value2 & 0x4000;
    }
    uint8_t value4 = RAM8(ACTOR_SABER_HITS_LEFT + y);
    if (value4 == 0) {
        r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
        r->v = overflow1;
        RETURN_RTS(c);
    }
    RAM8(ACTOR_SABER_HITS_LEFT + y) = (uint8_t)(value4 - 1);
    if ((uint8_t)(value4 - 1) == 0) {
        uint8_t value5 = RAM8(ACTOR_SABER_AND_CRIT_COUNTER + y);
        RAM8(ACTOR_SABER_AND_CRIT_COUNTER + y) = value5 & 0xF0;
        RAM8(0x0000 + sp0) = y >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)y;
        RAM8(0x0000 + sp0 - 2) = x >> 8;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)x;
        r->a = value >> 8 << 8 | (value5 & 0xF0);
        r->x = y;
        r->z = y == 0;
        r->n = y & 0x8000;
        r->v = overflow1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x5109, 0xC04530); GUARD_JSL(c, sp_call, 0x5109); } /* rebuild_actor_attributes_native */
        r->sp += 4;
        uint8_t db_ret = r->db;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0x510D, 0xC058B9); GUARD_JSL(c, sp_call, 0x510D); } /* enqueue_actor_buff_expiration_notice */
        r->sp += 4;
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        if (x_ret3) {
            uint8_t value6 = RAM8(0x0000 + sp0 - 3);
            uint8_t value7 = RAM8(0x0000 + sp0 - 2);
            uint8_t value8 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1FA + value7);
            BUS8_SET(c, (db_ret << 0x10) + 0xE1FA + value7, value8 | 4);
            uint8_t value9 = RAM8(0x0000 + sp0 - 1);
            uint8_t value10 = RAM8(0x0000 + sp0);
            r->a = (a_all2 >> 8 << 8) | (value8 | 4);
            r->x = value6;
            r->y = value7;
            r->z = (value8 | 4) == 0;
            r->n = (value8 | 4) & 0x80;
            r->mf = 1;
            r->xf = 1;
            TAIL_CALL_DYN(c, 0xC00000 | (uint16_t)(((value10 << 8) | value9) + 1), SOM_RTS); /* jump through a pushed address */
        } else {
            uint8_t value11 = RAM8(0x0000 + sp0 - 3);
            uint8_t value12 = RAM8(0x0000 + sp0 - 2);
            uint8_t value13 = RAM8(0x0000 + sp0 - 1);
            uint8_t value14 = RAM8(0x0000 + sp0);
            uint8_t value15 = BUS8_RDP(c, (db_ret << 0x10) + 0xE1FA + ((value14 << 8) | value13));
            BUS8_SET(c, (db_ret << 0x10) + 0xE1FA + ((value14 << 8) | value13), value15 | 4);
            r->x = (value12 << 8) | value11;
            r->y = (value14 << 8) | value13;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
    r->a = (r->a & 0x00FF) | ((value >> 8) << 8);
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC050CA, SOM_RTS, "gen", select_physical_element_and_expire_saber, SOM_UNWINDS, L_B | L_X | L_Y | L_C | L_V, 4, 1, 0, 79, 37)
