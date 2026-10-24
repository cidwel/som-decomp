.setcpu "65816"
.segment "CODE"
.org $5BAD
map_control_0c5bad:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
