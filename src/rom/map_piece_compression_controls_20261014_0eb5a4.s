.setcpu "65816"
.segment "CODE"
.org $B5A4
map_control_0eb5a4:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
