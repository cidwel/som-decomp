.setcpu "65816"
.segment "CODE"
.org $7C58
map_control_0d7c58:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
