.setcpu "65816"
.segment "CODE"
.org $A6AE
map_control_0ea6ae:
    .byte $C5 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
