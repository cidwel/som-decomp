.setcpu "65816"
.segment "CODE"
.org $8990
map_control_0e8990:
    .byte $EA ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
