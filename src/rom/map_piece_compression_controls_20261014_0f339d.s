.setcpu "65816"
.segment "CODE"
.org $339D
map_control_0f339d:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
