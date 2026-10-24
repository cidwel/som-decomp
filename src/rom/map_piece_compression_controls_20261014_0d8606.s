.setcpu "65816"
.segment "CODE"
.org $8606
map_control_0d8606:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
