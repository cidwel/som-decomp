.setcpu "65816"
.segment "CODE"
.org $5DD7
map_control_0e5dd7:
    .byte $EF ; backreference distance high bits
    .byte $08 ; distance low bit/count
