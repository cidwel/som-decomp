.setcpu "65816"
.segment "CODE"
.org $9F33
map_control_0e9f33:
    .byte $E8 ; backreference distance high bits
    .byte $3A ; distance low bit/count
