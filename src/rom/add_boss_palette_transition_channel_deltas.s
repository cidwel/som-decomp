; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2A17
add_boss_palette_transition_channel_deltas:
    ldy $C5
add_boss_palette_transition_channel_deltas_c22a19:
    clc
    lda ($76),Y
    adc ($79),Y
    sta ($76),Y
    iny
    iny
    cpy $66
    bne add_boss_palette_transition_channel_deltas_c22a19
    rts
