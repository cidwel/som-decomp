.setcpu "65816"
.segment "CODE"
.org $B9FC
map_control_0fb9fc:
    .byte $E8 ; backreference distance high bits
    .byte $27 ; distance low bit/count
