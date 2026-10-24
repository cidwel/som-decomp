; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-art.md.
.setcpu "65816"
.smart
.a8
.i16

derive_native_party_status_icon_quadrant_tile_offset = $63AD
read_selected_native_party_status_excluding_low_two_bits = $6AA4

.segment "CODE"
.org $6367
publish_eight_native_party_status_flag_icons_when_unrestricted:
    rep #$20
    jsr read_selected_native_party_status_excluding_low_two_bits
    bne publish_eight_native_party_status_flag_icons_when_unrestricted_c763aa
    sep #$20
    .i16
    ldy #$0000
    .a8
    lda #$90
    sta a:$A15A
    .a8
    lda #$10
    sta a:$A159
    .i16
    ldx #$0100
publish_eight_native_party_status_flag_icons_when_unrestricted_c76380:
    lda a:$CF90,Y
    beq publish_eight_native_party_status_flag_icons_when_unrestricted_c7639b
    dec
    bne publish_eight_native_party_status_flag_icons_when_unrestricted_c76390
    stz a:$A17E
    jsr derive_native_party_status_icon_quadrant_tile_offset
    bra publish_eight_native_party_status_flag_icons_when_unrestricted_c7639b
publish_eight_native_party_status_flag_icons_when_unrestricted_c76390:
    dec
    bne publish_eight_native_party_status_flag_icons_when_unrestricted_c7639b
    .a8
    lda #$08
    sta a:$A17E
    jsr derive_native_party_status_icon_quadrant_tile_offset
publish_eight_native_party_status_flag_icons_when_unrestricted_c7639b:
    .a8
    lda #$0C
    clc
    adc a:$A159
    sta a:$A159
    iny
    .i16
    cpy #$0008
    bne publish_eight_native_party_status_flag_icons_when_unrestricted_c76380
publish_eight_native_party_status_flag_icons_when_unrestricted_c763aa:
    sep #$20
    rts
