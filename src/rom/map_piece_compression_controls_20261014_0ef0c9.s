.setcpu "65816"
.segment "CODE"
.org $F0C9
map_control_0ef0c9:
    .byte $C1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
