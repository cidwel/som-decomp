.setcpu "65816"
.segment "CODE"
.org $4715
map_control_0c4715:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
