.setcpu "65816"
.segment "CODE"
.org $8B6D
map_control_0f8b6d:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
