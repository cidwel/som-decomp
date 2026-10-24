.setcpu "65816"
.segment "CODE"
.org $3B0F
map_control_0e3b0f:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
