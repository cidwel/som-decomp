.setcpu "65816"
.segment "CODE"
.org $6D01
map_control_0d6d01:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count
