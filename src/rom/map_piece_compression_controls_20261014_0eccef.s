.setcpu "65816"
.segment "CODE"
.org $CCEF
map_control_0eccef:
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
