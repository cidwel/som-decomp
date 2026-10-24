.setcpu "65816"
.segment "CODE"
.org $08BD
map_control_0d08bd:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
