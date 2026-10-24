.setcpu "65816"
.segment "CODE"
.org $AD7A
map_control_0dad7a:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
