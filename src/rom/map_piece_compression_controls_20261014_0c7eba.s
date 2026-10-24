.setcpu "65816"
.segment "CODE"
.org $7EBA
map_control_0c7eba:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
