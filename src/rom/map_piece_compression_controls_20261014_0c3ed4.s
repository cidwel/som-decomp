.setcpu "65816"
.segment "CODE"
.org $3ED4
map_control_0c3ed4:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
