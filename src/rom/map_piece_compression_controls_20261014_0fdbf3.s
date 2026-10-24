.setcpu "65816"
.segment "CODE"
.org $DBF3
map_control_0fdbf3:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
