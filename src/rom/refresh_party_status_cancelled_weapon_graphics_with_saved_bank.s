; Recovered Secret of Mana USA routine; behaviour documented in docs/hero-controller-action-gates.md.
.setcpu "65816"
.smart
.a8
.i16

routine_02afd0 = $2AFD0

.segment "CODE"
.org $B31F
refresh_party_status_cancelled_weapon_graphics_with_saved_bank:
    phb
    .a8
    lda #$7E
    pha
    plb
    jsl f:routine_02afd0
    plb
    rts
