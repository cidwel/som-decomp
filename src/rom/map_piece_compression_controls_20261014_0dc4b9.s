.setcpu "65816"
.segment "CODE"
.org $C4B9
map_control_0dc4b9:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
