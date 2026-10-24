.setcpu "65816"
.segment "CODE"
.org $BF46
map_control_0dbf46:
    .byte $E2 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
