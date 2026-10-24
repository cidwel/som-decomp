#include "som_c.h"

/* C2CC07 update_and_emit_event_radial_particle   [class B, 334 bytes, 156 instructions]
 * Source: src/rom/update_and_emit_event_radial_particle.s
 * Documented in docs/event-menu-effect-particles.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: XY.
 */
static void update_and_emit_event_radial_particle(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    if ((RAM8(0x0018) & 3) == 0) {
        uint8_t value2 = RAM8(0xF645 + y);
        RAM8(0xF645 + y) = (uint8_t)(value2 + 0x55);
        RAM8(0xF646 + y) = (((uint8_t)(value2 + 0x55) & 3) << 1) | 0x20;
    }
    uint8_t value3 = RAM8(0xF641 + y);
    uint8_t value4 = RAM8(0xF642 + y);
    uint8_t a3;
    if (value3 + value4 <= 0xFF) {
        a3 = (uint8_t)(value3 + value4);
    } else {
        RAM8(0xF643 + y) ^= 8;
        RAM8(0xF640 + y) ^= 0x10;
        uint8_t value7 = RAM8(0x0019);
        uint8_t a2;
        if (!(value7 & 0x80)) {
            a2 = 0;
        } else {
            uint8_t value8 = RAM8(0x0018);
            uint8_t a1;
            if (value8 & 0x80) {
                a1 = 0;
            } else {
                RAM8(0xF642 + y) = 0;
                RAM8(0xF640 + y) = 0xFF;
                a1 = 0xFF;
            }
            a2 = a1;
        }
        a3 = a2;
    }
    RAM8(0xF641 + y) = a3;
    uint16_t value9 = BUS16(c, 0x00FD22 + (((((a >> 8 << 8) | a3) & 0xFF) ^ 0xFF) << 1));
    uint8_t a4;
    if ((uint16_t)(0x0100 - value9) < 0x0100) {
        BUS8_SET(c, 0x004202, (uint8_t)(0x0100 - value9));
        BUS8_SET(c, 0x004203, RAM8(0xF640 + y));
        uint8_t value11 = BUS8(c, 0x004217);
        a4 = value11;
    } else {
        a4 = RAM8(0xF640 + y);
    }
    RAM8(0x0000) = a4;
    uint8_t value13 = RAM8(0xF643 + y);
    uint16_t value14 = RAM16(0xF643 + y);
    uint8_t a5;
    if ((value13 & 0x40) < 0x40) {
        a5 = value14 & 0x3F;
    } else {
        a5 = (value14 & 0x3F) ^ 0x3F;
    }
    uint16_t value15 = BUS16(c, 0x00FD22 + (a5 << 1 << 1 << 1));
    uint8_t a6;
    uint8_t a_hi1;
    if (value15 < 0x0100) {
        a6 = (uint8_t)value15;
        a_hi1 = value15 >> 8;
    } else {
        a6 = 0xFF;
        a_hi1 = 0;
    }
    RAM16_SET(0x0002, (a_hi1 << 8) | a6);
    uint16_t value16 = BUS16(c, 0x00FD22 + ((a5 << 1 << 1 << 1) ^ 0x01FE) + 2);
    uint8_t a7;
    uint8_t a_hi2;
    if (value16 < 0x0100) {
        a7 = (uint8_t)value16;
        a_hi2 = value16 >> 8;
    } else {
        a7 = 0xFF;
        a_hi2 = 0;
    }
    RAM16_SET(0x0004, (a_hi2 << 8) | a7);
    BUS8_SET(c, 0x004202, RAM8(0x0000));
    BUS8_SET(c, 0x004203, RAM8(0x0002));
    uint8_t value19 = BUS8(c, 0x004217);
    RAM8(0x0002) = value19;
    BUS8_SET(c, 0x004203, RAM8(0x0004));
    uint8_t value21 = BUS8(c, 0x004217);
    RAM8(0x0004) = value21;
    uint8_t value22 = RAM8(0xF643 + y);
    if (value22 & 0x80) {
        if (value22 < 0xC0) {
            RAM8(0x0004) ^= 0xFF;
            RAM8(0x0005) ^= 0xFF;
        }
        RAM8(0x0002) ^= 0xFF;
        RAM8(0x0003) ^= 0xFF;
    } else {
        if (value22 >= 0x40) {
            RAM8(0x0004) ^= 0xFF;
            RAM8(0x0005) ^= 0xFF;
        }
    }
    uint16_t value29 = RAM16(0x001E);
    uint16_t value30 = RAM16(0x0002);
    if ((uint16_t)((uint16_t)((value29 & 0xFF) - 4) + value30) >= 0x0100) {
        r->x = ((a5 << 1 << 1 << 1) ^ 0x01FE) + 2;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0002, (uint16_t)((uint16_t)((value29 & 0xFF) - 4) + value30));
    uint16_t value31 = RAM16(0x001F);
    uint16_t value32 = RAM16(0x0004);
    if ((uint16_t)(((uint16_t)(value31 - 4) & 0xFF) + value32) < 0x0100) {
        RAM16_SET(0x0003, (uint16_t)(((uint16_t)(value31 - 4) & 0xFF) + value32));
        uint16_t value33 = RAM16(0x0008);
        RAM16_SET(0x0900 + value33, RAM16(0x0002));
        RAM16_SET(0x0902 + value33, RAM16(0xF646 + y));
        RAM16_SET(0x0008, (uint16_t)(value33 + 4));
        r->x = (uint16_t)(value33 + 4);
        RETURN_RTS(c);
    }
    r->x = ((a5 << 1 << 1 << 1) ^ 0x01FE) + 2;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2CC07, SOM_RTS, "gen", update_and_emit_event_radial_particle, 0, L_X | L_Y, 1, 0, 0, 334, 156)
