.setcpu "65816"
.segment "CODE"
.org $E18F
map_control_0de18f:
    .byte $C2 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
