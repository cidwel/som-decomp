.setcpu "65816"
.segment "CODE"
.org $2183
map_control_0f2183:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
