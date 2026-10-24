.setcpu "65816"
.segment "CODE"
.org $D068
map_control_0fd068:
    .byte $C4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
