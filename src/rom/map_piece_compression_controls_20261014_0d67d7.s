.setcpu "65816"
.segment "CODE"
.org $67D7
map_control_0d67d7:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
