.setcpu "65816"
.segment "CODE"
.org $A3FA
map_control_0ea3fa:
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
