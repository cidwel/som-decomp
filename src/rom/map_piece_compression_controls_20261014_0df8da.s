.setcpu "65816"
.segment "CODE"
.org $F8DA
map_control_0df8da:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
