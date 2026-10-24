.setcpu "65816"
.segment "CODE"
.org $F675
map_control_0ef675:
    .byte $E9 ; backreference distance high bits
    .byte $05 ; distance low bit/count
