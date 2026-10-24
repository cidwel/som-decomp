.setcpu "65816"
.segment "CODE"
.org $8603
map_control_0f8603:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count
