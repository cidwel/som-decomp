.setcpu "65816"
.segment "CODE"
.org $922F
map_control_0f922f:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
