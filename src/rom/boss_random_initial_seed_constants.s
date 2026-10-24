; Typed RNG initial seed constants; docs/boss-frame-random-initialize.md.
.setcpu "65816"
.segment "CODE"
.org $308B
boss_random_initial_seed_constants:
    .byte $9C, $F6, $F8, $63, $D9, $DB, $CB, $EC
    .byte $5E, $23, $1E, $10, $9B, $40, $61, $40
    .byte $7E, $1E, $82, $6B, $7A, $32, $74, $02
    .byte $FE, $6A, $27, $F6, $FA, $35, $08, $B6
    .byte $5F, $05, $8B, $B2, $1B, $C8, $1C, $D8
    .byte $1E, $F0, $2E, $1B, $DA, $EB, $B0, $6B
    .byte $BD, $A9, $91, $36, $39, $1D, $43
