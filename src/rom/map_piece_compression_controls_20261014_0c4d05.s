.setcpu "65816"
.segment "CODE"
.org $4D05
map_control_0c4d05:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
