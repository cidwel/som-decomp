; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-settings-page.md.
.setcpu "65816"
.smart
.a8
.i16

copy_sixteen_native_settings_color_components_into_selectors = $6045

.segment "CODE"
.org $602B
snapshot_native_settings_selector_and_eight_icon_variants:
    lda a:$A24E
    sta a:$A222
    jsr copy_sixteen_native_settings_color_components_into_selectors
    .i16
    ldx #$0000
    .i16
    ldy #$0008
snapshot_native_settings_selector_and_eight_icon_variants_c7603a:
    lda a:$A24F,X
    sta a:$A223,X
    inx
    dey
    bne snapshot_native_settings_selector_and_eight_icon_variants_c7603a
    rts
