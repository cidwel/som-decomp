.setcpu "65816"
.segment "CODE"
.org $B950
map_control_0fb950:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
