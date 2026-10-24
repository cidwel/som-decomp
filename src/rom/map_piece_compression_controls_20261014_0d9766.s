.setcpu "65816"
.segment "CODE"
.org $9766
map_control_0d9766:
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
