.setcpu "65816"
.segment "CODE"
.org $6221
map_control_0e6221:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
