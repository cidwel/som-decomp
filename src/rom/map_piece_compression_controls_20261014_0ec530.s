.setcpu "65816"
.segment "CODE"
.org $C530
map_control_0ec530:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
