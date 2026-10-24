.setcpu "65816"
.segment "CODE"
.org $DA52
map_control_0eda52:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
