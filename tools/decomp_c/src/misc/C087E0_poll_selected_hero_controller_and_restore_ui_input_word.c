#include "som_c.h"

/* C087E0 poll_selected_hero_controller_and_restore_ui_input_word   [class B, 75 bytes, 36 instructions]
 * Source: src/rom/poll_selected_hero_controller_and_restore_ui_input_word.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void poll_selected_hero_controller_and_restore_ui_input_word(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t value = RAM16(0x00D4);
    uint8_t value2 = RAM8(0xE02C + value);
    uint8_t a2;
    bool zero2;
    bool negative2;
    if ((value2 & 2) != 0) {
        uint8_t value3 = RAM8(0x00CC);
        RAM8(0x00CD) = value3;
        a2 = value3;
        zero2 = value3 == 0;
        negative2 = value3 & 0x80;
    } else {
        uint8_t a1;
        bool zero1;
        bool negative1;
        if ((value2 & 4) == 0) {
            a1 = value2;
            zero1 = (value2 & 4) == 0;
            negative1 = value2 & 0x80;
        } else {
            uint8_t value4 = RAM8(0x00CC);
            RAM8(0x00CE) = value4;
            a1 = value4;
            zero1 = value4 == 0;
            negative1 = value4 & 0x80;
        }
        a2 = a1;
        zero2 = zero1;
        negative2 = negative1;
    }
    r->a = (a >> 8 << 8) | a2;
    r->x = value;
    r->z = zero2;
    r->n = negative2;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x87FE, 0xC093B9); GUARD_JSR(c, sp_call, 0x87FE); } /* poll_three_controller_words_and_publish_pressed_edges */
    uint16_t dp_ret = r->dp;
    uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xD4));
    uint8_t value6 = RAM8(0xE02C + value5);
    if ((value6 & 2) != 0) {
        uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret + 0xCD));
        BUS8_SET(c, (uint16_t)(dp_ret + 0xCC), value7);
        uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x44));
        BUS8_SET(c, (uint16_t)(dp_ret + 0x42), value8);
        uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x45));
        BUS8_SET(c, (uint16_t)(dp_ret + 0x43), value9);
        r->x = value5;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    if ((value6 & 4) != 0) {
        uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp_ret + 0xCE));
        BUS8_SET(c, (uint16_t)(dp_ret + 0xCC), value10);
        uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x46));
        BUS8_SET(c, (uint16_t)(dp_ret + 0x42), value11);
        uint8_t value12 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x47));
        BUS8_SET(c, (uint16_t)(dp_ret + 0x43), value12);
    }
    r->x = value5;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC087E0, SOM_RTS, "gen", poll_selected_hero_controller_and_restore_ui_input_word, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 75, 36)
