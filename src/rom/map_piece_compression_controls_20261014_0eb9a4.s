.setcpu "65816"
.segment "CODE"
.org $B9A4
map_control_0eb9a4:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
