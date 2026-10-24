.setcpu "65816"
.segment "CODE"
.org $67FD
map_control_0d67fd:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
