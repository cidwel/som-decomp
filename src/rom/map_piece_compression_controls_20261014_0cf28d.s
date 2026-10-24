.setcpu "65816"
.segment "CODE"
.org $F28D
map_control_0cf28d:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
