.setcpu "65816"
.segment "CODE"
.org $1EB1
map_control_0d1eb1:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
