#include "som_c.h"

/* C25329 release_boss_target_without_boss_completion_store   [class B, 43 bytes, 20 instructions]
 * Source: src/rom/release_boss_target_without_boss_completion_store.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void release_boss_target_without_boss_completion_store(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    uint16_t value = BUS16_RDP(c, (db << 0x10) + 0xA9 + x);
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x60 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
    if (value2 == 0) {
        uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x0190 + x);
        if (!(value3 & 0x80)) {
            BUS8_SET(c, (db << 0x10) + 0x01E5 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000), 0x0E);
        }
    }
    BUS8_SET(c, (db << 0x10) + 0x01B4 + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000), 1);
    uint8_t value4 = BUS8_RDP(c, (db << 0x10) + 0x0E + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000));
    BUS8_SET(c, (db << 0x10) + 0x0E + (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000), value4 & 0x7F);
    r->a = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) >> 8 << 8 | (value4 & 0x7F);
    r->y = (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000);
    r->c = (uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000 > 0xFFFF;
    r->z = (value4 & 0x7F) == 0;
    r->n = value4 & 0x7F & 0x80;
    r->v = (((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000)) & ((uint16_t)((uint16_t)((((uint8_t)value << 8) | (value >> 8)) << 1) + 0xE000) ^ 0xE000) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25329, SOM_RTS, "gen", release_boss_target_without_boss_completion_store, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 43, 20)
