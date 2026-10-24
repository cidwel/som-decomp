.setcpu "65816"
.segment "CODE"
.org $8BAE
map_control_0f8bae:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
