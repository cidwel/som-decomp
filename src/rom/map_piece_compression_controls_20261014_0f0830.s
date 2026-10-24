.setcpu "65816"
.segment "CODE"
.org $0830
map_control_0f0830:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
