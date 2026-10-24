; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-phase.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6C4F
reset_native_ring_phase_direction_and_description_request:
    stz a:$1812
    stz a:$1814
    .a16
    lda #$0024
    sta a:$181E
    sep #$20
    lda a:$1801
    .a8
    and #$FC
    sta a:$1801
    .a8
    lda #$04
    tsb a:$1802
    stz a:$1806
