#include "som_c.h"

/* C0C170 write_map_frame_background_scroll   [class D, 95 bytes, 42 instructions]
 * Source: src/rom/write_map_frame_background_scroll.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: CV.
 */
static void write_map_frame_background_scroll(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool carry = r->c;
    uint8_t value = RAM8(0x005E);
    BUS8_SET(c, 0x00210D, (value & 2) ^ RAM8(0x00B0));
    BUS8_SET(c, 0x00210D, RAM8(0x00B1));
    uint8_t value4 = RAM8(0x005F);
    BUS8_SET(c, 0x00210E, (value4 & 2) ^ RAM8(0x00B2));
    BUS8_SET(c, 0x00210E, RAM8(0x00B3));
    uint8_t value7 = RAM8(0x00B9);
    uint8_t a1;
    bool carry1;
    if (value7 != 0) {
        BUS8_SET(c, 0x00210F, ((value & 4) >> 1) ^ RAM8(0x00B4));
        BUS8_SET(c, 0x00210F, RAM8(0x00B5));
        a1 = ((value4 & 4) >> 1) ^ RAM8(0x00B6);
        carry1 = value4 & 4 & 0x01;
    } else {
        BUS8_SET(c, 0x00210F, RAM8(0x00B4));
        BUS8_SET(c, 0x00210F, RAM8(0x00B5));
        a1 = RAM8(0x00B6);
        carry1 = carry;
    }
    BUS8_SET(c, 0x002110, a1);
    BUS8_SET(c, 0x002110, 0);
    BUS8_SET(c, 0x002111, RAM8(0x003E));
    BUS8_SET(c, 0x002111, RAM8(0x003F));
    BUS8_SET(c, 0x002112, RAM8(0x0040));
    BUS8_SET(c, 0x002112, 0);
    r->c = carry1;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0C170, SOM_RTS, "gen", write_map_frame_background_scroll, 0, L_C | L_V, 1, 0, 1, 95, 42)
