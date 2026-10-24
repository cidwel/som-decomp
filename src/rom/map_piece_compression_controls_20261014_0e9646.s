.setcpu "65816"
.segment "CODE"
.org $9646
map_control_0e9646:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
