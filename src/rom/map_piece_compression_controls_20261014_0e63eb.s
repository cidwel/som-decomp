.setcpu "65816"
.segment "CODE"
.org $63EB
map_control_0e63eb:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
