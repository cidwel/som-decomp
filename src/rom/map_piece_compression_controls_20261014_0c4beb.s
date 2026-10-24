.setcpu "65816"
.segment "CODE"
.org $4BEB
map_control_0c4beb:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
