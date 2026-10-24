#include "som_c.h"

/* D0DCBE finish_native_equipment_exchange_with_two_sprite_flights   [class B, 50 bytes, 20 instructions]
 * Source: src/rom/finish_native_equipment_exchange_with_two_sprite_flights.s
 * Documented in docs/event-menu-equipment-flight.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void finish_native_equipment_exchange_with_two_sprite_flights(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t value = RAM8(0x19F0);
    bool x_flag2;
    uint8_t a_hi3;
    uint16_t x3;
    uint16_t y3;
    if (value != 2) {
        x_flag2 = 0;
        a_hi3 = a >> 8;
        x3 = x;
        y3 = y;
    } else {
        uint8_t value2 = RAM8(0x1804);
        bool x_flag;
        uint8_t a_hi2;
        uint16_t x2;
        uint16_t y2;
        if ((value2 & 0x20) == 0) {
            x_flag = 0;
            a_hi2 = a >> 8;
            x2 = x;
            y2 = y;
        } else {
            r->a = (a >> 8 << 8) | 0x20;
            r->c = value >= 2;
            r->v = value2 & 0x40;
            r->mf = true;
            r->sp -= 1;
            JSR(c, 0xDCD3, 0xD0DCF0); /* initialize_native_pair_of_equipment_flight_records */
            r->sp += 1;
            r->mf = true;
            r->xf = false;
            r->sp -= 1;
            JSL(c, 0xDCD7, 0xD0CF30); /* request_native_menu_audio_4b */
            r->sp += 1;
            uint16_t a_all2 = r->a;
            uint16_t x_ret2 = r->x;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool zero_ret2 = r->z;
            bool negative_ret2 = r->n;
            bool overflow_ret2 = r->v;
            uint8_t a1 = (uint8_t)a_all2;
            uint8_t a_hi1 = a_all2 >> 8;
            uint16_t x1 = x_ret2;
            uint16_t y1 = y_ret2;
            bool carry1 = carry_ret2;
            bool zero1 = zero_ret2;
            bool negative1 = negative_ret2;
            bool overflow1 = overflow_ret2;
            bool first_pass = true;
            for (;;) {
                if (first_pass) {
                    r->a = (a_hi1 << 8) | a1;
                    r->x = x1;
                    r->y = y1;
                    r->c = carry1;
                    r->z = zero1;
                    r->n = negative1;
                    r->v = overflow1;
                    r->mf = true;
                    r->xf = false;
                    r->db = 0;
                    r->dp = 0;
                    r->sp -= 1;
                    JSL(c, 0xDCDB, 0xC0695A); /* wait_vblank_and_poll_menu_through_native_long_wrapper */
                    r->sp += 1;
                    r->mf = false;
                    r->xf = false;
                    r->sp -= 1;
                    JSR(c, 0xDCDE, 0xD0DDB0); /* update_both_native_equipment_flight_records */
                    r->sp += 1;
                    uint16_t a_all4 = r->a;
                    uint16_t x_ret4 = r->x;
                    uint16_t y_ret4 = r->y;
                    bool carry_ret4 = r->c;
                    bool overflow_ret4 = r->v;
                    uint8_t value3 = RAM8(0x1826);
                    if (value3 == 0) {
                        a1 = value3;
                        a_hi1 = a_all4 >> 8;
                        x1 = (uint8_t)x_ret4;
                        y1 = (uint8_t)y_ret4;
                        carry1 = carry_ret4;
                        zero1 = value3 == 0;
                        negative1 = value3 & 0x80;
                        overflow1 = overflow_ret4;
                        first_pass = false;
                        continue;
                    }
                    a1 = value3;
                    a_hi1 = a_all4 >> 8;
                    x1 = (uint8_t)x_ret4;
                    y1 = (uint8_t)y_ret4;
                    carry1 = carry_ret4;
                    zero1 = value3 == 0;
                    negative1 = value3 & 0x80;
                    overflow1 = overflow_ret4;
                    break;
                } else {
                    r->a = (a_hi1 << 8) | a1;
                    r->x = (uint8_t)x1;
                    r->y = (uint8_t)y1;
                    r->c = carry1;
                    r->z = zero1;
                    r->n = negative1;
                    r->v = overflow1;
                    r->mf = true;
                    r->xf = true;
                    r->db = 0;
                    r->dp = 0;
                    r->sp -= 1;
                    JSL(c, 0xDCDB, 0xC0695A); /* wait_vblank_and_poll_menu_through_native_long_wrapper */
                    r->sp += 1;
                    r->mf = false;
                    r->xf = false;
                    r->sp -= 1;
                    JSR(c, 0xDCDE, 0xD0DDB0); /* update_both_native_equipment_flight_records */
                    r->sp += 1;
                    uint16_t a_all6 = r->a;
                    uint16_t x_ret6 = r->x;
                    uint16_t y_ret6 = r->y;
                    bool carry_ret6 = r->c;
                    bool overflow_ret6 = r->v;
                    uint8_t value4 = RAM8(0x1826);
                    if (value4 == 0) {
                        a1 = value4;
                        a_hi1 = a_all6 >> 8;
                        x1 = (uint8_t)x_ret6;
                        y1 = (uint8_t)y_ret6;
                        carry1 = carry_ret6;
                        zero1 = value4 == 0;
                        negative1 = value4 & 0x80;
                        overflow1 = overflow_ret6;
                        continue;
                    }
                    a1 = value4;
                    a_hi1 = a_all6 >> 8;
                    x1 = (uint8_t)x_ret6;
                    y1 = (uint8_t)y_ret6;
                    carry1 = carry_ret6;
                    zero1 = value4 == 0;
                    negative1 = value4 & 0x80;
                    overflow1 = overflow_ret6;
                    break;
                }
            }
            r->a = (a_hi1 << 8) | a1;
            r->x = (uint8_t)x1;
            r->y = (uint8_t)y1;
            r->c = carry1;
            r->z = zero1;
            r->n = negative1;
            r->v = overflow1;
            r->mf = true;
            r->xf = true;
            r->db = 0;
            r->dp = 0;
            r->sp -= 1;
            JSL(c, 0xDCE9, 0xC0693F); /* wait_menu_vblank_through_native_long_wrapper */
            r->sp += 1;
            r->mf = false;
            r->xf = true;
            r->sp -= 1;
            JSL(c, 0xDCED, 0xD0CF38); /* request_native_menu_audio_28 */
            r->sp += 1;
            uint16_t a_all8 = r->a;
            uint8_t x_ret8 = r->x;
            uint8_t y_ret8 = r->y;
            x_flag = 1;
            a_hi2 = a_all8 >> 8;
            x2 = x_ret8;
            y2 = y_ret8;
        }
        x_flag2 = x_flag;
        a_hi3 = a_hi2;
        x3 = x2;
        y3 = y2;
    }
    r->a = (a_hi3 << 8) | (uint8_t)a;
    r->x = x3;
    r->y = y3;
    r->c = carry;
    r->v = overflow;
    r->mf = false;
    r->xf = false;
    r->db = 0;
    r->dp = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0DCBE, SOM_RTL, "hand", finish_native_equipment_exchange_with_two_sprite_flights, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 50, 20)
