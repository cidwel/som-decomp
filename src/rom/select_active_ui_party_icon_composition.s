; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-sprites.md.
.setcpu "65816"
.smart
.a8
.i16

forward_ui_party_icon_to_native_packed_sprite_emitter = $9EF5
publish_single_ui_party_icon = $9E9C
publish_three_ui_party_icons = $9EB8

.segment "CODE"
.org $9E25
select_active_ui_party_icon_composition:
    lda a:$E000
    beq select_active_ui_party_icon_composition_c09e45
    bmi select_active_ui_party_icon_composition_c09e45
    lda a:$E200
    beq select_active_ui_party_icon_composition_c09e3c
    bmi select_active_ui_party_icon_composition_c09e3c
    lda a:$E400
    beq select_active_ui_party_icon_composition_c09e61
    bmi select_active_ui_party_icon_composition_c09e61
    bra select_active_ui_party_icon_composition_c09e76
select_active_ui_party_icon_composition_c09e3c:
    lda a:$E400
    beq select_active_ui_party_icon_composition_c09e55
    bmi select_active_ui_party_icon_composition_c09e55
    bra select_active_ui_party_icon_composition_c09e68
select_active_ui_party_icon_composition_c09e45:
    lda a:$E200
    beq select_active_ui_party_icon_composition_c09e5d
    bmi select_active_ui_party_icon_composition_c09e5d
    lda a:$E400
    beq select_active_ui_party_icon_composition_c09e59
    bmi select_active_ui_party_icon_composition_c09e59
    bra select_active_ui_party_icon_composition_c09e6f
select_active_ui_party_icon_composition_c09e55:
    .a8
    lda #$00
    bra publish_single_ui_party_icon
select_active_ui_party_icon_composition_c09e59:
    .a8
    lda #$10
    bra publish_single_ui_party_icon
select_active_ui_party_icon_composition_c09e5d:
    .a8
    lda #$20
    bra publish_single_ui_party_icon
select_active_ui_party_icon_composition_c09e61:
    .a8
    lda #$10
    xba
    .a8
    lda #$00
    bra select_active_ui_party_icon_composition_c09e78
select_active_ui_party_icon_composition_c09e68:
    .a8
    lda #$20
    xba
    .a8
    lda #$00
    bra select_active_ui_party_icon_composition_c09e78
select_active_ui_party_icon_composition_c09e6f:
    .a8
    lda #$20
    xba
    .a8
    lda #$10
    bra select_active_ui_party_icon_composition_c09e78
select_active_ui_party_icon_composition_c09e76:
    bra publish_three_ui_party_icons
select_active_ui_party_icon_composition_c09e78:
    rep #$20
    pha
    jsr publish_single_ui_party_icon
    rep #$20
    pla
    xba
    .a16
    and #$00FF
    clc
    adc $9C
    .i16
    ldx #$0080
    .i16
    ldy #$0090
    jsr forward_ui_party_icon_to_native_packed_sprite_emitter
    sep #$20
    lda a:$0A01
    .a8
    ora #$AA
    sta a:$0A01
    rts
