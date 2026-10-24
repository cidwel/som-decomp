.setcpu "65816"
.segment "CODE"
.org $1EFD
map_control_0d1efd:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
