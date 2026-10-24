.setcpu "65816"
.segment "CODE"
.org $712F
map_control_0e712f:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
