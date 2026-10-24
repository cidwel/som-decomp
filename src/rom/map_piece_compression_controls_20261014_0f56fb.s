.setcpu "65816"
.segment "CODE"
.org $56FB
map_control_0f56fb:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
