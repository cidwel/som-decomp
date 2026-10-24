.setcpu "65816"
.segment "CODE"
.org $D4DD
map_control_0fd4dd:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
