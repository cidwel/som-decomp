.setcpu "65816"
.segment "CODE"
.org $23EC
map_control_0d23ec:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
