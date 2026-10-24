.setcpu "65816"
.segment "CODE"
.org $7FE4
map_control_0c7fe4:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
