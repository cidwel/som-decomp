; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-settings-page.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6057
publish_three_native_settings_color_cursor_coordinates:
    .a8
    lda #$20
    sta a:$A159
    .i16
    ldx #$0001
    .a8
    lda #$03
publish_three_native_settings_color_cursor_coordinates_c76061:
    xba
    lda a:$A159
    sta a:$9C00,X
    inx
    clc
    .a8
    adc #$10
    sta a:$A159
    .a8
    lda #$20
    sta a:$9C00,X
    inx
    .a8
    lda #$20
    sta a:$9C00,X
    inx
    inx
    xba
    dec
    bne publish_three_native_settings_color_cursor_coordinates_c76061
    rts
