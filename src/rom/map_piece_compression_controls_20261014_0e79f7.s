.setcpu "65816"
.segment "CODE"
.org $79F7
map_control_0e79f7:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
