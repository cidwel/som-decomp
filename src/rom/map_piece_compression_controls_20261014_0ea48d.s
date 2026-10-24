.setcpu "65816"
.segment "CODE"
.org $A48D
map_control_0ea48d:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
