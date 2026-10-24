.setcpu "65816"
.segment "CODE"
.org $E24F
map_control_0de24f:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
