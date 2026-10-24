.setcpu "65816"
.segment "CODE"
.org $8395
map_control_0c8395:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
