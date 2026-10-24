.setcpu "65816"
.segment "CODE"
.org $BE25
map_control_0ebe25:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
