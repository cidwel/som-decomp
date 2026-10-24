.setcpu "65816"
.segment "CODE"
.org $A3AA
map_control_0ea3aa:
    .byte $E6 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
