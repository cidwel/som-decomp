.setcpu "65816"
.segment "CODE"
.org $30B7
map_control_0f30b7:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
