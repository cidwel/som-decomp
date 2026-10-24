.setcpu "65816"
.segment "CODE"
.org $F104
map_control_0ef104:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
