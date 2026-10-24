.setcpu "65816"
.segment "CODE"
.org $F08B
map_control_0ef08b:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
