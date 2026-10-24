.setcpu "65816"
.segment "CODE"
.org $01A0
map_control_0e01a0:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
