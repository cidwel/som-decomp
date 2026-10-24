; Recovered Secret of Mana USA routine; behaviour documented in docs/graphics.md.
.setcpu "65816"
.smart
.a8
.i16

unpack_boss_palette_colors_to_fixed_point_channels = $28C6

.segment "CODE"
.org $285B
initialize_single_boss_palette_transition_channels:
    ldx $87
    inc a:$0094,X
    lda a:$009E,X
    .a16
    and #$0F00
    xba
    asl
    sta $68
    lda a:$009E,X
    .a16
    and #$000F
    xba
    lsr
    lsr
    lsr
    clc
    .a16
    adc #$0600
    adc $68
    sta $76
    sta a:$0029,X
    lda $87
    clc
    .a16
    adc #$0030
    sta $79
    sta a:$00A0,X
    .a16
    lda #$0002
    sta $66
    jsr unpack_boss_palette_colors_to_fixed_point_channels
    ldx $87
    lda a:$009C,X
    asl
    tax
    lda $68
    clc
    adc f:$D0BB24,X
    tax
    .i16
    ldy #$0295
    .a16
    lda #$0001
    mvn #$C2, #$7E
    ldx $87
    .a16
    lda #$0295
    sta $76
    lda $87
    clc
    .a16
    adc #$0036
    sta $79
    sta a:$00A3,X
    .a16
    lda #$0002
    sta $66
    jsr unpack_boss_palette_colors_to_fixed_point_channels
    clc
    rts
