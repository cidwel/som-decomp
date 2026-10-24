.setcpu "65816"
.segment "CODE"
.org $6331
map_control_0c6331:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
