.setcpu "65816"
.segment "CODE"
.org $34F6
map_control_0c34f6:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
