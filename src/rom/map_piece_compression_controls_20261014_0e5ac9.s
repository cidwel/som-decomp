.setcpu "65816"
.segment "CODE"
.org $5AC9
map_control_0e5ac9:
    .byte $C1 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
