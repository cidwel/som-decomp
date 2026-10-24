.setcpu "65816"
.segment "CODE"
.org $6F5F
map_control_0e6f5f:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
