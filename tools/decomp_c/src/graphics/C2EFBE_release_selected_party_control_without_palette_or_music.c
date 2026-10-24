#include "som_c.h"

/* C2EFBE release_selected_party_control_without_palette_or_music   [class A, 30 bytes, 15 instructions]
 * Source: src/rom/release_selected_party_control_without_palette_or_music.s
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: XCV.
 */
static void release_selected_party_control_without_palette_or_music(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0xA9 + value);
    BUS8_SET(c, (db << 0x10) + 0x01B4 + (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000), 1);
    uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x0E + (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000));
    BUS8_SET(c, (db << 0x10) + 0x0E + (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000), value3 & 0x7F);
    r->x = value;
    r->c = (uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000 > 0xFFFF;
    r->v = (((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value2 << 8) | (value2 >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2EFBE, SOM_RTS, "gen", release_selected_party_control_without_palette_or_music, 0, L_X | L_C | L_V, 1, 0, 0, 30, 15)
