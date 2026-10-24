.setcpu "65816"
.segment "CODE"
.org $60B5
map_control_0d60b5:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
