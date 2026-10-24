.setcpu "65816"
.segment "CODE"
.org $4B9B
map_control_0d4b9b:
    .byte $EA ; backreference distance high bits
    .byte $05 ; distance low bit/count
