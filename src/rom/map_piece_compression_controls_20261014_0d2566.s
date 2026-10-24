.setcpu "65816"
.segment "CODE"
.org $2566
map_control_0d2566:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
