.setcpu "65816"
.segment "CODE"
.org $1551
map_control_0f1551:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
