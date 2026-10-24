.setcpu "65816"
.segment "CODE"
.org $BA03
map_control_0eba03:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
