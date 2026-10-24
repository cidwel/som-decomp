.setcpu "65816"
.segment "CODE"
.org $1C97
map_control_0f1c97:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
