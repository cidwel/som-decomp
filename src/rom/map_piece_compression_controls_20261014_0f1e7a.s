.setcpu "65816"
.segment "CODE"
.org $1E7A
map_control_0f1e7a:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
