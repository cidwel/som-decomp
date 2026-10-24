.setcpu "65816"
.segment "CODE"
.org $C9C1
map_control_0dc9c1:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
