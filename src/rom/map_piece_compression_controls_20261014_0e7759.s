.setcpu "65816"
.segment "CODE"
.org $7759
map_control_0e7759:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
