.setcpu "65816"
.segment "CODE"
.org $B476
map_control_0fb476:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
