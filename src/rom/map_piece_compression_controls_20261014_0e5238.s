.setcpu "65816"
.segment "CODE"
.org $5238
map_control_0e5238:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
