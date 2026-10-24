.setcpu "65816"
.segment "CODE"
.org $9D13
map_control_0e9d13:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
