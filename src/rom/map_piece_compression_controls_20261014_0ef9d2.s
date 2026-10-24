.setcpu "65816"
.segment "CODE"
.org $F9D2
map_control_0ef9d2:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
