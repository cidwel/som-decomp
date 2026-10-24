.setcpu "65816"
.segment "CODE"
.org $1E9D
map_control_0d1e9d:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
