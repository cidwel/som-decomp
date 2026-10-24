.setcpu "65816"
.segment "CODE"
.org $C8CC
map_control_0ec8cc:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
