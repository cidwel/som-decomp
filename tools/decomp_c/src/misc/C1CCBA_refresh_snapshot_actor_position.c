#include "som_c.h"

/* C1CCBA refresh_snapshot_actor_position   [class B, 59 bytes, 33 instructions]
 * Source: src/rom/refresh_snapshot_actor_position.s
 * Documented in docs/cutscene-engine.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XY.
 */
static void refresh_snapshot_actor_position(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0xC802 + x);
    RAM16_SET(0x0000, (RAM16(0xE002 + value) >> 4) & 0x7F);
    uint16_t value3 = RAM16(0xE004 + value);
    RAM16_SET(0xC80A + x, ((((uint8_t)(value3 >> 4) << 8) | (value3 >> 4 >> 8)) & 0x7F00) | RAM16(0x0000));
    RAM8(0x0000) = (RAM8(0xE00B + value) & 0x80) >> 4;
    RAM8(0xC80C + x) = (RAM8(0xC80C + x) & 0xF7) | RAM8(0x0000);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1CCBA, SOM_RTS, "gen", refresh_snapshot_actor_position, 0, L_X | L_Y, 2, 1, 0, 59, 33)
