; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-projection.md.
.setcpu "65816"
.smart
.a8
.i16

publish_clipped_ui_angular_icon_tiles_and_high_x_bits = $FE58
routine_02b10a = $2B10A

.segment "CODE"
.org $FDE4
publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites:
    rep #$30
    .i16
    ldy #$0100
    lda $F1
    bmi publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fe3d
    lda $8C
    bne publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fe3d
    stz $10
    stz $12
    stz a:$0A10
    stz a:$0A12
    ldx $12
publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fdfd:
    rep #$20
    lda f:$01FEE2,X
    tax
    lda f:$010000,X
    sta $00
    sec
    sbc $F6
    bcc publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fe19
    .a16
    cmp #$0200
    bcc publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fe21
    .a16
    sbc #$0400
    bra publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fe21
publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fe19:
    .a16
    cmp #$FE00
    bcs publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fe21
    .a16
    adc #$0400
publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fe21:
    .a16
    cmp #$0080
    bcc publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fe2b
    .a16
    cmp #$FF80
    bcc publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fe2e
publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fe2b:
    jsr publish_clipped_ui_angular_icon_tiles_and_high_x_bits
publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fe2e:
    ldx $12
    inx
    inx
    stx $12
    .i16
    cpx #$0010
    bcc publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fdfd
    jsl f:routine_02b10a
publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fe3d:
    rep #$20
    tya
    .a16
    eor #$FFFF
    sec
    .a16
    adc #$0150
    lsr
    lsr
    tax
publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fe4a:
    .a16
    lda #$E0FF
    sta a:$0800,Y
    iny
    iny
    iny
    iny
    dex
    bne publish_ui_angular_icons_and_focus_marker_then_hide_unused_sprites_c1fe4a
    rtl
