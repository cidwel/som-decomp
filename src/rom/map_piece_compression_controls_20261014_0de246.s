.setcpu "65816"
.segment "CODE"
.org $E246
map_control_0de246:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
