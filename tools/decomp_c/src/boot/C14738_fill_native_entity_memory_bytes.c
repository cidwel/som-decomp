#include "som_c.h"
#include "som_hand.h"

/* C14738 fill_native_entity_memory_bytes   [class B, 41 bytes, 27 instructions]
 * Source: src/rom/fill_native_entity_memory_bytes.s
 * Documented in docs/actor-cast-entity-memory.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: BYCV.
 */
static void fill_native_entity_memory_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    uint16_t x = r->x;
    uint16_t y = r->y;
    uint8_t a_hi = r->a >> 8;

    /* PHD, PHP, REP #$30, SEP #$20, PHA: the fill below may overwrite the pushed byte */
    RAM8(sp0) = r->dp >> 8;
    RAM8((uint16_t)(sp0 - 1)) = (uint8_t)r->dp;
    RAM8((uint16_t)(sp0 - 2)) = hand_p_byte(r);
    RAM8((uint16_t)(sp0 - 3)) = (uint8_t)r->a;
    RAM8(x) = (uint8_t)r->a;   /* STA a:$0000,X */
    if (y & 1) {               /* TYA, AND #$01, BEQ */
        x = (uint16_t)(x + 1);
        y = (uint16_t)(y - 1);
        if (y == 0) goto done;
    }
    {
        const uint8_t v = RAM8((uint16_t)(sp0 - 3));   /* LDA $01,S; XBA; LDA $01,S */
        a_hi = v;
        do {
            RAM16_SET(x, (uint16_t)((v << 8) | v));
            x = (uint16_t)(x + 2);
            y = (uint16_t)(y - 2);
        } while (y != 0);
    }
done:
    r->x = x;
    r->y = y;
    r->a = (uint16_t)((a_hi << 8) | RAM8((uint16_t)(sp0 - 3)));   /* PLA */
    r->sp = (uint16_t)(sp0 - 3);
    hand_plp(c);
    hand_pld(c);
    r->z = r->dp == 0;
    r->n = (r->dp & 0x8000) != 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC14738, SOM_RTS, "hand", fill_native_entity_memory_bytes, 0, L_B | L_Y | L_C | L_V, 4, 1, 0, 41, 27)
