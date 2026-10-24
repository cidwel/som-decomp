.setcpu "65816"
.segment "CODE"
.org $1606
map_control_0d1606:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
