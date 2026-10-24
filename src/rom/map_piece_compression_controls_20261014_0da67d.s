.setcpu "65816"
.segment "CODE"
.org $A67D
map_control_0da67d:
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
