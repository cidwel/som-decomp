.setcpu "65816"
.segment "CODE"
.org $A583
map_control_0ea583:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
