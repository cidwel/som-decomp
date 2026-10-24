.setcpu "65816"
.segment "CODE"
.org $2288
map_control_0d2288:
    .byte $E4 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
