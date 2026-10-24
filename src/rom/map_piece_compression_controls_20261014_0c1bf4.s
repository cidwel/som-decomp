.setcpu "65816"
.segment "CODE"
.org $1BF4
map_control_0c1bf4:
    .byte $EC ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
