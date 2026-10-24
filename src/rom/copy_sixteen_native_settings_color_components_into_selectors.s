; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-settings-page.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6045
copy_sixteen_native_settings_color_components_into_selectors:
    .i16
    ldx #$0000
    .a8
    lda #$10
copy_sixteen_native_settings_color_components_into_selectors_c7604a:
    xba
    lda a:$A23E,X
    sta a:$A136,X
    inx
    xba
    dec
    bne copy_sixteen_native_settings_color_components_into_selectors_c7604a
    rts
