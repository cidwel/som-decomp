.setcpu "65816"
.segment "CODE"
.org $0B16
map_control_0d0b16:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
