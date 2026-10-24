.setcpu "65816"
.segment "CODE"
.org $DA46
map_control_0eda46:
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
