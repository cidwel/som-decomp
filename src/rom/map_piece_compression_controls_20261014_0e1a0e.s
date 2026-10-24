.setcpu "65816"
.segment "CODE"
.org $1A0E
map_control_0e1a0e:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
