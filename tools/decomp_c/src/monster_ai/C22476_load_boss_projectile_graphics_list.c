#include "som_c.h"

/* C22476 load_boss_projectile_graphics_list   [class B, 77 bytes, 37 instructions]
 * Source: src/rom/load_boss_projectile_graphics_list.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: YV.
 */
static void load_boss_projectile_graphics_list(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = BUS16(c, 0xD0BAC0 + a);
    BUS16_SET(c, (uint16_t)(dp + 0x46), (value & 0xFF) << 1 << 1);
    uint8_t a_hi1 = (value & 0xFF) << 1 << 1 >> 8;
    uint16_t y1 = y;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + 0x46));
        uint16_t value3 = BUS16(c, 0xD0BADF + value2);
        if ((value3 & 0xFF) != 0xFF) {
            uint16_t value4 = BUS16(c, 0xD0BB0C + ((value3 & 0xFF) << 1));
            BUS16_SET(c, (uint16_t)(dp + 0x79), value4);
            BUS16_SET(c, (uint16_t)(dp + 0x68), 0x0400);
            uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp + 0x46));
            BUS16_SET(c, (uint16_t)(dp + 0x7C), ((((value5 & 3) << 8) | 0) << 1 << 1) + 0x7000);
            BUS8_SET(c, (uint16_t)(dp + 0x7B), 0xDB);
            BUS8_SET(c, (uint16_t)(dp + 0x7E), 0x7F);
            BUS16_SET(c, (uint16_t)(dp + 0x6A), 0);
            BUS16_SET(c, (uint16_t)(dp + 0x6C), 0);
            r->a = (((((value5 & 3) << 8) | 0) << 1 << 1) + 0x7000 >> 8 << 8) | 0x7F;
            r->x = (value3 & 0xFF) << 1;
            r->y = y1;
            r->c = ((((value5 & 3) << 8) | 0) << 1 << 1) + 0x7000 > 0xFFFF;
            r->z = 0;
            r->n = 0;
            r->v = ((((((value5 & 3) << 8) | 0) << 1 << 1) ^ ((((value5 & 3) << 8) | 0) << 1 << 1) + 0x7000) & (((((value5 & 3) << 8) | 0) << 1 << 1) + 0x7000 ^ 0x7000) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = dp;
            { const uint16_t sp_call = r->sp; JSR(c, 0x24BD, 0xC224F1); GUARD_JSR(c, sp_call, 0x24BD); } /* expand_boss_loader_resource_to_bus */
            uint16_t a_all = r->a;
            uint16_t y_ret = r->y;
            bool overflow_ret = r->v;
            uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp + 0x46));
            BUS16_RMW_SET(c, (uint16_t)(dp + 0x46), (uint16_t)(value6 + 1));
            a_hi1 = a_all >> 8;
            y1 = y_ret;
            overflow1 = overflow_ret;
            continue;
        }
        a_hi1 = 0;
        break;
    }
    r->y = y1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = dp;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC22476, SOM_RTS, "gen", load_boss_projectile_graphics_list, 0, L_Y | L_V, 1, 0, 0, 77, 37)
