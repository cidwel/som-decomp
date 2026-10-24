.setcpu "65816"
.segment "CODE"
.org $79E7
map_control_0e79e7:
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
