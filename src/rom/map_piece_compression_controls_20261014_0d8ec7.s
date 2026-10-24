.setcpu "65816"
.segment "CODE"
.org $8EC7
map_control_0d8ec7:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
