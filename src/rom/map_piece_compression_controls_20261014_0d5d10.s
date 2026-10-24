.setcpu "65816"
.segment "CODE"
.org $5D10
map_control_0d5d10:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
