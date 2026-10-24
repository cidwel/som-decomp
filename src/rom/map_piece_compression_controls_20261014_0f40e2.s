.setcpu "65816"
.segment "CODE"
.org $40E2
map_control_0f40e2:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
