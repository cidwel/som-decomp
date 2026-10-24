.setcpu "65816"
.segment "CODE"
.org $3C7A
map_control_0f3c7a:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
