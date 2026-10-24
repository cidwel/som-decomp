.setcpu "65816"
.segment "CODE"
.org $0E2D
map_control_0e0e2d:
    .byte $C6 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
