.setcpu "65816"
.segment "CODE"
.org $E82D
map_control_0de82d:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
