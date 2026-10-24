.setcpu "65816"
.segment "CODE"
.org $7E61
map_control_0e7e61:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
