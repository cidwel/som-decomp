.setcpu "65816"
.segment "CODE"
.org $4B0D
map_control_0c4b0d:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
