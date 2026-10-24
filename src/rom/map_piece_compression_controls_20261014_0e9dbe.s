.setcpu "65816"
.segment "CODE"
.org $9DBE
map_control_0e9dbe:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
