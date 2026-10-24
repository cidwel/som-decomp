; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native70-palette-cycle.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_palette_transition_object = $272D

.segment "CODE"
.org $D431
advance_native70_second_palette_transition_at_six_ticks:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0006
    bne advance_native70_second_palette_transition_at_six_ticks_c2d44f
    .a16
    lda #$0003
    .i16
    ldx #$0016
    .i16
    ldy #$8F0D
    jsr allocate_boss_palette_transition_object
    ldx $87
    dec a:$0094,X
    stz a:$0096,X
advance_native70_second_palette_transition_at_six_ticks_c2d44f:
    clc
    rts
