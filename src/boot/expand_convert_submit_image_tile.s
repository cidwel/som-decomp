; Recovered Secret of Mana USA boot routine; behaviour documented in docs/boot.md.
.setcpu "65816"
.smart
.a8
.i16

convert_components_to_planar_tile = $9D1E

.segment "CODE"
.org $9E3D
expand_convert_submit_image_tile:
    phd
    php
    rep #$30
    tsc
    sec
    .a16
    sbc #$000B
    tcd
    tcs
    sep #$20
    stx $06
    sty $08
    .i16
    ldy #$0100
    lda $08
    clc
    .a8
    adc #$70
    sta $08
    .a8
    lda #$04
    sta $01
expand_convert_submit_image_tile_9e5c:
    .a8
    lda #$02
    sta $02
expand_convert_submit_image_tile_9e60:
    .a8
    lda #$04
    sta $03
expand_convert_submit_image_tile_9e64:
    .a8
    lda #$02
    sta $04
expand_convert_submit_image_tile_9e68:
    rep #$20
    lda a:$007E,X
    dex
    dex
    lsr
    lsr
    sep #$20
    sta $0A
    stz $0B
    .a8
    lda #$03
    sta $05
    dec $08
    dey
expand_convert_submit_image_tile_9e7e:
    dec $08
    lda ($08)
    clc
    adc $0A
    dey
    sta ($06),Y
    .a8
    bit #$80
    beq expand_convert_submit_image_tile_9e98
    cmp $0B
    bmi expand_convert_submit_image_tile_9e94
    bvc expand_convert_submit_image_tile_9e98
    bra expand_convert_submit_image_tile_9e96
expand_convert_submit_image_tile_9e94:
    bvs expand_convert_submit_image_tile_9e98
expand_convert_submit_image_tile_9e96:
    sta $0B
expand_convert_submit_image_tile_9e98:
    .a8
    cmp #$3F
    beq expand_convert_submit_image_tile_9eb2
    bmi expand_convert_submit_image_tile_9ea2
    bvs expand_convert_submit_image_tile_9eb2
    bra expand_convert_submit_image_tile_9ea4
expand_convert_submit_image_tile_9ea2:
    bvc expand_convert_submit_image_tile_9eb2
expand_convert_submit_image_tile_9ea4:
    cmp $0B
    beq expand_convert_submit_image_tile_9eb2
    bmi expand_convert_submit_image_tile_9eae
    bvs expand_convert_submit_image_tile_9eb2
    bra expand_convert_submit_image_tile_9eb0
expand_convert_submit_image_tile_9eae:
    bvc expand_convert_submit_image_tile_9eb2
expand_convert_submit_image_tile_9eb0:
    sta $0B
expand_convert_submit_image_tile_9eb2:
    dec $05
    bne expand_convert_submit_image_tile_9e7e
    iny
    iny
    iny
    .a8
    lda #$03
    sta $05
    lda $0B
    beq expand_convert_submit_image_tile_9f28
    .a8
    cmp #$3F
    bmi expand_convert_submit_image_tile_9ec9
    bvs expand_convert_submit_image_tile_9efe
    bra expand_convert_submit_image_tile_9ecb
expand_convert_submit_image_tile_9ec9:
    bvc expand_convert_submit_image_tile_9efe
expand_convert_submit_image_tile_9ecb:
    sec
    .a8
    sbc #$3F
    sta $0B
expand_convert_submit_image_tile_9ed0:
    dey
    lda ($06),Y
    .a8
    cmp #$3F
    beq expand_convert_submit_image_tile_9ee4
    bmi expand_convert_submit_image_tile_9edd
    bvs expand_convert_submit_image_tile_9ee4
    bra expand_convert_submit_image_tile_9edf
expand_convert_submit_image_tile_9edd:
    bvc expand_convert_submit_image_tile_9ee4
expand_convert_submit_image_tile_9edf:
    sec
    sbc $0B
    bra expand_convert_submit_image_tile_9ef5
expand_convert_submit_image_tile_9ee4:
    clc
    adc $0B
    .a8
    cmp #$3F
    beq expand_convert_submit_image_tile_9ef5
    bmi expand_convert_submit_image_tile_9ef1
    bvs expand_convert_submit_image_tile_9ef5
    bra expand_convert_submit_image_tile_9ef3
expand_convert_submit_image_tile_9ef1:
    bvc expand_convert_submit_image_tile_9ef5
expand_convert_submit_image_tile_9ef3:
    .a8
    lda #$3F
expand_convert_submit_image_tile_9ef5:
    lsr
    sta ($06),Y
    dec $05
    bne expand_convert_submit_image_tile_9ed0
    bra expand_convert_submit_image_tile_9f32
expand_convert_submit_image_tile_9efe:
    dey
    lda ($06),Y
    .a8
    cmp #$00
    bmi expand_convert_submit_image_tile_9f09
    bvc expand_convert_submit_image_tile_9f10
    bra expand_convert_submit_image_tile_9f0b
expand_convert_submit_image_tile_9f09:
    bvs expand_convert_submit_image_tile_9f10
expand_convert_submit_image_tile_9f0b:
    sec
    sbc $0B
    bra expand_convert_submit_image_tile_9f1f
expand_convert_submit_image_tile_9f10:
    clc
    adc $0B
    .a8
    cmp #$00
    bmi expand_convert_submit_image_tile_9f1b
    bvc expand_convert_submit_image_tile_9f1f
    bra expand_convert_submit_image_tile_9f1d
expand_convert_submit_image_tile_9f1b:
    bvs expand_convert_submit_image_tile_9f1f
expand_convert_submit_image_tile_9f1d:
    .a8
    lda #$00
expand_convert_submit_image_tile_9f1f:
    lsr
    sta ($06),Y
    dec $05
    bne expand_convert_submit_image_tile_9efe
    bra expand_convert_submit_image_tile_9f32
expand_convert_submit_image_tile_9f28:
    dey
    lda ($06),Y
    lsr
    sta ($06),Y
    dec $05
    bne expand_convert_submit_image_tile_9f28
expand_convert_submit_image_tile_9f32:
    lda $08
    clc
    .a8
    adc #$04
    sta $08
    dec $04
    beq expand_convert_submit_image_tile_9f40
    jmp expand_convert_submit_image_tile_9e68
expand_convert_submit_image_tile_9f40:
    sec
    .a8
    sbc #$04
    sta $08
    dec $03
    beq expand_convert_submit_image_tile_9f4c
    jmp expand_convert_submit_image_tile_9e64
expand_convert_submit_image_tile_9f4c:
    clc
    .a8
    adc #$10
    sta $08
    dec $02
    beq expand_convert_submit_image_tile_9f58
    jmp expand_convert_submit_image_tile_9e60
expand_convert_submit_image_tile_9f58:
    sec
    .a8
    sbc #$20
    sta $08
    dec $01
    beq expand_convert_submit_image_tile_9f64
    jmp expand_convert_submit_image_tile_9e5c
expand_convert_submit_image_tile_9f64:
    ldx $06
    jsr convert_components_to_planar_tile
    rep #$20
    tsc
    clc
    .a16
    adc #$000B
    tcs
    plp
    pld
    rts
