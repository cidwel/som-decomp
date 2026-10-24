.setcpu "65816"
.segment "CODE"
.org $8B4D
map_control_0f8b4d:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
