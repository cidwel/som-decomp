; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

apply_map_tile_separate_sign_delta = $A15B
apply_map_tile_signed_six_bit_delta = $A17C
read_map_tile_absolute_word = $A19D
read_map_tile_six_bit_value = $A227
update_map_tile_word_attributes = $A282

.segment "CODE"
.org $A069
decode_map_tile_word_layers:
    sep #$30
    lda $1C
    .a8
    and #$3F
    sta $00
    asl
    clc
    adc $00
    tax
    rep #$20
    lda f:$CB4000,X
    sta $10
    lda f:$CB4002,X
    .a16
    ora #$00C0
    sta $12
    .a16
    lda #$C000
    sta $14
    .a16
    lda #$C800
    sta $16
    .a16
    lda #$0300
    sta $18
    stz $04
    sep #$20
    .i8
    ldy #$00
    lda [$10],Y
    sta $00
    .i8
    ldx #$04
decode_map_tile_word_layers_c2a0a2:
    sep #$20
    asl $00
    rol
    asl $00
    rol
    dex
    bne decode_map_tile_word_layers_c2a0bf
    .i8
    ldx #$04
    inc $10
    bne decode_map_tile_word_layers_c2a0b9
    inc $11
    bne decode_map_tile_word_layers_c2a0b9
    inc $12
decode_map_tile_word_layers_c2a0b9:
    pha
    lda [$10],Y
    sta $00
    pla
decode_map_tile_word_layers_c2a0bf:
    .a8
    and #$03
    beq decode_map_tile_word_layers_c2a0d1
    .a8
    cmp #$03
    beq decode_map_tile_word_layers_c2a11b
    .a8
    cmp #$01
    bne decode_map_tile_word_layers_c2a0cf
    inc $04
    bra decode_map_tile_word_layers_c2a0d1
decode_map_tile_word_layers_c2a0cf:
    dec $04
decode_map_tile_word_layers_c2a0d1:
    rep #$20
    lda $04
    bit $1B
    bpl decode_map_tile_word_layers_c2a0ff
    bvc decode_map_tile_word_layers_c2a0f3
    dec $18
    bpl decode_map_tile_word_layers_c2a0a2
decode_map_tile_word_layers_c2a0df:
    sta ($14),Y
    inc $14
    inc $14
decode_map_tile_word_layers_c2a0e5:
    sta ($16),Y
    lda $16
    inc
    inc
    sta $16
    .a16
    cmp #$CE00
    bcc decode_map_tile_word_layers_c2a0a2
    rts
decode_map_tile_word_layers_c2a0f3:
    dec $18
    bmi decode_map_tile_word_layers_c2a0e5
    sta ($14),Y
    inc $14
    inc $14
    bra decode_map_tile_word_layers_c2a0a2
decode_map_tile_word_layers_c2a0ff:
    bvc decode_map_tile_word_layers_c2a0df
    dec $18
    bmi decode_map_tile_word_layers_c2a10d
    sta ($16),Y
    inc $16
    inc $16
    bra decode_map_tile_word_layers_c2a0a2
decode_map_tile_word_layers_c2a10d:
    sta ($14),Y
    lda $14
    inc
    inc
    sta $14
    .a16
    cmp #$C600
    bcc decode_map_tile_word_layers_c2a0a2
    rts
decode_map_tile_word_layers_c2a11b:
    asl $00
    rol
    asl $00
    rol
    dex
    bne decode_map_tile_word_layers_c2a136
    .i8
    ldx #$04
    inc $10
    bne decode_map_tile_word_layers_c2a130
    inc $11
    bne decode_map_tile_word_layers_c2a130
    inc $12
decode_map_tile_word_layers_c2a130:
    pha
    lda [$10],Y
    sta $00
    pla
decode_map_tile_word_layers_c2a136:
    .a8
    and #$03
    .a8
    cmp #$02
    bcs decode_map_tile_word_layers_c2a147
    sta $01
    jsr read_map_tile_six_bit_value
    jsr apply_map_tile_separate_sign_delta
    jmp decode_map_tile_word_layers_c2a0d1
decode_map_tile_word_layers_c2a147:
    bne decode_map_tile_word_layers_c2a155
    jsr update_map_tile_word_attributes
    jsr read_map_tile_six_bit_value
    jsr apply_map_tile_signed_six_bit_delta
    jmp decode_map_tile_word_layers_c2a0d1
decode_map_tile_word_layers_c2a155:
    jsr read_map_tile_absolute_word
    jmp decode_map_tile_word_layers_c2a0d1
