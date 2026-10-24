.setcpu "65816"
.segment "CODE"
.org $B9A8
map_control_0eb9a8:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
