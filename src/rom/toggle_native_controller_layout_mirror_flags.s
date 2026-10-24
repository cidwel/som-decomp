; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-layout.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6F69
toggle_native_controller_layout_mirror_flags:
    ldx a:$A220
    .a8
    lda #$03
    eor a:$A22F,X
    sta a:$A22F,X
