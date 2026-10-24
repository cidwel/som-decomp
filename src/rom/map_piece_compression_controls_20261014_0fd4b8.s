.setcpu "65816"
.segment "CODE"
.org $D4B8
map_control_0fd4b8:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
