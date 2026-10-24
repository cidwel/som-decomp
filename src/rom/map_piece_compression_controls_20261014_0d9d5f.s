.setcpu "65816"
.segment "CODE"
.org $9D5F
map_control_0d9d5f:
    .byte $E8 ; backreference distance high bits
    .byte $30 ; distance low bit/count
