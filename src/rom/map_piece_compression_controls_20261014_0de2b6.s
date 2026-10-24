.setcpu "65816"
.segment "CODE"
.org $E2B6
map_control_0de2b6:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
