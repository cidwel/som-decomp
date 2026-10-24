; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-menu-input.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3275
derive_native_menu_button_and_page_callback_table_index:
    .a8
    lda #$00
    xba
    lda a:$A209
    sta a:$A173
    asl
    asl
    asl
    clc
    adc a:$A173
    adc a:$A173
    adc a:$A173
    adc f:$7EA202
    rep #$20
    asl
    tax
    sep #$20
    rts
