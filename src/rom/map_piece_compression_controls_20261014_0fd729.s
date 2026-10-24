.setcpu "65816"
.segment "CODE"
.org $D729
map_control_0fd729:
    .byte $C6 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
