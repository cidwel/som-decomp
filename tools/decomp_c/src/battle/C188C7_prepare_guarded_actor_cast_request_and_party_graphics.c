#include "som_c.h"

/* C188C7 prepare_guarded_actor_cast_request_and_party_graphics   [class B, 134 bytes, 57 instructions]
 * Source: src/rom/prepare_guarded_actor_cast_request_and_party_graphics.s
 * Documented in docs/actor-cast-request-setup.md
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void prepare_guarded_actor_cast_request_and_party_graphics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    RAM16_SET(0x0014, x);
    uint8_t value = RAM8(0x00F1);
    if (value & 0x80) {
        r->v = value & 0x40;
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint8_t value2 = RAM8(0x00D0);
    if (value2 == 0) {
        uint8_t value3 = RAM8(0xE000 + x);
        if (value3 == 0) {
            SET_A8(r, value3);
            r->v = value & 0x40;
            r->mf = 1;
            RETURN_RTS(c);
        }
        if (value3 & 0x80) {
            SET_A8(r, value3);
            r->v = value & 0x40;
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint8_t value4 = RAM8(0xE060 + x);
        if (value4 == 0) {
            RAM8(0xE111 + x) = 0;
            if (((RAM8(0xE179 + x) | RAM8(0xE17A + x)) & 7) != 0) {
                RAM8(0xE111 + x) = 0x80;
            }
            uint8_t value7 = RAM8(0xE171 + x);
            uint8_t value8 = RAM8(0xE111 + x);
            RAM8(0xE111 + x) = (value7 & 0x0F) | value8;
            RAM8(0xE108 + x) = 0;
            if (x < 0x0600) {
                uint8_t a1;
                if (x < 0x0400) {
                    a1 = 0xCE;
                } else {
                    a1 = 0xCF;
                }
                RAM8(0xE04F + x) = a1;
                RAM8(0xE01C + x) = 0x40;
                RAM8(0xE030 + x) = 0xFF;
                RAM8(0xE011 + x) = 0x94;
                RAM8(0xE006 + x) = 0;
                RAM8(0xE007 + x) = 0;
                RAM8(0xE008 + x) = 0;
                RAM8(0xE060 + x) = 0x20;
                r->c = x >= 0x0400;
                r->v = value & 0x40;
                r->mf = 1;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8944, 0xC18634); GUARD_JSR(c, sp_call, 0x8944); } /* load_actor_cast_secondary_graphics */
                r->mf = 1;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSR(c, 0x8947, 0xC185D8); GUARD_JSR(c, sp_call, 0x8947); } /* load_object_weapon_palette_from_field_04f */
                r->x = RAM16(0x0014);
                r->xf = 0;
                RETURN_RTS(c);
            }
            r->a = (a >> 8 << 8) | ((value7 & 0x0F) | value8);
            r->c = x >= 0x0600;
            r->v = value & 0x40;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x890B, 0xC18898); GUARD_JSR(c, sp_call, 0x890B); } /* prepare_actor_cast_directional_offset */
            RAM8(0xE060 + x) = 0x20;
            uint16_t value10 = RAM16(0x0014);
            SET_A8(r, 0x20);
            r->x = value10;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTS(c);
        }
        SET_A8(r, value4);
        r->v = value & 0x40;
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint16_t value11 = RAM16(0x00D4);
    if (x == value11) {
        SET_A8(r, value2);
        r->c = x >= value11;
        r->v = value & 0x40;
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint8_t value12 = RAM8(0xE000 + x);
    if (value12 == 0) {
        SET_A8(r, value12);
        r->c = x >= value11;
        r->v = value & 0x40;
        r->mf = 1;
        RETURN_RTS(c);
    }
    if (value12 & 0x80) {
        SET_A8(r, value12);
        r->c = x >= value11;
        r->v = value & 0x40;
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint8_t value13 = RAM8(0xE060 + x);
    if (value13 == 0) {
        RAM8(0xE111 + x) = 0;
        if (((RAM8(0xE179 + x) | RAM8(0xE17A + x)) & 7) != 0) {
            RAM8(0xE111 + x) = 0x80;
        }
        uint8_t value16 = RAM8(0xE171 + x);
        uint8_t value17 = RAM8(0xE111 + x);
        RAM8(0xE111 + x) = (value16 & 0x0F) | value17;
        RAM8(0xE108 + x) = 0;
        if (x < 0x0600) {
            uint8_t a2;
            if (x < 0x0400) {
                a2 = 0xCE;
            } else {
                a2 = 0xCF;
            }
            RAM8(0xE04F + x) = a2;
            RAM8(0xE01C + x) = 0x40;
            RAM8(0xE030 + x) = 0xFF;
            RAM8(0xE011 + x) = 0x94;
            RAM8(0xE006 + x) = 0;
            RAM8(0xE007 + x) = 0;
            RAM8(0xE008 + x) = 0;
            RAM8(0xE060 + x) = 0x20;
            r->c = x >= 0x0400;
            r->v = value & 0x40;
            r->mf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8944, 0xC18634); GUARD_JSR(c, sp_call, 0x8944); } /* load_actor_cast_secondary_graphics */
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8947, 0xC185D8); GUARD_JSR(c, sp_call, 0x8947); } /* load_object_weapon_palette_from_field_04f */
            r->x = RAM16(0x0014);
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = (a >> 8 << 8) | ((value16 & 0x0F) | value17);
        r->c = x >= 0x0600;
        r->v = value & 0x40;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x890B, 0xC18898); GUARD_JSR(c, sp_call, 0x890B); } /* prepare_actor_cast_directional_offset */
        RAM8(0xE060 + x) = 0x20;
        uint16_t value19 = RAM16(0x0014);
        SET_A8(r, 0x20);
        r->x = value19;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
    SET_A8(r, value13);
    r->c = x >= value11;
    r->v = value & 0x40;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC188C7, SOM_RTS, "gen", prepare_guarded_actor_cast_request_and_party_graphics, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, -1, 0, 134, 57)
