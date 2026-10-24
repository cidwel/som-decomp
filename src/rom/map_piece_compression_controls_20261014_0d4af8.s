.setcpu "65816"
.segment "CODE"
.org $4AF8
map_control_0d4af8:
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
