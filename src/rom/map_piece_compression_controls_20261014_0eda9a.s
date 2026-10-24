.setcpu "65816"
.segment "CODE"
.org $DA9A
map_control_0eda9a:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
