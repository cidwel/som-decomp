.setcpu "65816"
.segment "CODE"
.org $3540
map_control_0f3540:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
