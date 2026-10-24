.setcpu "65816"
.segment "CODE"
.org $B1CA
map_control_0fb1ca:
    .byte $EB ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
