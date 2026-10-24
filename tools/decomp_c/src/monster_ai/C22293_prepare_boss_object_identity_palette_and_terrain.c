#include "som_c.h"

/* C22293 prepare_boss_object_identity_palette_and_terrain   [class B, 118 bytes, 47 instructions]
 * Source: src/rom/prepare_boss_object_identity_palette_and_terrain.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void prepare_boss_object_identity_palette_and_terrain(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0287, x);
    uint16_t value = RAM16(0x0FA6);
    RAM16_SET(0x002B + x, (RAM16(0xC80A + value) & 0x7F) << 1 << 1 << 1 << 1);
    uint16_t value3 = RAM16(0xC80B + value);
    RAM16_SET(0x0032 + x, (value3 & 0x7F) << 1 << 1 << 1 << 1);
    RAM16_SET(0x0072 + x, RAM16(0xC80E + value) & 0x0FFF);
    RAM16_SET(0x0042 + x, RAM16(0x0304));
    RAM16_SET(0x0000 + x, 1);
    RAM16_SET(0x0029 + x, 0);
    RAM16_SET(0x0030 + x, 0);
    RAM16_SET(0x00A5 + x, 0);
    RAM16_SET(0x0022 + x, RAM16(0x0032 + x));
    RAM16_SET(0x0034 + x, 0);
    RAM16_SET(0x0092 + x, 0x3000);
    RAM16_SET(0x0060 + x, 0);
    RAM8(0x0046 + x) = 0;
    RAM8(0x0047 + x) = 0;
    RAM8(0x0074 + x) = 0;
    RAM8(0x0010 + x) = 1;
    uint16_t value7 = RAM16(0x0FA2);
    r->a = value7;
    r->y = value;
    r->c = (value3 & 0x7F) << 1 << 1 << 1 & 0x8000;
    r->z = value7 == 0;
    r->n = value7 & 0x8000;
    { const uint16_t sp_call = r->sp; JSL(c, 0x22FA, 0xC0003F); GUARD_JSL(c, sp_call, 0x22FA); } /* change_actor_identity_public_jump */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    if (m_ret) {
        uint8_t value8 = BUS8_RDP(c, (db_ret << 0x10) + 0x0FA2);
        if (x_ret) {
            uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->a = (a_all >> 8 << 8) | value8;
            r->x = value9;
            r->y = (uint8_t)y_ret;
            r->z = value9 == 0;
            r->n = value9 & 0x80;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2302, 0xC22309); GUARD_JSR(c, sp_call, 0x2302); } /* assign_boss_palette_list */
            uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->x = value10;
            r->z = value10 == 0;
            r->n = value10 & 0x80;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2307, 0xC215B7); GUARD_JSR(c, sp_call, 0x2307); } /* prepare_boss_object_terrain */
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->a = (a_all >> 8 << 8) | value8;
            r->x = value11;
            r->z = value11 == 0;
            r->n = value11 & 0x8000;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2302, 0xC22309); GUARD_JSR(c, sp_call, 0x2302); } /* assign_boss_palette_list */
            uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->x = value12;
            r->z = value12 == 0;
            r->n = value12 & 0x8000;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2307, 0xC215B7); GUARD_JSR(c, sp_call, 0x2307); } /* prepare_boss_object_terrain */
            r->xf = 0;
            RETURN_RTS(c);
        }
    } else {
        uint16_t value13 = BUS16_RDP(c, (db_ret << 0x10) + 0x0FA2);
        if (x_ret) {
            uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->a = value13;
            r->x = value14;
            r->y = (uint8_t)y_ret;
            r->z = value14 == 0;
            r->n = value14 & 0x80;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2302, 0xC22309); GUARD_JSR(c, sp_call, 0x2302); } /* assign_boss_palette_list */
            uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->x = value15;
            r->z = value15 == 0;
            r->n = value15 & 0x80;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2307, 0xC215B7); GUARD_JSR(c, sp_call, 0x2307); } /* prepare_boss_object_terrain */
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->a = value13;
            r->x = value16;
            r->z = value16 == 0;
            r->n = value16 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2302, 0xC22309); GUARD_JSR(c, sp_call, 0x2302); } /* assign_boss_palette_list */
            uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
            r->x = value17;
            r->z = value17 == 0;
            r->n = value17 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2307, 0xC215B7); GUARD_JSR(c, sp_call, 0x2307); } /* prepare_boss_object_terrain */
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0xC22293, SOM_RTS, "gen", prepare_boss_object_identity_palette_and_terrain, 0, 0, 1, 0, 0, 118, 47)
