.setcpu "65816"
.segment "CODE"
.org $4CAA
map_control_0d4caa:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
