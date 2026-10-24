.setcpu "65816"
.segment "CODE"
.org $71C3
map_control_0d71c3:
    .byte $E2 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
