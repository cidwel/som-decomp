.setcpu "65816"
.segment "CODE"
.org $2DD9
map_control_0f2dd9:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
