.setcpu "65816"
.segment "CODE"
.org $1742
map_control_0f1742:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
