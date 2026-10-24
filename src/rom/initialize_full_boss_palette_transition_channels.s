; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

unpack_boss_palette_colors_to_fixed_point_channels = $28C6

.segment "CODE"
.org $27F2
initialize_full_boss_palette_transition_channels:
    ldx $87
    .a16
    lda #$0001
    sta a:$0094,X
    lda a:$009E,X
    xba
    lsr
    lsr
    lsr
    clc
    .a16
    adc #$0600
    sta $76
    sta a:$0029,X
    lda $87
    clc
    .a16
    adc #$0100
    sta $79
    sta a:$00A0,X
    .a16
    lda #$0020
    sta $66
    jsr unpack_boss_palette_colors_to_fixed_point_channels
    ldx $87
    .a16
    lda #$C200
    sta $77
    lda a:$009C,X
    asl
    tax
    lda f:$D0BB24,X
    sta $76
    ldx $C5
    txy
initialize_full_boss_palette_transition_channels_c22832:
    lda [$76],Y
    sta $95,X
    iny
    iny
    inx
    inx
    .i16
    cpx #$0020
    bcc initialize_full_boss_palette_transition_channels_c22832
    ldx $87
    .a16
    lda #$0295
    sta $76
    lda $87
    clc
    .a16
    adc #$0160
    sta $79
    sta a:$00A3,X
    .a16
    lda #$0020
    sta $66
    jsr unpack_boss_palette_colors_to_fixed_point_channels
    clc
    rts
