.setcpu "65816"
.segment "CODE"
.org $27E1
map_control_0e27e1:
    .byte $C4 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $D5 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
