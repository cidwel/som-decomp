.setcpu "65816"
.segment "CODE"
.org $3CDF
map_control_0e3cdf:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
