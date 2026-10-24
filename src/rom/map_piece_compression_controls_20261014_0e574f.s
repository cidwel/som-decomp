.setcpu "65816"
.segment "CODE"
.org $574F
map_control_0e574f:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
