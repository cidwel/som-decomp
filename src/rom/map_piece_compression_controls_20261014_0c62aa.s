.setcpu "65816"
.segment "CODE"
.org $62AA
map_control_0c62aa:
    .byte $E8 ; backreference distance high bits
    .byte $36 ; distance low bit/count
