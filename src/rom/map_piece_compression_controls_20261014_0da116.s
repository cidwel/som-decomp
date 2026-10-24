.setcpu "65816"
.segment "CODE"
.org $A116
map_control_0da116:
    .byte $C7 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
