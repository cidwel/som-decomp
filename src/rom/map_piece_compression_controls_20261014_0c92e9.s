.setcpu "65816"
.segment "CODE"
.org $92E9
map_control_0c92e9:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
