.setcpu "65816"
.segment "CODE"
.org $B9D9
map_control_0fb9d9:
    .byte $E8 ; backreference distance high bits
    .byte $27 ; distance low bit/count
