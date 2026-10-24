; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $E0EB
prepare_map_object_load_window:
    sep #$20
    lda $BC
    bit $ED
    bpl prepare_map_object_load_window_c0e103
    .a8
    cmp #$04
    bcs prepare_map_object_load_window_c0e107
prepare_map_object_load_window_c0e0f7:
    rep #$20
    stz $04
    stz $06
    .a16
    lda #$FFFF
    sta $08
    rts
prepare_map_object_load_window_c0e103:
    .a8
    cmp #$0A
    bcc prepare_map_object_load_window_c0e0f7
prepare_map_object_load_window_c0e107:
    rep #$20
    .a16
    lda #$20F8
    sta $00
    .a16
    lda #$20F8
    sep #$20
    xba
    sta $09
    lda $01
    sta $08
    xba
    sta $01
    rep #$20
    lda $A8
    lsr
    lsr
    lsr
    lsr
    sep #$20
    clc
    bit $00
    bpl prepare_map_object_load_window_c0e134
    adc $00
    bpl prepare_map_object_load_window_c0e13c
    adc $9C
    bra prepare_map_object_load_window_c0e13c
prepare_map_object_load_window_c0e134:
    adc $00
    cmp $9C
    bcc prepare_map_object_load_window_c0e13c
    sbc $9C
prepare_map_object_load_window_c0e13c:
    sta $04
    rep #$20
    lda $AA
    lsr
    lsr
    lsr
    lsr
    sep #$20
    clc
    bit $01
    bpl prepare_map_object_load_window_c0e155
    adc $01
    bpl prepare_map_object_load_window_c0e15d
    adc $9D
    bra prepare_map_object_load_window_c0e15d
prepare_map_object_load_window_c0e155:
    adc $01
    cmp $9D
    bcc prepare_map_object_load_window_c0e15d
    sbc $9D
prepare_map_object_load_window_c0e15d:
    sta $05
    rep #$20
    lda $AC
    lsr
    lsr
    lsr
    lsr
    sep #$20
    clc
    bit $00
    bpl prepare_map_object_load_window_c0e176
    adc $00
    bpl prepare_map_object_load_window_c0e17e
    adc $A0
    bra prepare_map_object_load_window_c0e17e
prepare_map_object_load_window_c0e176:
    adc $00
    cmp $A0
    bcc prepare_map_object_load_window_c0e17e
    sbc $A0
prepare_map_object_load_window_c0e17e:
    sta $06
    rep #$20
    lda $AE
    lsr
    lsr
    lsr
    lsr
    sep #$20
    clc
    bit $01
    bpl prepare_map_object_load_window_c0e197
    adc $01
    bpl prepare_map_object_load_window_c0e19f
    adc $A1
    bra prepare_map_object_load_window_c0e19f
prepare_map_object_load_window_c0e197:
    adc $01
    cmp $A1
    bcc prepare_map_object_load_window_c0e19f
    sbc $A1
prepare_map_object_load_window_c0e19f:
    sta $07
    rts
