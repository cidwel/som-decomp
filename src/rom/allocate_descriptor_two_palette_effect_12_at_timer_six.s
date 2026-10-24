; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-two-palette.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_palette_transition_object = $272D

.segment "CODE"
.org $41D8
allocate_descriptor_two_palette_effect_12_at_timer_six:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0006
    bne allocate_descriptor_two_palette_effect_12_at_timer_six_c241f6
    .a16
    lda #$0003
    .i16
    ldx #$0012
    .i16
    ldy #$8F0D
    jsr allocate_boss_palette_transition_object
    ldx $87
    dec a:$0094,X
    stz a:$0096,X
allocate_descriptor_two_palette_effect_12_at_timer_six_c241f6:
    clc
    rts
