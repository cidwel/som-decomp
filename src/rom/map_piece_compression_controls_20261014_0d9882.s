.setcpu "65816"
.segment "CODE"
.org $9882
map_control_0d9882:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
