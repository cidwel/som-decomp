.setcpu "65816"
.segment "CODE"
.org $2924
map_control_0d2924:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
