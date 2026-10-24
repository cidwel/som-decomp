.setcpu "65816"
.segment "CODE"
.org $B017
map_control_0fb017:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
