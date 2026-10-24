.setcpu "65816"
.segment "CODE"
.org $CD96
map_control_0fcd96:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
