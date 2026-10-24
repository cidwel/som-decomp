.setcpu "65816"
.segment "CODE"
.org $418A
map_control_0e418a:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
