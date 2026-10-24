.setcpu "65816"
.segment "CODE"
.org $F027
map_control_0ef027:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
