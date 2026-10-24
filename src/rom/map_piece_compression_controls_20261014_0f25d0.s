.setcpu "65816"
.segment "CODE"
.org $25D0
map_control_0f25d0:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
