.setcpu "65816"
.segment "CODE"
.org $C7C8
map_control_0ec7c8:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
