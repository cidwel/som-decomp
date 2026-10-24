.setcpu "65816"
.segment "CODE"
.org $1EBB
map_control_0d1ebb:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
