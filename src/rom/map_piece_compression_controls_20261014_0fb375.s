.setcpu "65816"
.segment "CODE"
.org $B375
map_control_0fb375:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
