.setcpu "65816"
.segment "CODE"
.org $7642
map_control_0e7642:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
