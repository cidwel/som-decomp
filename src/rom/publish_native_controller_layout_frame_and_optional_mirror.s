; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-layout.md.
.setcpu "65816"
.smart
.a8
.i16

native_controller_layout_rectangle_long_wrapper = $C02AF6
swap_and_mirror_native_controller_frame_tiles = $C76F74

.segment "CODE"
.org $6E17
publish_native_controller_layout_frame_and_optional_mirror:
    stz a:$A198
    phb
    .a8
    lda #$C7
    pha
    plb
    .i16
    ldy #$75D2
    jsl f:native_controller_layout_rectangle_long_wrapper
    plb
    ldx a:$A220
    lda a:$A22F,X
    .a8
    and #$03
    beq publish_native_controller_layout_frame_and_optional_mirror_c76e35
    jsl f:swap_and_mirror_native_controller_frame_tiles
publish_native_controller_layout_frame_and_optional_mirror_c76e35:
    rtl
