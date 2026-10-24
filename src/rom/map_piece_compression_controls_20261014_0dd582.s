.setcpu "65816"
.segment "CODE"
.org $D582
map_control_0dd582:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
