.setcpu "65816"
.segment "CODE"
.org $495E
map_control_0e495e:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
