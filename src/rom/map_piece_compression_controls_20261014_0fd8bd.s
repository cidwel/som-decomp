.setcpu "65816"
.segment "CODE"
.org $D8BD
map_control_0fd8bd:
    .byte $C7 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
