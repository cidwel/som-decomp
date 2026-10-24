.setcpu "65816"
.segment "CODE"
.org $1B73
map_control_0c1b73:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
