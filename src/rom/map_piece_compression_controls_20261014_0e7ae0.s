.setcpu "65816"
.segment "CODE"
.org $7AE0
map_control_0e7ae0:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
