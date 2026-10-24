.setcpu "65816"
.segment "CODE"
.org $7975
map_control_0c7975:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
