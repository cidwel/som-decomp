.setcpu "65816"
.segment "CODE"
.org $51E2
map_control_0c51e2:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
