.setcpu "65816"
.segment "CODE"
.org $29CA
map_control_0e29ca:
    .byte $C2 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $03 ; distance low bit/count
