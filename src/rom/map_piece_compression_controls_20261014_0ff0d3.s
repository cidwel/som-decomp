.setcpu "65816"
.segment "CODE"
.org $F0D3
map_control_0ff0d3:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
