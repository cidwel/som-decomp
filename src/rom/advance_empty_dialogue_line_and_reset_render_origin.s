; Recovered Secret of Mana USA routine; behaviour documented in docs/event-dialogue-font-rows.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c0197c = $197C

.segment "CODE"
.org $13CD
advance_empty_dialogue_line_and_reset_render_origin:
    lda f:$001D00
    .a8
    ora #$01
    sta f:$001D00
    lda a:$A197
    sta a:$A17D
    lda a:$A17C
    inc
    inc
    sta a:$A17C
    inc a:$A15D
    rep #$20
    lda a:$A17E
    asl
    asl
    asl
    clc
    .a16
    adc #$4000
    sta a:$A18C
    sep #$20
    jsr routine_c0197c
    rts
