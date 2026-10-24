; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

divide_boss_palette_channel_deltas_by_duration = $2999

.segment "CODE"
.org $2976
derive_single_boss_palette_transition_channel_group:
    ldx $87
    .a16
    lda #$0002
    sta a:$0094,X
    lda a:$00A0,X
    sta $76
    lda a:$00A3,X
    sta $79
    .a16
    lda #$0006
    sta $66
    jsr divide_boss_palette_channel_deltas_by_duration
    clc
    rts
