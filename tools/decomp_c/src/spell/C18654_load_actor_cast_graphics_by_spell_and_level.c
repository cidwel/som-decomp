#include "som_c.h"

/* C18654 load_actor_cast_graphics_by_spell_and_level   [class B, 114 bytes, 61 instructions]
 * Source: src/rom/load_actor_cast_graphics_by_spell_and_level.s
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: ABXYCV.
 */
static void load_actor_cast_graphics_by_spell_and_level(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    BUS16_SET(c, (uint16_t)(dp + 0x14), x);
    RAM8(0x0000 + sp0) = a >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)a;
    BUS16_SET(c, (uint16_t)(dp + 8), (a & 0x7F) << 1 << 1 << 1 << 1 << 1 << 1);
    uint8_t value2 = RAM8(0x0000 + sp0);
    BUS8_SET(c, (uint16_t)(dp + 0x0A), value2);
    uint16_t y2;
    if ((value2 & 0x0F) < 8) {
        y2 = 2;
    } else {
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp + 0x0A));
        uint16_t y1;
        if (!(value3 & 0x80)) {
            y1 = 4;
        } else {
            y1 = 6;
        }
        y2 = y1;
    }
    uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp + 8));
    uint16_t value5 = BUS16(c, 0xD02AA0 + (uint16_t)(y2 + value4));
    uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
    RAM8(0x0000 + sp0) = value5 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value5;
    BUS16_SET(c, dp, (value5 & 0x07FF) << 1 << 1 << 1);
    uint16_t value7 = BUS16_RDP(c, dp);
    if ((((RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1)) & 0x0800) != 0) {
        BUS16_SET(c, (uint16_t)(dp + 8), 0x40);
        BUS16_SET(c, dp, 0);
        r->a = 0xD4;
        r->x = value6;
        r->y = (uint16_t)(((value5 & 0x07FF) << 1 << 1 << 1 << 1) + value7 + ((value5 & 0x07FF) << 1 << 1 << 1 >> 0x0F));
        r->c = ((value5 & 0x07FF) << 1 << 1 << 1 << 1) + value7 + ((value5 & 0x07FF) << 1 << 1 << 1 >> 0x0F) > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = ((((value5 & 0x07FF) << 1 << 1 << 1 << 1) ^ (uint16_t)(((value5 & 0x07FF) << 1 << 1 << 1 << 1) + value7 + ((value5 & 0x07FF) << 1 << 1 << 1 >> 0x0F))) & (value7 ^ (uint16_t)(((value5 & 0x07FF) << 1 << 1 << 1 << 1) + value7 + ((value5 & 0x07FF) << 1 << 1 << 1 >> 0x0F))) & 0x8000) != 0;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0x86BF, 0x01C599); GUARD_JSL(c, sp_call, 0x86BF); } /* dispatch_object_graphics_plane_conversion */
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x86C2, 0xC18634); GUARD_JSR(c, sp_call, 0x86C2); } /* load_actor_cast_secondary_graphics */
        uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
        r->x = value10;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    BUS16_SET(c, (uint16_t)(dp + 8), 0x7F);
    BUS16_SET(c, dp, 0);
    r->a = 0xD4;
    r->x = value6;
    r->y = (uint16_t)(((value5 & 0x07FF) << 1 << 1 << 1 << 1) + value7 + ((value5 & 0x07FF) << 1 << 1 << 1 >> 0x0F));
    r->c = ((value5 & 0x07FF) << 1 << 1 << 1 << 1) + value7 + ((value5 & 0x07FF) << 1 << 1 << 1 >> 0x0F) > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = ((((value5 & 0x07FF) << 1 << 1 << 1 << 1) ^ (uint16_t)(((value5 & 0x07FF) << 1 << 1 << 1 << 1) + value7 + ((value5 & 0x07FF) << 1 << 1 << 1 >> 0x0F))) & (value7 ^ (uint16_t)(((value5 & 0x07FF) << 1 << 1 << 1 << 1) + value7 + ((value5 & 0x07FF) << 1 << 1 << 1 >> 0x0F))) & 0x8000) != 0;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x86AB, 0x01C599); GUARD_JSL(c, sp_call, 0x86AB); } /* dispatch_object_graphics_plane_conversion */
    uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp + 0x14));
    r->x = value11;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC18654, SOM_RTS, "gen", load_actor_cast_graphics_by_spell_and_level, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, -1, 0, 114, 61)
