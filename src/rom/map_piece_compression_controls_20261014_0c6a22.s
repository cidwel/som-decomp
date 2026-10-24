.setcpu "65816"
.segment "CODE"
.org $6A22
map_control_0c6a22:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
