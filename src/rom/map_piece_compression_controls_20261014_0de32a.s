.setcpu "65816"
.segment "CODE"
.org $E32A
map_control_0de32a:
    .byte $ED ; backreference distance high bits
    .byte $08 ; distance low bit/count
