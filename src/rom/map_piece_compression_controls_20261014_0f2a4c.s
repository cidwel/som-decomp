.setcpu "65816"
.segment "CODE"
.org $2A4C
map_control_0f2a4c:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
