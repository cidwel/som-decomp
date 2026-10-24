#include "som_c.h"

/* C090FA build_first_ui_hdma_matrix_record_bank   [class B, 205 bytes, 103 instructions]
 * Source: src/rom/build_first_ui_hdma_matrix_record_bank.s
 * Documented in docs/ui-native-ui-frame-hdma.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void build_first_ui_hdma_matrix_record_bank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint8_t x = r->x;
    const bool carry = r->c;
    uint16_t value = RAM16(0x0007);
    RAM16_SET(0x1300, value);
    uint8_t a_hi1 = value >> 8;
    uint8_t x1 = x;
    bool carry1 = carry;
    for (;;) {
        uint16_t value2 = RAM16(0x0004);
        uint16_t value3 = RAM16(0x0006);
        RAM16_SET(0x0006, (uint16_t)(value2 + value3 + carry1));
        if (value2 + value3 + carry1 > 0xFFFF) {
            RAM16_SET(0x0008, (uint16_t)(RAM16(0x0008) + 1));
        }
        RAM16_SET(0x1300 + x1, RAM16(0x0007));
        uint8_t value5 = BUS8(c, 0x004214);
        BUS8_SET(c, 0x004202, value5);
        BUS8_SET(c, 0x004203, RAM8(0x0035));
        RAM16_SET(0x0000, (uint16_t)(RAM16(0x0000) + 1));
        uint8_t value7 = RAM8(0x0034);
        uint16_t value8 = BUS16(c, 0x004216);
        BUS8_SET(c, 0x004203, value7);
        uint16_t value9 = RAM16(0x004B);
        uint8_t a1;
        uint8_t a_hi2;
        if (!(value9 & 0x8000)) {
            a1 = (uint8_t)(value8 >> 6);
            a_hi2 = value8 >> 6 >> 8;
        } else {
            a1 = (uint8_t)((value8 >> 6) ^ 0xFFFF);
            a_hi2 = ((value8 >> 6) ^ 0xFFFF) >> 8;
        }
        RAM16_SET(0x1000 + x1, (a_hi2 << 8) | a1);
        uint16_t value10 = BUS16(c, 0x004216);
        BUS8_SET(c, 0x004206, RAM8(0x0000));
        uint16_t value12 = RAM16(0x004B);
        uint8_t a_hi4;
        uint8_t x3;
        if (!(value12 & 0x4000)) {
            RAM16_SET(0x1200 + x1, value10 >> 6);
            RAM16_SET(0x1100 + x1, (value10 >> 6) ^ 0xFFFF);
            if ((uint8_t)(x1 + 2) != 0) {
                a_hi1 = ((value10 >> 6) ^ 0xFFFF) >> 8;
                x1 = (uint8_t)(x1 + 2);
                carry1 = value10 >> 5 & 0x01;
                continue;
            }
            a_hi4 = ((value10 >> 6) ^ 0xFFFF) >> 8;
            x3 = (uint8_t)(x1 + 2);
        } else {
            RAM16_SET(0x1100 + x1, value10 >> 6);
            RAM16_SET(0x1200 + x1, (value10 >> 6) ^ 0xFFFF);
            if ((uint8_t)(x1 + 2) != 0) {
                a_hi1 = ((value10 >> 6) ^ 0xFFFF) >> 8;
                x1 = (uint8_t)(x1 + 2);
                carry1 = value10 >> 5 & 0x01;
                continue;
            }
            uint8_t a_hi3;
            uint8_t x2;
            if ((uint8_t)(x1 + 2) == 0) {
                a_hi3 = ((value10 >> 6) ^ 0xFFFF) >> 8;
                x2 = (uint8_t)(x1 + 2);
            } else {
                RAM16_SET(0x1200 + (uint8_t)(x1 + 2), (value10 >> 6) ^ 0xFFFF);
                RAM16_SET(0x1100 + (uint8_t)(x1 + 2), (value10 >> 6) ^ 0xFFFF ^ 0xFFFF);
                if ((uint8_t)(x1 + 4) != 0) {
                    a_hi1 = ((value10 >> 6) ^ 0xFFFF ^ 0xFFFF) >> 8;
                    x1 = (uint8_t)(x1 + 4);
                    carry1 = value10 >> 5 & 0x01;
                    continue;
                }
                a_hi3 = ((value10 >> 6) ^ 0xFFFF ^ 0xFFFF) >> 8;
                x2 = (uint8_t)(x1 + 4);
            }
            a_hi4 = a_hi3;
            x3 = x2;
        }
        a_hi1 = a_hi4;
        x1 = x3;
        carry1 = value10 >> 5 & 0x01;
        break;
    }
    uint8_t a_hi5 = a_hi1;
    uint8_t x4 = x1;
    uint8_t y1 = 0;
    bool carry2 = carry1;
    bool overflow1 = 0;
    for (;;) {
        uint16_t value13 = RAM16(0x0004);
        uint16_t value14 = RAM16(0x0006);
        RAM16_SET(0x0006, (uint16_t)(value13 + value14 + carry2));
        if (value13 + value14 + carry2 > 0xFFFF) {
            RAM16_SET(0x0008, (uint16_t)(RAM16(0x0008) + 1));
        }
        RAM16_SET(0x0CC0 + x4, RAM16(0x0007));
        uint8_t value16 = BUS8(c, 0x004214);
        BUS8_SET(c, 0x004202, value16);
        BUS8_SET(c, 0x004203, RAM8(0x0035));
        RAM16_SET(0x0000, (uint16_t)(RAM16(0x0000) + 1));
        uint8_t value18 = RAM8(0x0034);
        uint16_t value19 = BUS16(c, 0x004216);
        BUS8_SET(c, 0x004203, value18);
        uint16_t value20 = RAM16(0x004B);
        uint8_t a2;
        uint8_t a_hi6;
        if (!(value20 & 0x8000)) {
            a2 = (uint8_t)(value19 >> 6);
            a_hi6 = value19 >> 6 >> 8;
        } else {
            a2 = (uint8_t)((value19 >> 6) ^ 0xFFFF);
            a_hi6 = ((value19 >> 6) ^ 0xFFFF) >> 8;
        }
        RAM16_SET(0x0C00 + x4, (a_hi6 << 8) | a2);
        uint16_t value21 = BUS16(c, 0x004216);
        uint8_t value22 = RAM8(0x0000);
        BUS8_SET(c, 0x004206, value22);
        uint16_t value23 = RAM16(0x004B);
        if (!(value23 & 0x4000)) {
            RAM16_SET(0x0C80 + x4, value21 >> 6);
            RAM16_SET(0x0C40 + x4, (value21 >> 6) ^ 0xFFFF);
            uint8_t value24 = RAM8(0x0010);
            if ((uint8_t)(x4 + 2) < value24) {
                uint8_t a_hi5_next = ((value21 >> 6) ^ 0xFFFF) >> 8;
                uint8_t x4_next = (uint8_t)(x4 + 2);
                uint8_t y1_next = value22;
                bool carry2_next = (uint8_t)(x4 + 2) >= value24;
                bool overflow1_next = value23 & 0x4000;
                a_hi5 = a_hi5_next;
                x4 = x4_next;
                y1 = y1_next;
                carry2 = carry2_next;
                overflow1 = overflow1_next;
                continue;
            }
            uint8_t a_hi5_next3 = ((value21 >> 6) ^ 0xFFFF) >> 8;
            uint8_t x4_next3 = (uint8_t)(x4 + 2);
            uint8_t y1_next3 = value22;
            bool carry2_next3 = (uint8_t)(x4 + 2) >= value24;
            bool overflow1_next3 = value23 & 0x4000;
            a_hi5 = a_hi5_next3;
            x4 = x4_next3;
            y1 = y1_next3;
            carry2 = carry2_next3;
            overflow1 = overflow1_next3;
            break;
        }
        RAM16_SET(0x0C40 + x4, value21 >> 6);
        RAM16_SET(0x0C80 + x4, (value21 >> 6) ^ 0xFFFF);
        uint8_t value25 = RAM8(0x0010);
        if ((uint8_t)(x4 + 2) < value25) {
            uint8_t a_hi5_next2 = ((value21 >> 6) ^ 0xFFFF) >> 8;
            uint8_t x4_next2 = (uint8_t)(x4 + 2);
            uint8_t y1_next2 = value22;
            bool carry2_next2 = (uint8_t)(x4 + 2) >= value25;
            bool overflow1_next2 = value23 & 0x4000;
            a_hi5 = a_hi5_next2;
            x4 = x4_next2;
            y1 = y1_next2;
            carry2 = carry2_next2;
            overflow1 = overflow1_next2;
            continue;
        }
        r->a = (value21 >> 6) ^ 0xFFFF;
        r->y = value22;
        r->c = (uint8_t)(x4 + 2) >= value25;
        r->v = value23 & 0x4000;
        RETURN_RTS(c);
    }
    r->a = (a_hi5 << 8) | (uint8_t)a;
    r->y = y1;
    r->c = carry2;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC090FA, SOM_RTS, "gen", build_first_ui_hdma_matrix_record_bank, 0, L_B | L_Y | L_C | L_V, 1, 0, 1, 205, 103)
