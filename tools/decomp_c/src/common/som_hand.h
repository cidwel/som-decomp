/* Helpers shared by hand-corrected routines (include after som_c.h). */
#ifndef SOM_HAND_H
#define SOM_HAND_H

/* PLP: reload all status flags from the byte at WRAM offset `off`. A callee that used the caller's direct page can
 * have changed that byte, so the restore must read it back instead of trusting the entry snapshot. */
static inline void som_pull_p(SomCtx *c, uint32_t off)
{
    Cpu *r = &c->cpu;
    uint8_t p = c->wram[off & 0x1FFFF];
    r->c = p & 1;
    r->z = (p >> 1) & 1;
    r->i = (p >> 2) & 1;
    r->d = (p >> 3) & 1;
    if (!r->e) {
        r->xf = (p >> 4) & 1;
        r->mf = (p >> 5) & 1;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }   /* X=1 clears the index high bytes */
    }
    r->v = (p >> 6) & 1;
    r->n = p >> 7;
}
#endif
