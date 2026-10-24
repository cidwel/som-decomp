.setcpu "65816"
.segment "CODE"
.org $49E8
map_control_0e49e8:
    .byte $EB ; backreference distance high bits
    .byte $93 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
