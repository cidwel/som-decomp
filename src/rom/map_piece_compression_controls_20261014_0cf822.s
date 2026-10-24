.setcpu "65816"
.segment "CODE"
.org $F822
map_control_0cf822:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
