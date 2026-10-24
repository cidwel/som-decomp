.setcpu "65816"
.segment "CODE"
.org $B116
map_control_0fb116:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
