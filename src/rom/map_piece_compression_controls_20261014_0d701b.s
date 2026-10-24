.setcpu "65816"
.segment "CODE"
.org $701B
map_control_0d701b:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
