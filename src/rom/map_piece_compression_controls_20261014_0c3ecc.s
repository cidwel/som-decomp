.setcpu "65816"
.segment "CODE"
.org $3ECC
map_control_0c3ecc:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
