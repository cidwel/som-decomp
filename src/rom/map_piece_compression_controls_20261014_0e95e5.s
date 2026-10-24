.setcpu "65816"
.segment "CODE"
.org $95E5
map_control_0e95e5:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
