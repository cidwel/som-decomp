.setcpu "65816"
.segment "CODE"
.org $2200
map_control_0c2200:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
