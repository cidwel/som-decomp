.setcpu "65816"
.segment "CODE"
.org $9283
map_control_0c9283:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
