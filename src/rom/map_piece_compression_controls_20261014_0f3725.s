.setcpu "65816"
.segment "CODE"
.org $3725
map_control_0f3725:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
