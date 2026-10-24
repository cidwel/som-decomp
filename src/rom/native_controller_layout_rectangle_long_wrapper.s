; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-controller-layout.md.
.setcpu "65816"
.smart
.a8
.i16

consume_native_menu_rectangle_76f5 = $2697

.segment "CODE"
.org $2AF6
native_controller_layout_rectangle_long_wrapper:
    jsr consume_native_menu_rectangle_76f5
    rtl
