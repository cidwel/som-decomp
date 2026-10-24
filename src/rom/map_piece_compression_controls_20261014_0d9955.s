.setcpu "65816"
.segment "CODE"
.org $9955
map_control_0d9955:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
