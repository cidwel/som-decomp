.setcpu "65816"
.segment "CODE"
.org $4FB3
map_control_0e4fb3:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
