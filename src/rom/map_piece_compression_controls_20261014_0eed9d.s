.setcpu "65816"
.segment "CODE"
.org $ED9D
map_control_0eed9d:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
