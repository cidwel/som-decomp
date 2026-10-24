#include "som_c.h"

/* C2C757 test_map_object_event_flag_range   [class A, 47 bytes, 29 instructions]
 * Source: src/rom/test_map_object_event_flag_range.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void test_map_object_event_flag_range(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = RAM8(0xC808 + y);
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    RAM8(0x0000) = RAM8(EVENT_FLAG_BYTES + value);
    uint8_t value2 = RAM8(0xC809 + y);
    RAM8(0x0001) = value2 & 0x0F;
    RAM8(0x0002) = value2 >> 4;
    uint8_t value3 = RAM8(0x0000);
    if (value3 < RAM8(0x0002)) {
        r->a = value3;
        r->c = 0;
        RETURN_RTL(c);
    }
    uint8_t value5 = RAM8(0x0001);
    if (value3 == value5) {
        r->a = value3;
        r->c = 1;
        RETURN_RTL(c);
    }
    if (value3 >= value5) {
        r->a = value3;
        r->c = 0;
        RETURN_RTL(c);
    }
    r->a = value3;
    r->c = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2C757, SOM_RTL, "gen", test_map_object_event_flag_range, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, 1, 0, 47, 29)
