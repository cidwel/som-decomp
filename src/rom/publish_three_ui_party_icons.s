; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

forward_ui_party_icon_to_native_packed_sprite_emitter = $9EF5
publish_single_ui_party_icon = $9E9C

.segment "CODE"
.org $9EB8
publish_three_ui_party_icons:
    rep #$20
    .a16
    lda #$0000
    jsr publish_single_ui_party_icon
    rep #$20
    lda $9C
    clc
    .a16
    adc #$0010
    .i16
    ldx #$0060
    .i16
    ldy #$0080
    jsr forward_ui_party_icon_to_native_packed_sprite_emitter
    rep #$20
    lda $9C
    clc
    .a16
    adc #$0020
    .i16
    ldx #$00A0
    .i16
    ldy #$0080
    jsr forward_ui_party_icon_to_native_packed_sprite_emitter
    sep #$20
    lda a:$0A01
    .a8
    ora #$AA
    sta a:$0A01
    lda a:$0A02
    .a8
    ora #$AA
    sta a:$0A02
    rts
