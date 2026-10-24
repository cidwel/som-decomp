.setcpu "65816"
.segment "CODE"
.org $CC1B
map_control_0ecc1b:
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
