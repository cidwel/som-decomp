; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-composition.md.
.setcpu "65816"
.smart
.a8
.i16

await_world_map_survey_nmi_acknowledgement = $AFA3

.segment "CODE"
.org $AE96
average_four_world_map_pixels_and_pack_all_eight_bitplanes:
    rep #$20
    lda $10
    sec
    sbc $14
    asl
    asl
    asl
    asl
    asl
    asl
    sta a:$2116
    sep #$20
    phb
    .a8
    lda #$7F
    pha
    plb
    rep #$10
    .i16
    ldy #$0000
average_four_world_map_pixels_and_pack_all_eight_bitplanes_c0aeb2:
    sep #$20
    .a8
    lda #$00
    xba
    lda a:$E000,Y
    tax
    lda a:$D800,X
    sta $00
    lda a:$D900,X
    sta $01
    lda a:$DA00,X
    sta $02
    lda a:$E001,Y
    tax
    lda a:$D800,X
    clc
    adc $00
    sta $00
    lda a:$D900,X
    clc
    adc $01
    sta $01
    lda a:$DA00,X
    clc
    adc $02
    sta $02
    lda a:$E200,Y
    tax
    lda a:$D800,X
    clc
    adc $00
    sta $00
    lda a:$D900,X
    clc
    adc $01
    sta $01
    lda a:$DA00,X
    clc
    adc $02
    sta $02
    lda a:$E201,Y
    tax
    lda a:$D800,X
    clc
    adc $00
    lsr
    lsr
    sta $00
    lda a:$D900,X
    clc
    adc $01
    lsr
    lsr
    .a8
    and #$38
    ora $00
    sta $00
    lda a:$DA00,X
    clc
    adc $02
    .a8
    and #$C0
    ora $00
    sta $00
    rep #$20
    tya
    .a16
    and #$0030
    asl
    asl
    sta $02
    tya
    xba
    lsr
    .a16
    and #$000E
    ora $02
    tax
    sep #$20
    lda $00
    lsr
    rol a:$0000,X
    lsr
    rol a:$0001,X
    lsr
    rol a:$0010,X
    lsr
    rol a:$0011,X
    lsr
    rol a:$0020,X
    lsr
    rol a:$0021,X
    lsr
    rol a:$0030,X
    lsr
    rol a:$0031,X
    rep #$20
    tya
    clc
    .a16
    adc #$0400
    .a16
    cmp #$2000
    bcs average_four_world_map_pixels_and_pack_all_eight_bitplanes_c0af71
    tay
    brl average_four_world_map_pixels_and_pack_all_eight_bitplanes_c0aeb2
average_four_world_map_pixels_and_pack_all_eight_bitplanes_c0af71:
    .a16
    and #$03FF
    inc
    inc
    tay
    .a16
    and #$003F
    bne average_four_world_map_pixels_and_pack_all_eight_bitplanes_c0af99
    jsr await_world_map_survey_nmi_acknowledgement
    rep #$20
    .a16
    lda #$0100
    sta f:$004375
    .a16
    lda #$0000
    sta f:$004372
    sep #$20
    .a8
    lda #$80
    sta f:$00420B
    rep #$20
average_four_world_map_pixels_and_pack_all_eight_bitplanes_c0af99:
    .i16
    cpy #$0200
    bcs average_four_world_map_pixels_and_pack_all_eight_bitplanes_c0afa1
    brl average_four_world_map_pixels_and_pack_all_eight_bitplanes_c0aeb2
average_four_world_map_pixels_and_pack_all_eight_bitplanes_c0afa1:
    plb
    rts
