.setcpu "65816"
.segment "CODE"
.org $8CFC
map_control_0e8cfc:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
