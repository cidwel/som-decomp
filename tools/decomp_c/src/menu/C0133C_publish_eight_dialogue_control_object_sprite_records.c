#include "som_c.h"

/* C0133C publish_eight_dialogue_control_object_sprite_records   [class B, 100 bytes, 43 instructions]
 * Source: src/rom/publish_eight_dialogue_control_object_sprite_records.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void publish_eight_dialogue_control_object_sprite_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value2 = RAM16(0x0000 + RAM16(0x1D14));
    bool m_flag;
    if ((value2 & 0xFF) != 0) {
        m_flag = 0;
    } else {
        uint16_t value3 = RAM16(0x1D16);
        uint8_t a1 = 8;
        uint8_t a_hi1 = value3 >> 8;
        uint16_t x1 = 0x28;
        uint16_t y1 = value3;
        for (;;) {
            BUS8_SET(c, 0x000800 + x1, (uint8_t)(RAM8(0x0001 + y1) - 0x98));
            BUS8_SET(c, 0x000801 + x1, RAM8(0x0002 + y1));
            BUS8_SET(c, 0x000802 + x1, RAM8(0x0003 + y1));
            uint8_t value7 = RAM8(0x0004 + y1);
            BUS8_SET(c, 0x000803 + x1, value7);
            a1 = (uint8_t)(a1 - 1);
            a_hi1 = value7;
            x1 = (uint16_t)(x1 - 4);
            y1 = (uint16_t)(y1 + 4);
            if (!(a1 != 0)) break;
        }
        RAM8(0x0A00) |= 0x80;
        RAM8(0x0A01) = 0xAA;
        RAM8(0x0A02) |= 0x2A;
        m_flag = 1;
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0133C, SOM_RTS, "gen", publish_eight_dialogue_control_object_sprite_records, 0, 0, 1, 1, 0, 100, 43)
