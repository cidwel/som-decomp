.setcpu "65816"
.segment "CODE"
.org $4244
map_control_0c4244:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
