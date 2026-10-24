; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-projection.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FE58
publish_clipped_ui_angular_icon_tiles_and_high_x_bits:
    inx
    inx
    sta $02
    .a16
    cmp #$8000
    ror
    clc
    adc $02
    .a16
    eor #$FFFF
    sec
    .a16
    adc #$0080
    sta $02
    .a16
    lda #$0080
    bit $00
    beq publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1fe7d
    .a16
    lda #$0004
    sta $04
    .a16
    lda #$FFF0
    bra publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1fe85
publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1fe7d:
    .a16
    lda #$0003
    sta $04
    .a16
    lda #$FFF4
publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1fe85:
    clc
    adc $02
    sta $02
    .a16
    cmp #$0100
    bcc publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1fec7
    .a16
    cmp #$FFF8
    bcc publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1fed8
    .a16
    and #$00FF
    pha
    phy
    tya
    lsr
    lsr
    lsr
    lsr
    pha
    tya
    sep #$20
    .a8
    and #$0C
    beq publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1feba
    .a8
    cmp #$04
    beq publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1feb6
    .a8
    cmp #$08
    beq publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1feb2
    .a8
    lda #$40
    bra publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1febc
publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1feb2:
    .a8
    lda #$10
    bra publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1febc
publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1feb6:
    .a8
    lda #$04
    bra publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1febc
publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1feba:
    .a8
    lda #$01
publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1febc:
    ply
    ora a:$0A00,Y
    sta a:$0A00,Y
    rep #$20
    ply
    pla
publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1fec7:
    .a16
    ora #$1000
    sta a:$0800,Y
    lda f:$010000,X
    sta a:$0802,Y
    iny
    iny
    iny
    iny
publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1fed8:
    inx
    inx
    .a16
    lda #$0008
    dec $04
    bne publish_clipped_ui_angular_icon_tiles_and_high_x_bits_c1fe85
    rts
