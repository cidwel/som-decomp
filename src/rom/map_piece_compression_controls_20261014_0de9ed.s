.setcpu "65816"
.segment "CODE"
.org $E9ED
map_control_0de9ed:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $DA ; same-value copy count/distance
