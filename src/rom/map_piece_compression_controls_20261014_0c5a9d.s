.setcpu "65816"
.segment "CODE"
.org $5A9D
map_control_0c5a9d:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
