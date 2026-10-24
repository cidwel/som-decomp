.setcpu "65816"
.segment "CODE"
.org $A0C7
map_control_0da0c7:
    .byte $C7 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
