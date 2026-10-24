.setcpu "65816"
.segment "CODE"
.org $271A
map_control_0d271a:
    .byte $E8 ; backreference distance high bits
    .byte $B1 ; distance low bit/count
