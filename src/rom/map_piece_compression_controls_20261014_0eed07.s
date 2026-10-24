.setcpu "65816"
.segment "CODE"
.org $ED07
map_control_0eed07:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
