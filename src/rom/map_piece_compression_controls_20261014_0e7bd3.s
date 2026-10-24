.setcpu "65816"
.segment "CODE"
.org $7BD3
map_control_0e7bd3:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
