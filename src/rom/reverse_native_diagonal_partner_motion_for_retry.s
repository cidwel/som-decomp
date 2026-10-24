; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-party-obstacle-detour.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B929
reverse_native_diagonal_partner_motion_for_retry:
    sep #$20
    .a8
    lda #$00
    sta a:$E02D,X
    lda a:$E007,X
    .a8
    eor #$80
    sta a:$E007,X
    .a8
    lda #$20
    sta a:$E00A,X
    rts
