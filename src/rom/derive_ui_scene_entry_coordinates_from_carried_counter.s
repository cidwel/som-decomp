; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-entry-prefix.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B0D7
derive_ui_scene_entry_coordinates_from_carried_counter:
    rep #$20
    lda a:$0126
    .a16
    adc #$0037
    sta a:$0126
    .a16
    and #$00FF
    .a16
    cmp #$0080
    bcc derive_ui_scene_entry_coordinates_from_carried_counter_c2b0ed
    .a16
    eor #$FF7F
derive_ui_scene_entry_coordinates_from_carried_counter_c2b0ed:
    adc $FA
    .a16
    and #$0FFF
    sta a:$0128
    lda a:$0126
    .a16
    and #$007F
    .a16
    ora #$0100
    .a16
    eor #$FFFF
    adc $FC
    .a16
    and #$0FFF
    sta a:$012A
    rtl
