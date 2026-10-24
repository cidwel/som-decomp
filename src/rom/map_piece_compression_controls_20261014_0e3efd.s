.setcpu "65816"
.segment "CODE"
.org $3EFD
map_control_0e3efd:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
