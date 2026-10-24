.setcpu "65816"
.segment "CODE"
.org $F8C8
map_control_0cf8c8:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
