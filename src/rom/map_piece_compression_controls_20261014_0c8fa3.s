.setcpu "65816"
.segment "CODE"
.org $8FA3
map_control_0c8fa3:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
