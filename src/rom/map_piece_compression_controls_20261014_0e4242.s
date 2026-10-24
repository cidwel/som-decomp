.setcpu "65816"
.segment "CODE"
.org $4242
map_control_0e4242:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
