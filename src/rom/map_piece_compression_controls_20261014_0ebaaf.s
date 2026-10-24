.setcpu "65816"
.segment "CODE"
.org $BAAF
map_control_0ebaaf:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
