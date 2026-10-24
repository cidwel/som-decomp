; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $BD8D
build_map_palette_color_ramp:
    lda $00
    asl
    asl
    asl
    xba
    sep #$30
    .a8
    and #$1F
    sta $05
    lda $00
    .a8
    and #$1F
    sta $04
    lda $01
    lsr
    lsr
    .a8
    and #$1F
    sta $06
    rep #$20
    lda $02
    asl
    asl
    asl
    xba
    sep #$20
    .a8
    and #$1F
    sta $08
    lda $02
    .a8
    and #$1F
    sta $07
    lda $03
    lsr
    lsr
    .a8
    and #$1F
    sta $09
    .a8
    lda #$00
    sta $00
build_map_palette_color_ramp_c2bdc7:
    lda $03
    bpl build_map_palette_color_ramp_c2bdce
    jmp build_map_palette_color_ramp_c2be94
build_map_palette_color_ramp_c2bdce:
    ldx $04
    lda $00
    bne build_map_palette_color_ramp_c2bdd8
    ldx $07
    bra build_map_palette_color_ramp_c2be09
build_map_palette_color_ramp_c2bdd8:
    inc
    beq build_map_palette_color_ramp_c2be09
    xba
    txa
    sta f:$004202
    xba
    sta f:$004203
    .a8
    eor #$FF
    inc
    tax
    ldy $07
    rep #$20
    lda f:$004216
    pha
    sep #$20
    txa
    xba
    tya
    rep #$20
    sta f:$004202
    pla
    nop
    clc
    adc f:$004216
    xba
    sep #$20
    tax
build_map_palette_color_ramp_c2be09:
    stx $02
    ldx $06
    lda $00
    bne build_map_palette_color_ramp_c2be15
    ldx $09
    bra build_map_palette_color_ramp_c2be47
build_map_palette_color_ramp_c2be15:
    inc
    beq build_map_palette_color_ramp_c2be47
    xba
    txa
    sta f:$004202
    xba
    sta f:$004203
    .a8
    eor #$FF
    inc
    tax
    ldy $09
    rep #$20
    lda f:$004216
    pha
    sep #$20
    txa
    xba
    tya
    rep #$20
    sta f:$004202
    pla
    nop
    nop
    clc
    adc f:$004216
    xba
    sep #$20
    tax
build_map_palette_color_ramp_c2be47:
    stx $03
    ldx $05
    lda $00
    bne build_map_palette_color_ramp_c2be53
    ldx $08
    bra build_map_palette_color_ramp_c2be84
build_map_palette_color_ramp_c2be53:
    inc
    beq build_map_palette_color_ramp_c2be84
    xba
    txa
    sta f:$004202
    xba
    sta f:$004203
    .a8
    eor #$FF
    inc
    tax
    ldy $08
    rep #$20
    lda f:$004216
    pha
    sep #$20
    txa
    xba
    tya
    rep #$20
    sta f:$004202
    pla
    nop
    clc
    adc f:$004216
    xba
    sep #$20
    tax
build_map_palette_color_ramp_c2be84:
    txa
    asl
    asl
    asl
    asl
    rol $03
    asl
    rol $03
    ora $02
    sta $02
    .i8
    ldy #$00
build_map_palette_color_ramp_c2be94:
    rep #$20
    lda $02
    sta ($18),Y
    lda $18
    clc
    .a16
    adc #$001E
    sta $18
    sep #$20
    lda $00
    clc
    .a8
    adc #$11
    sta $00
    bcs build_map_palette_color_ramp_c2beb0
    jmp build_map_palette_color_ramp_c2bdc7
build_map_palette_color_ramp_c2beb0:
    rts
