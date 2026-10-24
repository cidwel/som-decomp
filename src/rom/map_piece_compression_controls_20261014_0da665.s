.setcpu "65816"
.segment "CODE"
.org $A665
map_control_0da665:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
