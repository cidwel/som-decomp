.setcpu "65816"
.segment "CODE"
.org $2A12
map_control_0f2a12:
    .byte $E2 ; previous-row copy count
    .byte $C9 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
