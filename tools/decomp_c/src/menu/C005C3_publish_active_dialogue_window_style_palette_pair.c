#include "som_c.h"

/* C005C3 publish_active_dialogue_window_style_palette_pair   [class B, 78 bytes, 39 instructions]
 * Source: src/rom/publish_active_dialogue_window_style_palette_pair.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYV.
 */
static void publish_active_dialogue_window_style_palette_pair(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    uint8_t value = RAM8(0xA24E);
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = value;
    uint8_t value2 = BUS8(c, 0xC77161 + value);
    RAM16_SET(0xA173, value2 << 1);
    uint16_t value3 = RAM16(0xA173);
    r->a = (uint16_t)((value2 << 1 << 1) + value3);
    r->x = 0x01E0;
    r->y = (uint16_t)((value2 << 1 << 1) + value3);
    r->c = (value2 << 1 << 1) + value3 > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = (((value2 << 1 << 1) ^ (uint16_t)((value2 << 1 << 1) + value3)) & (value3 ^ (uint16_t)((value2 << 1 << 1) + value3)) & 0x8000) != 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x05E2, 0xC00DFC); GUARD_JSR(c, sp_call, 0x05E2); } /* copy_dialogue_style_palette_and_highlight_colors */
    r->sp += 2;
    uint8_t db_ret = r->db;
    uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0xA24E);
    uint8_t value5 = BUS8(c, 0xC77159 + value4);
    BUS16_SET(c, (db_ret << 0x10) + 0xA173, value5 << 1);
    uint16_t value6 = BUS16_RDP(c, (db_ret << 0x10) + 0xA173);
    r->a = (uint16_t)((value5 << 1 << 1) + value6);
    r->x = 0x01E8;
    r->y = (uint16_t)((value5 << 1 << 1) + value6);
    r->c = (value5 << 1 << 1) + value6 > 0xFFFF;
    r->z = 0;
    r->n = 0;
    r->v = (((value5 << 1 << 1) ^ (uint16_t)((value5 << 1 << 1) + value6)) & (value6 ^ (uint16_t)((value5 << 1 << 1) + value6)) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x0601, 0xC00DFC); GUARD_JSR(c, sp_call, 0x0601); } /* copy_dialogue_style_palette_and_highlight_colors */
    r->sp += 2;
    uint8_t db_ret2 = r->db;
    uint8_t value7 = RAM8(0x0000 + sp0 - 1);
    uint8_t value8 = RAM8(0x0000 + sp0);
    uint16_t value9 = BUS16_RDP(c, (db_ret2 << 0x10) + 0xA23E + (uint16_t)(((value8 << 8) | value7) << 1));
    RAM16_SET(0x07E4, value9);
    r->a = (r->a & 0x00FF) | ((value9 >> 8) << 8);
    r->x = (uint16_t)(((value8 << 8) | value7) << 1);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC005C3, SOM_RTS, "gen", publish_active_dialogue_window_style_palette_pair, 0, L_B | L_X | L_Y | L_V, 2, 1, 0, 78, 39)
