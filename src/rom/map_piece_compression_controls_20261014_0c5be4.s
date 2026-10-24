.setcpu "65816"
.segment "CODE"
.org $5BE4
map_control_0c5be4:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
