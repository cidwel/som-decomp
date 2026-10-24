.setcpu "65816"
.segment "CODE"
.org $897A
map_control_0e897a:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
