.setcpu "65816"
.segment "CODE"
.org $8486
map_control_0d8486:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $2E ; distance low bit/count
