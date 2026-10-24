.setcpu "65816"
.segment "CODE"
.org $1451
map_control_0d1451:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
