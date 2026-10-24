.setcpu "65816"
.segment "CODE"
.org $49E7
map_control_0d49e7:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
