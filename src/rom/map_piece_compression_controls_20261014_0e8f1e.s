.setcpu "65816"
.segment "CODE"
.org $8F1E
map_control_0e8f1e:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
