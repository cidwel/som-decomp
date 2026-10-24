.setcpu "65816"
.segment "CODE"
.org $D64D
map_control_0dd64d:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
