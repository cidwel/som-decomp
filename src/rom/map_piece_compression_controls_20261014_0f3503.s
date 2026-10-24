.setcpu "65816"
.segment "CODE"
.org $3503
map_control_0f3503:
    .byte $E7 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
