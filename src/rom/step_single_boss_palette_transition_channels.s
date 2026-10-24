; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

add_boss_palette_transition_channel_deltas = $2A17
pack_boss_palette_fixed_point_channels = $2A27

.segment "CODE"
.org $29EA
step_single_boss_palette_transition_channels:
    ldx $87
    lda a:$00A0,X
    sta $76
    lda a:$00A3,X
    sta $79
    .a16
    lda #$0006
    sta $66
    jsr add_boss_palette_transition_channel_deltas
    lda a:$0029,X
    sta $79
    .a16
    lda #$0006
    sta $66
    jsr pack_boss_palette_fixed_point_channels
    ldx $87
    dec a:$009A,X
    bne step_single_boss_palette_transition_channels_c22a15
    inc a:$0094,X
step_single_boss_palette_transition_channels_c22a15:
    clc
    rts
