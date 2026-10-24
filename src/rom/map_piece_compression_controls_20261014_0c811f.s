.setcpu "65816"
.segment "CODE"
.org $811F
map_control_0c811f:
    .byte $F1 ; progressive-copy count
    .byte $DA ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $8F ; distance low bit/count
