.setcpu "65816"
.segment "CODE"
.org $DA57
map_control_0eda57:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
