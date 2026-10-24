.setcpu "65816"
.segment "CODE"
.org $9926
map_control_0e9926:
    .byte $E8 ; backreference distance high bits
    .byte $B0 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
