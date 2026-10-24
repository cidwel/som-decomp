.setcpu "65816"
.segment "CODE"
.org $F394
map_control_0ef394:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
