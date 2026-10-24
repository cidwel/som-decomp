.setcpu "65816"
.segment "CODE"
.org $CFD9
map_control_0fcfd9:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
