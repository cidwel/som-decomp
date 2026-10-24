; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

forward_ui_party_icon_to_native_packed_sprite_emitter = $9EF5

.segment "CODE"
.org $9E9C
publish_single_ui_party_icon:
    rep #$20
    .a16
    and #$00FF
    clc
    adc $9C
    .i16
    ldx #$0080
    .i16
    ldy #$0070
    jsr forward_ui_party_icon_to_native_packed_sprite_emitter
    sep #$20
    lda a:$0A00
    .a8
    ora #$AA
    sta a:$0A00
    rts
