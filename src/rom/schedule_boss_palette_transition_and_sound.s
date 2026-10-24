; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_palette_transition_object = $272D
request_boss_sound_with_parameter_word = $30E3

.segment "CODE"
.org $65ED
schedule_boss_palette_transition_and_sound:
    lda a:$007E,X
    clc
    .a16
    adc #$0078
    .i16
    ldx #$000E
    sep #$20
    sta a:$033F,X
    rep #$20
    txy
    tax
    .a16
    lda #$0020
    jsr allocate_boss_palette_transition_object
    .a16
    lda #$0086
    .i16
    ldx #$000F
    jsr request_boss_sound_with_parameter_word
    rts
