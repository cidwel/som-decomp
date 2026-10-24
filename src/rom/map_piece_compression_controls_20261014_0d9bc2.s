.setcpu "65816"
.segment "CODE"
.org $9BC2
map_control_0d9bc2:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
