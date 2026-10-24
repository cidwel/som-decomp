.setcpu "65816"
.segment "CODE"
.org $4172
map_control_0d4172:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
