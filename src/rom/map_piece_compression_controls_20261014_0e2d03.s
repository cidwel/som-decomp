.setcpu "65816"
.segment "CODE"
.org $2D03
map_control_0e2d03:
    .byte $C9 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
