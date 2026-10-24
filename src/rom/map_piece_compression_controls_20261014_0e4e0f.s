.setcpu "65816"
.segment "CODE"
.org $4E0F
map_control_0e4e0f:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
