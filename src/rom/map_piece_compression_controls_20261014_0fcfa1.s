.setcpu "65816"
.segment "CODE"
.org $CFA1
map_control_0fcfa1:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
