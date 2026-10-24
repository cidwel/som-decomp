.setcpu "65816"
.segment "CODE"
.org $5BCF
map_control_0e5bcf:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
