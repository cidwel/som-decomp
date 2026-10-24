.setcpu "65816"
.segment "CODE"
.org $F54E
map_control_0cf54e:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
