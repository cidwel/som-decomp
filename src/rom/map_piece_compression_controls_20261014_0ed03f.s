.setcpu "65816"
.segment "CODE"
.org $D03F
map_control_0ed03f:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
