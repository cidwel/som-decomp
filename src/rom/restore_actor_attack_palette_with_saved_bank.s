; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-attack-entry.md.
.setcpu "65816"
.smart
.a8
.i16

routine_01ca04 = $1CA04

.segment "CODE"
.org $B313
restore_actor_attack_palette_with_saved_bank:
    phb
    .a8
    lda #$7E
    pha
    plb
    sec
    jsl f:routine_01ca04
    plb
    rts
