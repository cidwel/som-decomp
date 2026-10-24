.setcpu "65816"
.segment "CODE"
.org $4D09
map_control_0c4d09:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
