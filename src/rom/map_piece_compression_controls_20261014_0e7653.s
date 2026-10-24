.setcpu "65816"
.segment "CODE"
.org $7653
map_control_0e7653:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
