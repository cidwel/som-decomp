.setcpu "65816"
.segment "CODE"
.org $9D0F
map_control_0e9d0f:
    .byte $E8 ; backreference distance high bits
    .byte $1E ; distance low bit/count
