; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-setup.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_palette_transition_object = $272D
copy_boss_palette_with_cpu_words = $26F9
draw_boss_frame_random_number = $300B
request_boss_sound_with_parameter_word = $30E3

.segment "CODE"
.org $8528
choose_native59_distinct_color_and_publish_status_palette_sound:
    stz a:$0096,X
    .a16
    lda #$0003
    jsr draw_boss_frame_random_number
    ldx $87
    cmp a:$00B0,X
    beq choose_native59_distinct_color_and_publish_status_palette_sound_c28574
    sta a:$00B0,X
    asl
    tax
    lda f:$C28575,X
    ldx $87
    sta a:$0192,X
    lda a:$00B0,X
    clc
    .a16
    adc #$005B
    .i16
    ldx #$0007
    sep #$20
    sta a:$033F,X
    rep #$20
    txy
    tax
    .a16
    lda #$0010
    jsr allocate_boss_palette_transition_object
    .a16
    lda #$0086
    jsr request_boss_sound_with_parameter_word
    ldx $87
    lda a:$00B0,X
    clc
    .a16
    adc #$005B
    .i16
    ldx #$000D
    jsr copy_boss_palette_with_cpu_words
choose_native59_distinct_color_and_publish_status_palette_sound_c28574:
    rts
