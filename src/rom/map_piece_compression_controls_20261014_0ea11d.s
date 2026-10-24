.setcpu "65816"
.segment "CODE"
.org $A11D
map_control_0ea11d:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
