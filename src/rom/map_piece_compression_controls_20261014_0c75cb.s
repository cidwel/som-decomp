.setcpu "65816"
.segment "CODE"
.org $75CB
map_control_0c75cb:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
