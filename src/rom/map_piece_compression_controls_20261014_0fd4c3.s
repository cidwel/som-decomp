.setcpu "65816"
.segment "CODE"
.org $D4C3
map_control_0fd4c3:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
