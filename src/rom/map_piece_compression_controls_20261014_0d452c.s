.setcpu "65816"
.segment "CODE"
.org $452C
map_control_0d452c:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
