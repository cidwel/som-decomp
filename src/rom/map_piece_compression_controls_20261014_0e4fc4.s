.setcpu "65816"
.segment "CODE"
.org $4FC4
map_control_0e4fc4:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
