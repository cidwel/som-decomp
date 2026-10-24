.setcpu "65816"
.segment "CODE"
.org $E3AD
map_control_0de3ad:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
