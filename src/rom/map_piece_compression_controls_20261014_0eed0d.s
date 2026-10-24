.setcpu "65816"
.segment "CODE"
.org $ED0D
map_control_0eed0d:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
