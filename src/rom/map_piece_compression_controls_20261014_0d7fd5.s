.setcpu "65816"
.segment "CODE"
.org $7FD5
map_control_0d7fd5:
    .byte $C4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
