.setcpu "65816"
.segment "CODE"
.org $8E33
map_control_0d8e33:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
