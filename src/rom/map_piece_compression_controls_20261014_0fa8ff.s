.setcpu "65816"
.segment "CODE"
.org $A8FF
map_control_0fa8ff:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
