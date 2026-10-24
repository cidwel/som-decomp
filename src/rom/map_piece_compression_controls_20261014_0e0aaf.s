.setcpu "65816"
.segment "CODE"
.org $0AAF
map_control_0e0aaf:
    .byte $F4 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
