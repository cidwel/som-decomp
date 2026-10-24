.setcpu "65816"
.segment "CODE"
.org $099F
map_control_0f099f:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
