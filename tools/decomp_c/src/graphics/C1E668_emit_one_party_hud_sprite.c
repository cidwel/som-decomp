#include "som_c.h"

/* C1E668 emit_one_party_hud_sprite   [class B, 60 bytes, 34 instructions]
 * Source: src/rom/emit_one_party_hud_sprite.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXC.
 */
static void emit_one_party_hud_sprite(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    RAM8(0x0002) = (uint8_t)((uint8_t)((a_hi & 0x1F) - 2) << 3);
    RAM8(0x0003) = 0xC7;
    RAM16_SET(0x0000, (((a << 8) | 0xC7) & 0x0E00) | 0x3000);
    uint16_t value = RAM16(0x007C);
    BUS16_SET(c, 0x0802 + value, y | RAM16(0x0000));
    BUS16_SET(c, 0x0800 + value, RAM16(0x0002));
    RAM16_SET(0x007C, (uint16_t)(value + 4));
    uint8_t value4 = RAM8(0x0059);
    uint8_t a1;
    if (!((uint8_t)(value4 << 1) & 0x80)) {
        a1 = (uint8_t)(value4 << 2);
    } else {
        RAM8(0x005A)++;
        a1 = 1;
    }
    RAM8(0x0059) = a1;
    r->a = (r->a & 0x00FF) | (((uint16_t)(value + 4) >> 8) << 8);
    r->c = (uint8_t)(value4 << 1) & 0x80;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E668, SOM_RTS, "hand", emit_one_party_hud_sprite, 0, L_B | L_X | L_C, 1, 1, 0, 60, 34)
