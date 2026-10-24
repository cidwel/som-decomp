#include "som_c.h"

/* C75181 compare_twelve_native_party_name_bytes   [class B, 65 bytes, 33 instructions]
 * Source: src/rom/compare_twelve_native_party_name_bytes.s
 * Documented in docs/event-menu-name-helpers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BV.
 */
static void compare_twelve_native_party_name_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    uint16_t value = RAM16(0xA22B);
    RAM16_SET(0xA173, (value & 0xFF) << 1 << 1);
    uint16_t value2 = RAM16(0xA173);
    uint16_t value3 = RAM16(0xA175);
    RAM16_SET(0xA173, (uint16_t)((uint16_t)((value3 & 0xFF) - 1) << 2));
    uint16_t value4 = RAM16(0xA173);
    RAM8(0xA1D0) = 0x0C;
    uint8_t a_hi1 = (uint16_t)((uint16_t)((uint16_t)((value3 & 0xFF) - 1) << 3) + value4) >> 8;
    uint16_t x1 = (uint16_t)(((value & 0xFF) << 1 << 1 << 1) + value2);
    uint16_t y1 = (uint16_t)((uint16_t)((uint16_t)((value3 & 0xFF) - 1) << 3) + value4);
    do {
        if (RAM8(0xCC00 + y1) != RAM8(0xCC00 + x1)) {
            RAM8(0xA171) = 1;
        }
        RAM8(0xA1D0)--;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 + 1);
    } while (RAM8(0xA1D0) != 0);
    r->a = (a_hi1 << 8) | a;
    r->v = (((uint16_t)((uint16_t)((value3 & 0xFF) - 1) << 3) ^ (uint16_t)((uint16_t)((uint16_t)((value3 & 0xFF) - 1) << 3) + value4)) & (value4 ^ (uint16_t)((uint16_t)((uint16_t)((value3 & 0xFF) - 1) << 3) + value4)) & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75181, SOM_RTS, "gen", compare_twelve_native_party_name_bytes, 0, L_B | L_V, 1, 1, 0, 65, 33)
