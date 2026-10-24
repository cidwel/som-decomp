.setcpu "65816"
.segment "CODE"
.org $B95F
map_control_0eb95f:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
