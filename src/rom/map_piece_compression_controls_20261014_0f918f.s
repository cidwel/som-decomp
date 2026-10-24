.setcpu "65816"
.segment "CODE"
.org $918F
map_control_0f918f:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
