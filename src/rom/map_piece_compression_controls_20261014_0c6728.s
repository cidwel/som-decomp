.setcpu "65816"
.segment "CODE"
.org $6728
map_control_0c6728:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
