#include "som_c.h"

/* D3F683 advance_and_publish_spell_frame_sprite   [class B, 70 bytes, 30 instructions]
 * Source: src/rom/advance_and_publish_spell_frame_sprite.s
 * Documented in docs/map-oam-spell-frames.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$01E4.  Callers read: Y.
 */
static void advance_and_publish_spell_frame_sprite(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x01E4) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0x0003 + y);
    uint8_t value2 = RAM8(0x0005 + x);
    RAM8(0x0005 + x) = (uint8_t)(value + value2);
    RAM16_SET(0x0006 + x, (uint16_t)(RAM16(0x0004 + y) + RAM16(0x0006 + x) + (value + value2 > 0xFF)));
    uint8_t value5 = RAM8(0x0000 + y);
    uint8_t value6 = RAM8(0x0002 + x);
    RAM8(0x0002 + x) = (uint8_t)(value5 + value6);
    uint16_t value7 = RAM16(0x0001 + y);
    uint16_t value8 = RAM16(0x0003 + x);
    RAM16_SET(0x0003 + x, (uint16_t)(value7 + value8 + (value5 + value6 > 0xFF)));
    uint16_t value9 = RAM16(0x0000 + x);
    RAM16_SET(0x0002 + value9, (uint16_t)(value7 + value8 + (value5 + value6 > 0xFF)));
    RAM16_SET(0x0004 + value9, RAM16(0x0006 + x));
    r->x = value9;
    r->y = value9;
    r->c = value7 + value8 + (value5 + value6 > 0xFF) > 0xFFFF;
    r->z = value9 == 0;
    r->n = value9 & 0x8000;
    r->v = ((value7 ^ (uint16_t)(value7 + value8 + (value5 + value6 > 0xFF))) & (value8 ^ (uint16_t)(value7 + value8 + (value5 + value6 > 0xFF))) & 0x8000) != 0;
    r->sp -= 3;
    JSL(c, 0xF6C5, 0xC12E84); /* publish_spell_frame_projection_long */
    r->sp += 3;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3F683, SOM_RTS, "gen", advance_and_publish_spell_frame_sprite, 0, L_Y, 3, 0, 0, 70, 30)
