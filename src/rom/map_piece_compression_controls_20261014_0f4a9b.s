.setcpu "65816"
.segment "CODE"
.org $4A9B
map_control_0f4a9b:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
