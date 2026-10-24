; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-queued-effect-requests.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c18686 = $8686

.segment "CODE"
.org $86C6
load_queued_native_motion_presentation_graphics:
    rep #$20
    sty $14
    lda f:$D04158,X
    jmp routine_c18686
