#include "som_c.h"

/* C2AF7D initialize_scene_quadratic_curve_hdma_bytes   [class B, 44 bytes, 22 instructions]
 * Source: src/rom/initialize_scene_quadratic_curve_hdma_bytes.s
 * Documented in docs/ui-native-scene-setup.md
 * Entry: M=any X=any DB=any D=any.  Callers read: BYCV.
 */
static void initialize_scene_quadratic_curve_hdma_bytes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    uint8_t a_hi1 = a >> 8;
    uint8_t x1 = 7;
    for (;;) {
        uint8_t value = BUS8(c, 0x02AF75 + x1);
        BUS8_SET(c, (db << 0x10) + 0x0F00 + x1, value);
        x1 = (uint8_t)(x1 - 1);
        if (!(!(x1 & 0x80))) break;
    }
    uint8_t a_hi2 = a_hi1;
    uint8_t x2 = 0;
    uint8_t y1 = (uint8_t)y;
    bool overflow1 = overflow;
    for (;;) {
        r->a = (a_hi2 << 8) | (uint8_t)((x2 ^ 0x3F) + 1);
        r->x = x2;
        r->y = y1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 1;
        r->db = db;
        r->dp = dp;
        JSR(c, 0xAF93, 0xC2AFA9); /* compute_scene_curve_square_over_one_hundred_forty_four */
        uint16_t a_all = r->a;
        BUS8_SET(c, (db << 0x10) + 0x0F08 + x2, (uint8_t)a_all | 0xE0);
        a_hi2 = a_all >> 8;
        x2 = (uint8_t)(x2 + 1);
        if (!(x2 < 0x40)) break;
    }
    uint8_t x3 = x2;
    bool carry1 = 0;
    for (;;) {
        BUS8_SET(c, (db << 0x10) + 0x0F08 + x3, 0xE0);
        uint8_t x3_next = (uint8_t)(x3 + 1);
        bool carry1_next = (uint8_t)(x3 + 1) >= 0x98;
        x3 = x3_next;
        carry1 = carry1_next;
        if (!(x3 < 0x98)) break;
    }
    r->a = (a_hi2 << 8) | 0xE0;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 1;
    r->db = db;
    r->dp = dp;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2AF7D, SOM_RTL, "gen", initialize_scene_quadratic_curve_hdma_bytes, 0, L_B | L_Y | L_C | L_V, 1, -1, -1, 44, 22)
