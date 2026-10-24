.setcpu "65816"
.segment "CODE"
.org $BF53
map_control_0ebf53:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
