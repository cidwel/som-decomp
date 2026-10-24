.setcpu "65816"
.segment "CODE"
.org $7807
map_control_0e7807:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
