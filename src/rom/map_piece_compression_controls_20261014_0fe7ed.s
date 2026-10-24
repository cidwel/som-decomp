.setcpu "65816"
.segment "CODE"
.org $E7ED
map_control_0fe7ed:
    .byte $E8 ; backreference distance high bits
    .byte $65 ; distance low bit/count
