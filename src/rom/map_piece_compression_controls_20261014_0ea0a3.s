.setcpu "65816"
.segment "CODE"
.org $A0A3
map_control_0ea0a3:
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
