#include "som_c.h"

/* C047DD classify_actor_appearance_from_sprite   [class B, 131 bytes, 58 instructions]
 * Source: src/rom/classify_actor_appearance_from_sprite.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void classify_actor_appearance_from_sprite(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0xE180 + x);
    uint8_t value2 = BUS8(c, 0xD0000F + ((((a_hi << 8) | value) & 0xFF) << 1 << 1 << 1 << 1));
    uint16_t value3 = RAM16(0x03BD);
    RAM8(ACTOR_HIT_SOUND + value3) = value2;
    RAM8(ACTOR_KIND_FLAGS + value3) &= 0x0E;
    uint8_t value5 = RAM8(0xE1E7 + value3);
    if (value5 & 0x80) {
        if (value5 >= 0x83) {
            RAM8(ACTOR_KIND_FLAGS + value3) |= 0x20;
            r->a = (r->a & 0x00FF) | (((((a_hi << 8) | value) & 0xFF) << 1 << 1 << 1 << 1 >> 8) << 8);
            r->x = value3;
            r->c = value5 >= 0x83;
            RETURN_RTS(c);
        }
        RAM8(ACTOR_KIND_FLAGS + value3) |= 0x80;
        RAM8(ACTOR_DAMAGE_BONUS_ROOT + value3) = RAM8(0xCFFC);
        r->a = (r->a & 0x00FF) | (((((a_hi << 8) | value) & 0xFF) << 1 << 1 << 1 << 1 >> 8) << 8);
        r->x = value3;
        r->c = value5 >= 0x83;
        RETURN_RTS(c);
    }
    if (value5 == 0x2E) {
        RAM8(ACTOR_KIND_FLAGS + value3) |= 1;
        r->a = (r->a & 0x00FF) | (((((a_hi << 8) | value) & 0xFF) << 1 << 1 << 1 << 1 >> 8) << 8);
        r->x = value3;
        r->c = value5 >= 0x2E;
        RETURN_RTS(c);
    }
    if (value5 == 0x3F) {
        RAM8(ACTOR_KIND_FLAGS + value3) |= 1;
        r->a = (r->a & 0x00FF) | (((((a_hi << 8) | value) & 0xFF) << 1 << 1 << 1 << 1 >> 8) << 8);
        r->x = value3;
        r->c = value5 >= 0x3F;
        RETURN_RTS(c);
    }
    if (value5 == 0x20) {
        RAM8(ACTOR_KIND_FLAGS + value3) |= 1;
        r->a = (r->a & 0x00FF) | (((((a_hi << 8) | value) & 0xFF) << 1 << 1 << 1 << 1 >> 8) << 8);
        r->x = value3;
        r->c = value5 >= 0x20;
        RETURN_RTS(c);
    }
    RAM8(ACTOR_DAMAGE_BONUS_ROOT + value3) = RAM8(0xCFFB);
    uint8_t value13 = RAM8(0xE1E7 + value3);
    if (value13 < 0x57) {
        if (value13 < 0x55) {
            r->a = (r->a & 0x00FF) | (((((a_hi << 8) | value) & 0xFF) << 1 << 1 << 1 << 1 >> 8) << 8);
            r->x = value3;
            r->c = value13 >= 0x55;
            RETURN_RTS(c);
        }
        RAM8(ACTOR_KIND_FLAGS + value3) |= 0x10;
        RAM8(ACTOR_STATUS + value3) = 0x20;
        r->a = (r->a & 0x00FF) | (((((a_hi << 8) | value) & 0xFF) << 1 << 1 << 1 << 1 >> 8) << 8);
        r->x = value3;
        r->c = value13 >= 0x55;
        RETURN_RTS(c);
    }
    RAM8(ACTOR_KIND_FLAGS + value3) |= 0x40;
    r->a = (r->a & 0x00FF) | (((((a_hi << 8) | value) & 0xFF) << 1 << 1 << 1 << 1 >> 8) << 8);
    r->x = value3;
    r->c = value13 >= 0x57;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC047DD, SOM_RTS, "gen", classify_actor_appearance_from_sprite, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 131, 58)
