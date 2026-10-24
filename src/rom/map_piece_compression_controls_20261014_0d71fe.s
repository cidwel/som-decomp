.setcpu "65816"
.segment "CODE"
.org $71FE
map_control_0d71fe:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
