.setcpu "65816"
.segment "CODE"
.org $8046
map_control_0d8046:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
