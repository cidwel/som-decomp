.setcpu "65816"
.segment "CODE"
.org $4B81
map_control_0c4b81:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
