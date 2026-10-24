.setcpu "65816"
.segment "CODE"
.org $A0C7
map_control_0ea0c7:
    .byte $D2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
