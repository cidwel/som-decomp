.setcpu "65816"
.segment "CODE"
.org $4A75
map_control_0f4a75:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
