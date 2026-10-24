.setcpu "65816"
.segment "CODE"
.org $1584
map_control_0f1584:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
