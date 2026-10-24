.setcpu "65816"
.segment "CODE"
.org $02A8
map_control_0e02a8:
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
