.setcpu "65816"
.segment "CODE"
.org $EAB0
map_control_0eeab0:
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
