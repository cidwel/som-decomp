#include "som_c.h"

/* C1B729 prepare_native_partner_obstacle_detour   [class B, 100 bytes, 50 instructions]
 * Source: src/rom/prepare_native_partner_obstacle_detour.s
 * Documented in docs/actor-party-obstacle-detour.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void prepare_native_partner_obstacle_detour(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    RAM16_SET(0x0010, y);
    uint8_t value = RAM8(0xE00B + y);
    RAM8(0x0004) = value & 3;
    uint8_t a_hi1;
    if (value >= 0x80) {
        RAM16_SET(0x000A, 0x4000);
        RAM16_SET(0x000D, 0xBC00);
        a_hi1 = 0xBC;
    } else {
        RAM16_SET(0x000A, 0);
        RAM16_SET(0x000D, 0xB800);
        a_hi1 = 0xB8;
    }
    uint16_t value2 = RAM16(0xE006 + y);
    RAM16_SET(0x0006, value2);
    if (value2 == 0) {
        r->a = value2;
        r->x = y;
        r->c = value >= 0x80;
        r->mf = 0;
        RETURN_RTL(c);
    }
    RAM16_SET(0x0008, RAM16(0xE002 + y) >> 4);
    uint16_t value4 = RAM16(0xE004 + y);
    uint16_t value5 = RAM16(0x0008);
    RAM16_SET(0x0008, ((value4 & 0x0FF0) << 1 << 1 << 1) | value5);
    RAM8(0x000C) = 0x7F;
    RAM8(0x000F) = 0x7F;
    uint8_t value6 = RAM8(0x0006);
    if (value6 == 0) {
        r->a = ((((value4 & 0x0FF0) << 1 << 1 << 1) | value5) >> 8 << 8) | value6;
        r->x = y;
        JSR(c, 0xB787, 0xC1B78D); /* search_native_horizontal_detour_after_vertical_motion */
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    uint8_t value7 = RAM8(0x0007);
    if (value7 == 0) {
        r->a = ((((value4 & 0x0FF0) << 1 << 1 << 1) | value5) >> 8 << 8) | value7;
        r->x = y;
        JSR(c, 0xB783, 0xC1B877); /* search_native_vertical_detour_after_horizontal_motion */
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    if (value7 != 0) {
        r->a = ((((value4 & 0x0FF0) << 1 << 1 << 1) | value5) >> 8 << 8) | value7;
        r->x = y;
        r->c = (value4 & 0x0FF0) << 1 << 1 & 0x8000;
        JSR(c, 0xB78B, 0xC1B929); /* reverse_native_diagonal_partner_motion_for_retry */
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    r->a = ((((value4 & 0x0FF0) << 1 << 1 << 1) | value5) >> 8 << 8) | value7;
    r->x = y;
    r->c = (value4 & 0x0FF0) << 1 << 1 & 0x8000;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1B729, SOM_RTL, "gen", prepare_native_partner_obstacle_detour, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 100, 50)
