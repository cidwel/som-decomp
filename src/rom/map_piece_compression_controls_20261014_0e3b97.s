.setcpu "65816"
.segment "CODE"
.org $3B97
map_control_0e3b97:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
