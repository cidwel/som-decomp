.setcpu "65816"
.segment "CODE"
.org $20F0
map_control_0f20f0:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
