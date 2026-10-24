.setcpu "65816"
.segment "CODE"
.org $7497
map_control_0d7497:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
