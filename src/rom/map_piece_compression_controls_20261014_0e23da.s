.setcpu "65816"
.segment "CODE"
.org $23DA
map_control_0e23da:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
