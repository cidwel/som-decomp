.setcpu "65816"
.segment "CODE"
.org $A7A8
map_control_0fa7a8:
    .byte $E7 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
