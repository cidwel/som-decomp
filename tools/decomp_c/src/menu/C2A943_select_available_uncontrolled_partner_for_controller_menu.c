#include "som_c.h"

/* C2A943 select_available_uncontrolled_partner_for_controller_menu   [class C, 177 bytes, 87 instructions]
 * Source: src/rom/select_available_uncontrolled_partner_for_controller_menu.s
 * Documented in docs/map-main-frame-partner-selection.md
 * Entry: M=8 bit X=any DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void select_available_uncontrolled_partner_for_controller_menu(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint8_t value = BUS8(c, (uint16_t)(0x00D9 + x));
    if ((((value & 6) << 8) | 0) == 0) {
        RAM8(0x0000) = 0;
        r->a = ((value & 6) << 8) | 0;
        r->x = 0x0200;
        r->y = ((value & 6) << 8) | 0;
        r->xf = 0;
        JSR(c, 0xA9BE, 0xC2A9F4); /* test_partner_actor_active_uncontrolled_and_status_available */
        bool carry_ret = r->c;
        if (!carry_ret) {
            RAM8(0x0000)++;
        }
        r->x = 0x0400;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0xA9C8, 0xC2A9F4); /* test_partner_actor_active_uncontrolled_and_status_available */
        bool carry_ret2 = r->c;
        if (!carry_ret2) {
            RAM8(0x0000)++;
            RAM8(0x0000)++;
        }
        uint8_t value2 = RAM8(0x0000);
        if (value2 == 0) {
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        uint8_t a3;
        if (value2 == 1) {
            a3 = 2;
        } else {
            uint8_t a2;
            if (value2 == 2) {
                a2 = 4;
            } else {
                uint8_t value3 = RAM8(0x00BE);
                RAM8(0x00BE) = value3 ^ 1;
                uint8_t a1;
                if ((value3 ^ 1) & 0x01) {
                    a1 = 2;
                } else {
                    a1 = 4;
                }
                a2 = a1;
            }
            a3 = a2;
        }
        r->a = (r->a & 0x00FF) | (a3 << 8);
        r->x = (a3 << 8) | 0;
        r->c = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    if ((((value & 6) << 8) | 0) == 0x0200) {
        RAM8(0x0000) = 0;
        r->a = ((value & 6) << 8) | 0;
        r->x = 0;
        r->y = ((value & 6) << 8) | 0;
        r->xf = 0;
        JSR(c, 0xA98D, 0xC2A9F4); /* test_partner_actor_active_uncontrolled_and_status_available */
        bool carry_ret3 = r->c;
        if (!carry_ret3) {
            RAM8(0x0000)++;
        }
        r->x = 0x0400;
        r->mf = 1;
        r->xf = 0;
        JSR(c, 0xA997, 0xC2A9F4); /* test_partner_actor_active_uncontrolled_and_status_available */
        bool carry_ret4 = r->c;
        if (!carry_ret4) {
            RAM8(0x0000)++;
            RAM8(0x0000)++;
        }
        uint8_t value4 = RAM8(0x0000);
        if (value4 == 0) {
            r->c = 1;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        if (value4 == 1) {
            r->a = (r->a & 0x00FF) | (0 << 8);
            r->x = 0;
            r->c = 0;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        if (value4 == 2) {
            r->a = (r->a & 0x00FF) | (4 << 8);
            r->c = 0;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        uint8_t value5 = RAM8(0x00BE);
        RAM8(0x00BE) = value5 ^ 1;
        if ((value5 ^ 1) & 0x01) {
            r->a = (r->a & 0x00FF) | (0 << 8);
            r->x = 0;
            r->c = 0;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        if (!((value5 ^ 1) & 0x01)) {
            r->a = (r->a & 0x00FF) | (4 << 8);
            r->c = 0;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
        r->c = 1;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    RAM8(0x0000) = 0;
    r->a = ((value & 6) << 8) | 0;
    r->x = 0;
    r->y = ((value & 6) << 8) | 0;
    r->xf = 0;
    JSR(c, 0xA95E, 0xC2A9F4); /* test_partner_actor_active_uncontrolled_and_status_available */
    bool carry_ret5 = r->c;
    if (!carry_ret5) {
        RAM8(0x0000)++;
    }
    r->x = 0x0200;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xA968, 0xC2A9F4); /* test_partner_actor_active_uncontrolled_and_status_available */
    uint16_t a_all6 = r->a;
    bool carry_ret6 = r->c;
    if (!carry_ret6) {
        RAM8(0x0000)++;
        RAM8(0x0000)++;
    }
    uint8_t value6 = RAM8(0x0000);
    if (value6 == 0) {
        r->c = 1;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    if (value6 == 1) {
        r->a = (r->a & 0x00FF) | (0 << 8);
        r->x = 0;
        r->c = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    if (value6 == 2) {
        r->a = (r->a & 0x00FF) | (2 << 8);
        r->c = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    uint8_t value7 = RAM8(0x00BE);
    RAM8(0x00BE) = value7 ^ 1;
    if ((value7 ^ 1) & 0x01) {
        r->a = (r->a & 0x00FF) | (0 << 8);
        r->x = 0;
        r->c = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    if (!((value7 ^ 1) & 0x01)) {
        r->a = (r->a & 0x00FF) | (2 << 8);
        r->c = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    RAM8(0x0000) = 0;
    r->a = (a_all6 >> 8 << 8) | ((value7 ^ 1) >> 1);
    r->x = 0;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xA98D, 0xC2A9F4); /* test_partner_actor_active_uncontrolled_and_status_available */
    bool carry_ret7 = r->c;
    if (!carry_ret7) {
        RAM8(0x0000)++;
    }
    r->x = 0x0400;
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0xA997, 0xC2A9F4); /* test_partner_actor_active_uncontrolled_and_status_available */
    bool carry_ret8 = r->c;
    if (!carry_ret8) {
        RAM8(0x0000)++;
        RAM8(0x0000)++;
    }
    uint8_t value8 = RAM8(0x0000);
    if (value8 == 0) {
        r->c = 1;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    if (value8 == 1) {
        r->a = (r->a & 0x00FF) | (0 << 8);
        r->x = 0;
        r->c = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    if (value8 == 2) {
        r->a = (r->a & 0x00FF) | (4 << 8);
        r->c = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    uint8_t value9 = RAM8(0x00BE);
    RAM8(0x00BE) = value9 ^ 1;
    if ((value9 ^ 1) & 0x01) {
        r->a = (r->a & 0x00FF) | (0 << 8);
        r->x = 0;
        r->c = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    if (!((value9 ^ 1) & 0x01)) {
        r->a = (r->a & 0x00FF) | (4 << 8);
        r->c = 0;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTL(c);
    }
    r->c = 1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2A943, SOM_RTL, "hand", select_available_uncontrolled_partner_for_controller_menu, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, -1, 177, 87)
