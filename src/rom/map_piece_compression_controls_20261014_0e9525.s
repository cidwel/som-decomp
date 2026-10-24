.setcpu "65816"
.segment "CODE"
.org $9525
map_control_0e9525:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
