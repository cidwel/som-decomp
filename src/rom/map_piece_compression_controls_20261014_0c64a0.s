.setcpu "65816"
.segment "CODE"
.org $64A0
map_control_0c64a0:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
