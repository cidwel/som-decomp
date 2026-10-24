; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c09a06 = $9A06

.segment "CODE"
.org $AA14
construct_all_world_map_picker_image_rows:
    rep #$20
    stz $10
    stz $12
    sep #$20
    .a8
    lda #$01
    sta a:$2183
construct_all_world_map_picker_image_rows_c0aa21:
    sep #$30
    lda $10
    bpl construct_all_world_map_picker_image_rows_c0aa29
    .a8
    eor #$FE
construct_all_world_map_picker_image_rows_c0aa29:
    pha
    .a8
    eor #$7E
    lsr
    tax
    lda a:$A798,X
    rep #$20
    .a16
    and #$00FF
    ldx $10
    bmi construct_all_world_map_picker_image_rows_c0aa3e
    .a16
    eor #$FFFF
    inc
construct_all_world_map_picker_image_rows_c0aa3e:
    clc
    adc $0A
    .a16
    and #$01FF
    rep #$30
    tay
    .a16
    lda #$0B00
    tcd
    .a16
    lda #$FE00
    sta a:$2181
    jsr routine_c09a06
    sep #$30
    .a8
    lda #$7F
    pha
    plb
    rep #$20
    plx
    lda a:$5000,X
    sta $02
    lda a:$5080,X
    sta $00
    lda $10
    xba
    lsr
    lsr
    .a16
    adc #$0040
    sec
    sbc $00
    sta f:$002181
    sep #$20
    .a8
    lda #$01
    sta f:$002183
    rep #$20
    lda $00
    asl
    sta $04
    tay
    dey
    dey
    rep #$10
construct_all_world_map_picker_image_rows_c0aa8a:
    lda $08
    sec
    sbc ($02),Y
    .a16
    and #$01FF
    tax
    sep #$20
    lda a:$FE00,X
    sta f:$002180
    rep #$20
    dey
    dey
    bpl construct_all_world_map_picker_image_rows_c0aa8a
    iny
    iny
construct_all_world_map_picker_image_rows_c0aaa4:
    lda ($02),Y
    clc
    adc $08
    .a16
    and #$01FF
    tax
    sep #$20
    lda a:$FE00,X
    sta f:$002180
    rep #$20
    iny
    iny
    cpy $04
    bcc construct_all_world_map_picker_image_rows_c0aaa4
    sep #$30
    .a8
    lda #$00
    pha
    plb
    inc $10
    inc $10
    beq construct_all_world_map_picker_image_rows_c0aacd
    jmp construct_all_world_map_picker_image_rows_c0aa21
construct_all_world_map_picker_image_rows_c0aacd:
    inc $0E
    stz $1E
    rts
