.setcpu "65816"
.segment "CODE"
.org $6584
map_control_0e6584:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
