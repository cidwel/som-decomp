.setcpu "65816"
.segment "CODE"
.org $7271
map_control_0d7271:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
