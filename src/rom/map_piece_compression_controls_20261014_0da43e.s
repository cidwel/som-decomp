.setcpu "65816"
.segment "CODE"
.org $A43E
map_control_0da43e:
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
