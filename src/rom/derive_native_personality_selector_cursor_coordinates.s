; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-personality-movement.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6C45
derive_native_personality_selector_cursor_coordinates:
    lda a:$A211
    asl
    asl
    asl
    asl
    clc
    .a8
    adc #$30
    sta a:$A15A
    .a8
    lda #$E3
    sta a:$A159
    rtl
