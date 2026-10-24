#include "som_c.h"

/* C20779 prepare_boss_secondary_collision_box   [class B, 78 bytes, 41 instructions]
 * Source: src/rom/prepare_boss_secondary_collision_box.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABYCV.
 */
static void prepare_boss_secondary_collision_box(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x00C2 + x);
    if (value == 0) {
        r->a = value;
        r->c = 1;
        RETURN_RTS(c);
    }
    RAM16_SET(0x025E, RAM16(0x002B + x));
    RAM16_SET(0x0260, (uint16_t)((uint16_t)(((RAM16(0x0066 + x) >> 1) ^ 0xFFFF) + 1) + RAM16(0x0032 + x)));
    uint16_t value5 = RAM16(0x0066 + x);
    RAM16_SET(0x0264, value5);
    uint8_t a_hi1 = value5 >> 8;
    uint16_t x1 = 0;
    uint16_t y1 = x;
    for (;;) {
        uint8_t value6 = RAM8(0x00C0 + y1);
        BUS8_SET(c, (uint16_t)(x1 + 0x0256), value6);
        if (!(value6 & 0x80)) {
            BUS8_SET(c, (uint16_t)(x1 + 0x0257), 0);
        } else {
            BUS8_SET(c, (uint16_t)(x1 + 0x0257), 0xFF);
        }
        x1 = (uint16_t)(x1 + 2);
        y1 = (uint16_t)(y1 + 1);
        if (!(x1 != 8)) break;
    }
    RAM16_SET(0x0256, (uint16_t)(RAM16(0x025E) + RAM16(0x0256)));
    uint16_t value9 = RAM16(0x0260);
    uint16_t value10 = RAM16(0x0258);
    RAM16_SET(0x0258, (uint16_t)(value9 + value10));
    r->a = (uint16_t)(value9 + value10);
    r->y = y1;
    r->c = 0;
    r->v = ((value9 ^ (uint16_t)(value9 + value10)) & (value10 ^ (uint16_t)(value9 + value10)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20779, SOM_RTS, "gen", prepare_boss_secondary_collision_box, 0, L_A | L_B | L_Y | L_C | L_V, 1, 0, 0, 78, 41)
